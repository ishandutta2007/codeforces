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


alias Value = int;
int root(int[] ps, Value[] qs, int u) {
  if (ps[u] < 0) {
    return u;
  } else {
    int r = root(ps, qs, ps[u]);
    // qs[u] += qs[ps[u]];
    qs[u] ^= qs[ps[u]];
    return (ps[u] = r);
  }
}
bool connect(int[] ps, Value[] qs, int u, int v, Value c) {
  int ru = root(ps, qs, u);
  int rv = root(ps, qs, v);
  // Value cc = c + qs[u] - qs[v];
  Value cc = c ^ qs[u] ^ qs[v];
  if (ru == rv) return (cc == 0);
  // if (ps[ru] > ps[rv]) { swap(ru, rv); cc *= -1; }
  if (ps[ru] > ps[rv]) { swap(ru, rv); }
  ps[ru] += ps[rv]; ps[rv] = ru; qs[rv] = cc;
  return true;
}


int N, M;
int[] A, B, C;
int[] U, V, P;

int[][] G;
int[] ds;

void dfs(int u, int p, int d) {
  ds[u] = d;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      const c = (~C[i]) ? (popcnt(C[i]) & 1) : 0;
      dfs(v, u, d ^ c);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        M = readInt;
        A = new int[N - 1];
        B = new int[N - 1];
        C = new int[N - 1];
        foreach (i; 0 .. N - 1) {
          A[i] = readInt - 1;
          B[i] = readInt - 1;
          C[i] = readInt;
        }
        U = new int[M];
        V = new int[M];
        P = new int[M];
        foreach (m; 0 .. M) {
          U[m] = readInt - 1;
          V[m] = readInt - 1;
          P[m] = readInt;
        }
        
        G = new int[][N];
        foreach (i; 0 .. N - 1) {
          G[A[i]] ~= i;
          G[B[i]] ~= i;
        }
        ds = new int[N];
        dfs(0, -1, 0);
        debug {
          writeln("ds = ", ds);
        }
        
        auto ps = new int[N];
        ps[] = -1;
        auto qs = new int[N];
        foreach (i; 0 .. N - 1) {
          if (~C[i]) {
            if (!connect(ps, qs, A[i], B[i], popcnt(C[i]) & 1)) {
              assert(false);
            }
          }
        }
        bool ok = true;
        foreach (m; 0 .. M) {
          if (!connect(ps, qs, U[m], V[m], P[m])) {
            ok = false;
          }
        }
        if (ok) {
          foreach (u; 0 .. N) {
            root(ps, qs, u);
          }
          writeln("YES");
          foreach (i; 0 .. N - 1) {
            int c = C[i];
            if (!~c) {
              c = qs[A[i]] ^ qs[B[i]];
            }
            writeln(A[i] + 1, " ", B[i] + 1, " ", c);
          }
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}