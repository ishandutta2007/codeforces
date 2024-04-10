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




void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new string[N];
        foreach (x; 0 .. N) {
          A[x] = readToken();
        }
        
        auto cnt = new int[][](3, 2);
        foreach (x; 0 .. N) foreach (y; 0 .. N) {
          if (A[x][y] == 'X') ++cnt[(x + y) % 3][0];
          if (A[x][y] == 'O') ++cnt[(x + y) % 3][1];
        }
        int total;
        foreach (i; 0 .. 3) foreach (j; 0 .. 2) {
          total += cnt[i][j];
        }
        
        auto ans = new char[][](N, N);
        foreach (x; 0 .. N) foreach (y; 0 .. N) {
          ans[x][y] = A[x][y];
        }
        foreach (i; 0 .. 3) {
          const j = (i + 1) % 3;
          if (cnt[i][0] + cnt[j][1] <= total / 3) {
            foreach (x; 0 .. N) foreach (y; 0 .. N) {
              if (A[x][y] == 'X' && (x + y) % 3 == i) ans[x][y] = 'O';
              if (A[x][y] == 'O' && (x + y) % 3 == j) ans[x][y] = 'X';
            }
            goto done;
          }
        }
        assert(false);
       done:
        foreach (x; 0 .. N) {
          writeln(ans[x]);
        }
      }
    }
  } catch (EOFException e) {
  }
}