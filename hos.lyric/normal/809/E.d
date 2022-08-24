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


struct ModInt(int M_) {
  import std.conv : to;
  alias M = M_;
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
    else static if (op == "/") { this *= a.inv(); }
    else static assert(false);
    return this;
  }
  ref ModInt opOpAssign(string op)(long a) {
    static if (op == "^^") {
      if (a < 0) return (this = inv()^^(-a));
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e > 0; e >>= 1) {
        if (e & 1) te *= t2;
        t2 *= t2;
      }
      x = cast(int)(te.x);
      return this;
    } else return mixin("this " ~ op ~ "= ModInt(a)");
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  ModInt opUnary(string op: "-")() const { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const {
    return mixin("ModInt(this) " ~ op ~ "= a");
  }
  ModInt opBinaryRight(string op)(long a) const {
    return mixin("ModInt(a) " ~ op ~ "= this");
  }
  bool opCast(T: bool)() const { return (x != 0); }
  string toString() const { return x.to!string; }
}

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


int N;
int[] A, B;

int[] lpf, phi;
Mint[] inv, weights;

int[][] G;
int[] par, dep;
int[] seq, poss;
int zeit;
int[] dis, fin;

void dfs(int u, int p) {
  par[u] = p;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  poss[u] = cast(int)(seq.length);
  seq ~= u;
  dis[u] = zeit++;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      seq ~= u;
    }
  }
  fin[u] = zeit++;
}

int shallower(int u, int v) {
  return (dep[u] <= dep[v]) ? u : v;
}

int[][] mn;

int lca(int u, int v) {
  int a = poss[u], b = poss[v];
  if (a > b) {
    swap(a, b);
  }
  const e = bsr(b - a + 1);
  const l = shallower(mn[e][a], mn[e][b - (1 << e) + 1]);
  debug {
    // writeln("lca ", u, " ", v, " = ", l);
  }
  return l;
}

