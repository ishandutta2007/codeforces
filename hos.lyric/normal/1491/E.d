import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


int[] fib;

int N;
int[] A, B;

int[][] G;
bool[] del;
int[] sz, par, pari;
int[] us;

void dfs(int u, int p, int pi) {
  us ~= u;
  par[u] = p;
  pari[u] = pi;
  sz[u] = 1;
  foreach (i; G[u]) {
    if (!del[i]) {
      if (i != pi) {
        const v = A[i] ^ B[i] ^ u;
        dfs(v, u, i);
        sz[u] += sz[v];
      }
    }
  }
}

bool solve(int k, int rt) {
  debug {
    // writeln("solve ", k, " ", rt);
  }
  if (k <= 2) {
    return true;
  }
  us = [];
  dfs(rt, -1, -1);
  /*
  debug {
    writeln("solve ", k, " ", rt);
    writeln("  del = ", del);
    writeln("  us = ", us);
    writeln("  sz = ", sz);
    writeln("  par = ", par);
    writeln("  pari = ", pari);
  }
  //*/
  assert(sz[rt] == fib[k]);
  int[] vs, ps;
  foreach (u; us) {
    if (sz[u] == fib[k - 2] || fib[k] - sz[u] == fib[k - 2]) {
      vs ~= u;
      ps ~= par[u];
    }
  }
  foreach (v; vs) {
    del[pari[v]] = true;
  }
  if (vs.length == 0) {
    return false;
  } else if (vs.length == 1) {
    bool ret = true;
    if (sz[vs[0]] == fib[k - 2]) {
      ret = ret && solve(k - 2, vs[0]);
      ret = ret && solve(k - 1, ps[0]);
    } else {
      ret = ret && solve(k - 1, vs[0]);
      ret = ret && solve(k - 2, ps[0]);
    }
    return ret;
  } else if (vs.length == 2) {
    bool ret = true;
    if (sz[vs[0]] == fib[k - 2]) {
      if (sz[vs[1]] == fib[k - 2]) {
        ret = ret && solve(k - 2, vs[0]);
        ret = ret && solve(k - 2, vs[1]);
        ret = ret && solve(k - 3, ps[0]);
      } else {
        ret = ret && solve(k - 2, vs[0]);
        ret = ret && solve(k - 2, ps[1]);
        ret = ret && solve(k - 3, ps[0]);
      }
    } else {
      if (sz[vs[1]] == fib[k - 2]) {
        ret = ret && solve(k - 2, vs[1]);
        ret = ret && solve(k - 2, ps[0]);
        ret = ret && solve(k - 3, ps[1]);
      } else {
        assert(false);
      }
    }
    return ret;
  } else {
    assert(false);
  }
}

void main() {
  fib = new int[40];
  fib[0] = 1;
  fib[1] = 1;
  foreach (k; 2 .. fib.length) {
    fib[k] = fib[k - 1] + fib[k - 2];
  }
  debug {
    writeln("fib = ", fib);
  }
  
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      debug {
        writeln("N = ", N);
        writeln("A = ", A);
        writeln("B = ", B);
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      del = new bool[N - 1];
      sz = new int[N];
      par = new int[N];
      pari = new int[N];
      
      bool ans = false;
      const k = fib.lowerBound(N);
      if (fib[k] == N) {
        ans = solve(k, 0);
      }
      writeln(ans ? "YES" : "NO");
      
      debug {
        auto brt = new bool[1 << N];
        foreach (p; 1 .. 1 << N) {
          if (!(p & p - 1)) {
            brt[p] = true;
          } else {
            auto uf = new int[N];
            uf[] = -1;
            foreach (i; 0 .. N - 1) {
              if ((p & 1 << A[i]) && (p & 1 << B[i])) {
                uf.connect(A[i], B[i]);
              }
            }
            int numComps;
            foreach (u; 0 .. N) {
              if (p & 1 << u) {
                if (uf[u] < 0) {
                  ++numComps;
                }
              }
            }
            if (fib.count(popcnt(p)) > 0 && numComps == 1) {
              for (int q = p; --q &= p; ) {
                if (brt[q] && brt[p ^ q]) {
                  brt[p] = true;
                  break;
                }
              }
            }
          }
        }
        assert(brt[$ - 1] == ans, format("%s %s %s: %s %s", N, A, B, brt[$ - 1], ans));
      }
    }
  } catch (EOFException e) {
  }
}