import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


int N;
int[] P;
int[][] G;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      P = new int[N];
      P[0] = -1;
      foreach (u; 1 .. N) {
        P[u] = readInt();
      }
      
      G = new int[][N];
      foreach (u; 1 .. N) {
        G[P[u]] ~= u;
      }
      
      auto dpSum = new int[N];
      auto dpMin = new int[N];
      auto dpMax = new int[N];
      dpSum[] = 1;
      dpMin[] = N;
      dpMax[] = 0;
      void add(int u, int p) {
        dpSum[p] += dpSum[u];
        if (dpMin[u] >= N) {
          dpMin[u] = 0;
        }
        chmin(dpMin[p], 1 + dpMin[u]);
        chmax(dpMax[p], 1 + dpMax[u]);
      }
      
      foreach_reverse (u; 1 .. N) {
        add(u, P[u]);
      }
      debug {
        writeln("dpSum = ", dpSum);
        writeln("dpMin = ", dpMin);
        writeln("dpMax = ", dpMax);
      }
      
      int[] path, ops;
      for (int u = 0; ; ) {
        path ~= u;
        const len = cast(int)(G[u].length);
        if (len == 0) {
          break;
        }
        // 2043 10
        // G[u].sort!((v, w) => (dpSum[v] < dpSum[w]));
        // 5479
        // G[u].sort!((v, w) => (dpSum[v] > dpSum[w]));
        // 2044
        // G[u].sort!((v, w) => (dpMin[v] < dpMin[w]));
        // 3058
        // G[u].sort!((v, w) => (dpMin[v] > dpMin[w]));
        // 2043 7
        G[u].sort!((v, w) => (dpMax[v] < dpMax[w]));
        // 3078
        // G[u].sort!((v, w) => (dpMax[v] > dpMax[w]));
        foreach_reverse (j; 1 .. len) {
          ops ~= G[u][j];
          G[G[u][j - 1]] ~= G[u][j];
          add(G[u][j], G[u][j - 1]);
        }
        u = G[u][0];
      }
      debug {
        writeln("path = ", path);
        writeln("ops = ", ops);
        assert(path.length == N);
        auto p = new int[N];
        p[path[0]] = -1;
        foreach (i; 1 .. N) {
          p[path[i]] = path[i - 1];
        }
        foreach_reverse (u; ops) {
          p[u] = p[p[u]];
        }
        assert(p == P);
      }
      
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(path[i]);
      }
      writeln();
      writeln(ops.length);
      int ou;
      foreach_reverse (u; ops) {
        if (ou++) write(" ");
        write(u);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}