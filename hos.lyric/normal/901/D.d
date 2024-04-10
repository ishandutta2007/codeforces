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


int N, M;
long[] C;
int[] A, B;

int[][] G;
int[] par, pari;
int[] dep;
long[] ans;
int odI, odU, odV;

long dfs(int u, int p, int pi) {
  par[u] = p;
  pari[u] = pi;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  long ret = C[u];
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      if (dep[v] == -1) {
        ans[i] = dfs(v, u, i);
        ret -= ans[i];
      } else if (dep[u] > dep[v]) {
        if ((dep[u] - dep[v]) % 2 == 0) {
          odI = i;
          odU = u;
          odV = v;
        }
      }
    }
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      C = new long[N];
      foreach (u; 0 .. N) {
        C[u] = readLong();
      }
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      par = new int[N];
      pari = new int[N];
      dep = new int[N];
      dep[] = -1;
      ans = new long[M];
      odI = odU = odV = -1;
      const rt = 0;
      const res = dfs(rt, -1, -1);
      debug {
        writeln("ans = ", ans);
        writefln("od = %s: %s %s", odI, odU, odV);
        writeln("res = ", res);
      }
      if (res != 0) {
        if (odI != -1 && res % 2 == 0) {
          long d = (-1)^^(dep[odV] % 2) * (res / 2);
          ans[odI] += d;
          for (int w = odU; w != odV; w = par[w]) {
            d *= -1;
            ans[pari[w]] += d;
          }
          d *= 2;
          for (int w = odV; w != rt; w = par[w]) {
            d *= -1;
            ans[pari[w]] += d;
          }
        } else {
          ans = null;
        }
      }
      
      if (!ans.empty) {
        auto cs = new long[N];
        foreach (i; 0 .. M) {
          cs[A[i]] += ans[i];
          cs[B[i]] += ans[i];
        }
        if (C != cs) {
          ans = null;
        }
      }
      
      if (!ans.empty) {
        writeln("YES");
        foreach (i; 0 .. M) {
          writeln(ans[i]);
        }
      } else {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}