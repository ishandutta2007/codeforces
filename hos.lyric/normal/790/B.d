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


int N, K;
int[] A, B;

int[][] G;
long ans;

void solveCentroidDecomp() {
  auto sz = new int[N];
  auto del = new bool[N];
  void dfsSz(int u, int p) {
    sz[u] = 1;
    foreach (i; G[u]) {
      const v = A[i] ^ B[i] ^ u;
      if (v != p) {
        dfsSz(v, u);
        sz[u] += sz[v];
      }
    }
  }
  dfsSz(0, -1);

  // r: centroid
  void solveSubtree(int r) {
    debug {
      string dfsDebug(int u, int p) {
        string ret = u.to!string;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (!del[v] && v != p) {
            ret ~= "(" ~ dfsDebug(v, u) ~ ")";
          }
        }
        return ret;
      }
      writeln("solveSubtree ", dfsDebug(r, -1));
    }
    
    int[] vs;
    foreach (i; G[r]) {
      const v = A[i] ^ B[i] ^ r;
      if (!del[v]) {
        vs ~= v;
      }
    }
    
    const len = cast(int)(vs.length);
    auto fs0 = new long[K];
    auto fs1 = new long[K];
    auto gs0 = new long[][](len, K);
    auto gs1 = new long[][](len, K);
    
    void dfs(int j, int u, int p, int d) {
      fs0[d % K] += 1;
      fs1[d % K] += d;
      gs0[j][d % K] += 1;
      gs1[j][d % K] += d;
      foreach (i; G[u]) {
        const v = A[i] ^ B[i] ^ u;
        if (!del[v] && v != p) {
          dfs(j, v, u, d + 1);
        }
      }
    }
    fs0[0] += 1;
    fs1[0] += 0;
    foreach (j; 0 .. len) {
      dfs(j, vs[j], r, 1);
    }
    
    debug {
      writeln("fs0 = ", fs0);
      writeln("gs1 = ", fs1);
      writeln("fs0 = ", gs0);
      writeln("gs1 = ", gs1);
    }
    foreach (x; 0 .. K) foreach (y; 0 .. K) {
      const z = (K - (x + y) % K) % K;
      ans += fs1[x] * fs0[y];
      ans += fs0[x] * fs1[y];
      ans += fs0[x] * fs0[y] * z;
      foreach (j; 0 .. len) {
        ans -= gs1[j][x] * gs0[j][y];
        ans -= gs0[j][x] * gs1[j][y];
        ans -= gs0[j][x] * gs0[j][y] * z;
      }
    }
  }

  void solveRec(int u) {
    for (; ; ) {
      int vm = -1;
      foreach (i; G[u]) {
        const v = A[i] ^ B[i] ^ u;
        if (!del[v]) {
          if (vm == -1 || sz[vm] < sz[v]) {
            vm = v;
          }
        }
      }
      if (vm == -1 || sz[u] >= 2 * sz[vm]) {
        solveSubtree(u);
        del[u] = true;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (!del[v]) {
            solveRec(v);
          }
        }
        break;
      } else {
        sz[u] -= sz[vm];
        sz[vm] += sz[u];
        u = vm;
      }
    }
  }
  solveRec(0);
}


void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      
      ans = 0;
      solveCentroidDecomp;
      ans /= K;
      ans /= 2;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}