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


enum E = 26;

void main() {
  /*
  debug {
    enum LIM = 8;
    auto dp = new bool[][LIM + 1];
    dp[1] = [true, false];
    foreach (n; 2 .. LIM + 1) {
      dp[n] = new bool[1 << n];
      foreach (m; 1 .. n) {
        foreach (p; 0 .. 1 << m) foreach (q; 0 .. 1 << (n - m)) {
          if (dp[m][p] && dp[n - m][q]) {
            dp[n][(((1 << m) - 1) ^ p) | (q << m)] = true;
          }
        }
      }
      foreach (p; 0 .. 1 << n) {
        if (dp[n][p]) {
          foreach (i; 0 .. n) {
            write((p >> i) & 1);
          }
          writeln;
        }
      }
      assert(dp[n].count(true) == 1 << (n - 2));
    }
  }
  //*/
  
  try {
    for (; ; ) {
      const N = readInt();
      const T = readLong();
      const S = readToken();
      
      auto freq = new long[E];
      foreach (i; 0 .. N - 2) {
        ++freq[S[i] - 'a'];
      }
      
      long tar = T;
      tar -= -(1L << (S[N - 2] - 'a'));
      tar -= +(1L << (S[N - 1] - 'a'));
      
      foreach (e; 0 .. E) {
        tar -= freq[e] * (1L << e);
      }
      long mn = tar, mx = tar;
      foreach (e; 0 .. E) {
        if (mn & 1) ++mn;
        if (mx & 1) --mx;
        if (mn > mx) {
          break;
        }
        mn /= 2;
        mx /= 2;
        mx += freq[e];
        debug {
          writeln(e, ": ", mn, " ", mx);
        }
      }
      writeln((mn <= 0 && 0 <= mx) ? "Yes" : "No");
    }
  } catch (EOFException e) {
  }
}