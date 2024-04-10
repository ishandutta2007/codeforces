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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const S = readToken();
      const X = readLong();
      const Y = readLong();
      const N = cast(int)(S.length);
      
      auto nums = new int[2][N + 1];
      foreach (i; 0 .. N) {
        foreach (t; 0 .. 2) {
          nums[i + 1][t] = nums[i][t] + ((S[i] - '0' == t) ? 1 : 0);
        }
      }
      long[2][] css;
      foreach (i; 0 .. N) {
        if (S[i] == '?') {
          long[2] cs;
          cs[0] += Y * (nums[i][1]);
          cs[0] += X * (nums[N][1] - nums[i + 1][1]);
          cs[1] += X * (nums[i][0]);
          cs[1] += Y * (nums[N][0] - nums[i + 1][0]);
          css ~= cs;
        }
      }
      debug {
        writeln("css = ", css);
      }
      const cssLen = cast(int)(css.length);
      auto cssSum = new long[2][cssLen + 1];
      foreach (j; 0 .. cssLen) {
        foreach (t; 0 .. 2) {
          cssSum[j + 1][t] = cssSum[j][t] + css[j][t];
        }
      }
      long ans = INF;
      foreach (j; 0 .. cssLen + 1) {
        long cost;
        cost += cssSum[j][0];
        cost += (cssSum[cssLen][1] - cssSum[j][1]);
        cost += X * j * (cssLen - j);
        chmin(ans, cost);
      }
      foreach (j; 0 .. cssLen + 1) {
        long cost;
        cost += cssSum[j][1];
        cost += (cssSum[cssLen][0] - cssSum[j][0]);
        cost += Y * j * (cssLen - j);
        chmin(ans, cost);
      }
      
      foreach (i; 0 .. N) {
        if (S[i] == '0') ans += Y * nums[i][1];
        if (S[i] == '1') ans += X * nums[i][0];
      }
      
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}