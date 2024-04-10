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


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const M = readInt();
        const N = readInt();
        auto A = new string[M];
        foreach (x; 0 .. M) {
          A[x] = readToken();
        }
        
        auto ASums = new int[][](M, N + 1);
        foreach (x; 0 .. M) {
          foreach (y; 0 .. N) {
            ASums[x][y + 1] = ASums[x][y] + (A[x][y] - '0');
          }
        }
        
        int ans = INF;
        auto fs = new int[M + 1];
        foreach (y0; 0 .. N) foreach (y1; y0 + 3 .. N) {
          foreach (x; 0 .. M) {
            fs[x + 1] = fs[x];
            fs[x + 1] += 1 - (A[x][y0] - '0');
            fs[x + 1] += 1 - (A[x][y1] - '0');
            fs[x + 1] += (ASums[x][y1] - ASums[x][y0 + 1]);
          }
          int mn = INF;
          foreach (x; 0 .. M) {
            if (x >= 4) {
              int cost;
              cost += (y1 - y0 - 1) - (ASums[x - 4][y1] - ASums[x - 4][y0 + 1]);
              cost -= fs[x - 4 + 1];
              chmin(mn, cost);
            }
            {
              int cost = mn;
              cost += (y1 - y0 - 1) - (ASums[x][y1] - ASums[x][y0 + 1]);
              cost += fs[x];
              chmin(ans, cost);
            }
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}