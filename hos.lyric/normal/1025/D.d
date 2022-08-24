import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
      int N = readInt();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      N += 2;
      A = [0L] ~ A ~ [0L];
      auto b = new bool[][](N, N);
      foreach (i; 0 .. N) foreach (j; 0 .. N) {
        b[i][j] = (gcd(A[i], A[j]) != 1);
      }
      
      auto dpL = new bool[][](N, N);
      auto dpR = new bool[][](N, N);
      foreach (i; 0 .. N - 1) {
        dpL[i + 1][i] = true;
        dpR[i][i + 1] = true;
      }
      foreach (w; 2 .. N) {
        foreach (i; 0 .. N - w) {
          const j = i + w;
          foreach (k; i + 1 .. j) {
            if (dpR[i][k] && dpL[j][k]) {
              if (b[i][k]) dpL[j][i] = true;
              if (b[j][k]) dpR[i][j] = true;
            }
          }
        }
      }
      writeln(dpL[N - 1][0] ? "Yes" : "No");
    }
  } catch (EOFException e) {
  }
}