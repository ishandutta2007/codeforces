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

/*
  \sum d_i = n (n - 1) / 2
  30 >= (\sum d_i) / n = (n - 1) / 2
*/

enum LIM_N = 70;
enum LIM_S = LIM_N * LIM_N / 2 + 1;

void main() {
  try {
    for (; ; ) {
      const M = readInt();
      auto A = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt();
      }
      A.sort;
      
      auto dp = new bool[][][](M + 1, LIM_N, LIM_S);
      dp[0][0][0] = true;
      foreach (i; 0 .. M) {
        foreach (n; 0 .. LIM_N - 1) {
          foreach (s; 0 .. LIM_S - A[i]) {
            if (dp[i][n][s] || dp[i + 1][n][s]) {
              dp[i + 1][n + 1][s + A[i]] = true;
            }
          }
        }
        foreach (n; 0 .. LIM_N) {
          dp[i + 1][n][0 .. n * (n - 1) / 2] = false;
        }
      }
      
      foreach (N; 0 .. LIM_N) {
        if (dp[M][N][N * (N - 1) / 2]) {
          int[] deg;
          for (int i = M, n = N, s = N * (N - 1) / 2; i--; ) {
            do {
              deg ~= A[i];
              n -= 1;
              s -= A[i];
            } while (!dp[i][n][s]);
          }
          deg.reverse;
          debug {
            writeln("deg = ", deg);
          }
          auto ans = new bool[][](N, N);
          foreach (u; 0 .. N) {
            assert(0 <= deg[u] && deg[u] <= N - u - 1);
            alias Entry = Tuple!(int, int);
            Entry[] es;
            foreach (v; u + 1 .. N) {
              es ~= Entry(deg[v], v);
            }
            es.sort;
            foreach (j; 0 .. N - u - 1) {
              const v = es[j][1];
              if (j < deg[u]) {
                ans[u][v] = true;
              } else {
                ans[v][u] = true;
                --deg[v];
              }
            }
          }
          writeln(N);
          foreach (u; 0 .. N) {
            foreach (v; 0 .. N) {
              write(ans[u][v] ? 1 : 0);
            }
            writeln;
          }
          goto found;
        }
      }
      writeln("=(");
     found:
    }
  } catch (EOFException e) {
  }
}