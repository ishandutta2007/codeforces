import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


int N, M;
int[] A, B;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      auto cnt = new int[N];
      auto mn = new int[N];
      mn[] = N;
      foreach (i; 0 .. M) {
        ++cnt[A[i]];
        chmin(mn[A[i]], (B[i] - A[i] + N) % N);
      }
      
      foreach (x; 0 .. N) {
        int ans;
        foreach (y; 0 .. N) {
          if (cnt[y] > 0) {
            chmax(ans, (y - x + N) % N + (cnt[y] - 1) * N + mn[y]);
          }
        }
        if (x > 0) {
          write(" ");
        }
        write(ans);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}