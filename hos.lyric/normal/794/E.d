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
  /*
  debug {
    enum lim = 10;
    auto dp = new int[][][](lim, 2);
    dp[1] = [[0, 1], [0, 1]];
    foreach (n; 2 .. lim) {
      foreach (t; 0 .. 2) {
        dp[n][t] = new int[1 << n];
        foreach (p; 0 .. 1 << n) {
          dp[n][t][p] = t ^ 1;
          if (dp[n - 1][t ^ 1][p >> 1] == t) {
            dp[n][t][p] = t;
          }
          if (dp[n - 1][t ^ 1][p & ~(1 << (n - 1))] == t) {
            dp[n][t][p] = t;
          }
        }
      }
    }
    foreach (n; 1 .. lim) {
      foreach (t; 0 .. 2) {
        foreach (p; 0 .. 1 << n) {
          write(n, " ", t, " ");
          foreach (i; 0 .. n) {
            write((p >> i) & 1);
          }
          writeln(": ", dp[n][t][p]);
          if (t == 1) {
            int win;
            if (n == 1) {
              win = ((p >> 0) & 1);
            } else if (n % 2 == 0) {
              win |= ((p >> (n / 2 - 1)) & 1);
              win |= ((p >> (n / 2)) & 1);
            } else {
              win |= ((p >> (n / 2 - 1)) & 1) & ((p >> (n / 2)) & 1);
              win |= ((p >> (n / 2)) & 1) & ((p >> (n / 2 + 1)) & 1);
            }
            // assert(dp[n][t][p] == win);
          }
        }
      }
    }
  }
  //*/
  
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      auto ans = new int[N];
      // even: 01, 10, 11
      foreach (i; 0 .. N - 1) {
        const a = max(A[i], A[i + 1]);
        const k = abs((i - 0) - (N - (i + 2)));
        chmax(ans[k], a);
      }
      // odd: 011, 110, 111
      foreach (i; 0 .. N - 2) {
        const a = max(min(A[i], A[i + 1]), min(A[i + 1], A[i + 2]));
        const k = abs((i - 0) - (N - (i + 3)));
        chmax(ans[k], a);
      }
      
      foreach (k; 2 .. N) {
        chmax(ans[k], ans[k - 2]);
      }
      ans[N - 1] = A.maxElement;
      
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(ans[i]);
      }
      writeln;
    }
  } catch (EOFException e) {
  }
}