void main() {
  
  try {
    for (; ; ) {
      N = readInt();
      auto perm = new int[N + 1];
      foreach (i; 1 .. N + 1) {
        perm[i] = readInt();
      }
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = perm[readInt()];
        B[i] = perm[readInt()];
      }
      debug {
        writeln("A = ", A);
        writeln("B = ", B);
      }
      
      lpf = iota(N + 1).array;
      phi = iota(N + 1).array;
      foreach (p; 2 .. N + 1) {
        if (lpf[p] == p) {
          for (int n = p; n <= N; n += p) {
            chmin(lpf[n], p);
            phi[n] = phi[n] / p * (p - 1);
          }
        }
      }
      inv = new Mint[N + 1];
      inv[1] = 1;
      foreach (n; 2 .. N + 1) {
        inv[n] = -(MO / n) * inv[cast(int)(MO % n)];
      }
      weights = new Mint[N + 1];
      weights[1] = 1;
      foreach (n; 2 .. N + 1) {
        const p = lpf[n];
        weights[n] = (n / p % p == 0) ? Mint(0) : (inv[p - 1] * weights[n / p]);
      }
      
      G = new int[][N + 1];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      par = new int[N + 1];
      dep = new int[N + 1];
      seq = [];
      poss = new int[N + 1];
      zeit = 0;
      dis = new int[N + 1];
      fin = new int[N + 1];
      dfs(1, -1);
      debug {
        writeln("par = ", par);
        writeln("dep = ", dep);
        writeln("seq = ", seq);
        writeln("poss = ", poss);
        writeln("dis = ", dis);
        writeln("fin = ", fin);
      }
      
      const seqLen = cast(int)(seq.length);
      const E = bsr(seqLen) + 1;
      mn = new int[][](E, seqLen);
      mn[0][] = seq[];
      foreach (e; 0 .. E - 1) {
        mn[e + 1][] = mn[e][];
        foreach (x; 0 .. seqLen - (1 << e)) {
          mn[e + 1][x] = shallower(mn[e][x], mn[e][x + (1 << e)]);
        }
      }
      debug {
        writeln("mn = ", mn);
        foreach (u; 1 .. N + 1) foreach (v; 1 .. N + 1) {
          lca(u, v);
        }
      }
      
      Mint ans;
      
      foreach (k; 1 .. N / 2 + 1) {
        if (weights[k]) {
          debug {
            writefln("**** k = %s ****", k);
          }
          int n = N / k;
          auto us = new int[n];
          foreach (x; 0 .. n) {
            us[x] = k * (1 + x);
          }
          us.sort!((u, v) => (dis[u] < dis[v]));
          debug {
            writeln("us = ", us);
          }
          us.length += n - 1;
          foreach (x; 0 .. n - 1) {
            us[n + x] = lca(us[x], us[x + 1]);
          }
          us.sort!((u, v) => (dis[u] < dis[v]));
          us = us.uniq.array;
          n = cast(int)(us.length);
          debug {
            writeln("us = ", us);
          }
          auto pp = new int[n];
          pp[0] = -1;
          int stackLen;
          auto stack = new int[n];
          stack[stackLen++] = 0;
          foreach (x; 1 .. n) {
            for (; fin[us[stack[stackLen - 1]]] < dis[us[x]]; --stackLen) {}
            pp[x] = stack[stackLen - 1];
            stack[stackLen++] = x;
          }
          debug {
            writeln("pp = ", pp);
          }
          auto graph = new int[][n];
          foreach (x; 1 .. n) {
            graph[pp[x]] ~= x;
          }
          Mint tot;
          foreach (x; 0 .. n) {
            if (us[x] % k == 0) {
              tot += phi[us[x]];
            }
          }
          Mint score;
          Mint dfs(int x) {
            Mint sum;
            foreach (y; graph[x]) {
              const res = dfs(y);
              score += (tot - res) * res * abs(dep[us[x]] - dep[us[y]]);
              sum += res;
            }
            if (us[x] % k == 0) {
              sum += phi[us[x]];
            }
            return sum;
          }
          dfs(0);
          debug {
            writeln("score = ", score);
          }
          ans += weights[k] * score;
        }
      }
      
      ans /= 1L * N * (N - 1) / 2;
      writeln(ans);
      
      debug {
        long brtPhi(long n) {
          long ret = n;
          for (long p = 2; p^^2 <= n; ++p) {
            if (n % p == 0) {
              do {
                n /= p;
              } while (n % p == 0);
              ret = ret / p * (p - 1);
            }
          }
          if (n > 1) {
            ret = ret / n * (n - 1);
          }
          return ret;
        }
        auto d = new int[][](N + 1, N + 1);
        foreach (u; 1 .. N + 1) {
          d[u][] = N;
          d[u][u] = 0;
        }
        foreach (i; 0 .. N - 1) {
          d[A[i]][B[i]] = d[B[i]][A[i]] = 1;
        }
        foreach (w; 1 .. N + 1) foreach (u; 1 .. N + 1) foreach (v; 1 .. N + 1) {
          chmin(d[u][v], d[u][w] + d[w][v]);
        }
        Mint brt;
        foreach (u; 1 .. N + 1) foreach (v; u + 1 .. N + 1) {
          brt += brtPhi(1L * u * v) * d[u][v];
        }
        writefln("brt = %s / NC2 = %s", brt, brt / (1L * N * (N - 1) / 2));
        
        Mint slw;
        foreach (k; 1 .. N + 1) {
          Mint sum;
          for (int u = k; u <= N; u += k) for (int v = u + k; v <= N; v += k) {
            sum += phi[u] * phi[v] * d[u][v];
          }
          writeln(k, ": ", sum);
          slw += weights[k] * sum;
        }
        writefln("slw = %s / NC2 = %s", slw, slw / (1L * N * (N - 1) / 2));
      }
    }
  } catch (EOFException e) {
  }
}