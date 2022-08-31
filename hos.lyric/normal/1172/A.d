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
int[] A, B;

int[] pos;

int solveDirect() {
  // B[N - 1] at 2 N - 1
  const d = (2 * N - 1) - B[N - 1];
  bool ok = true;
  foreach (x; 1 .. B[N - 1] + 1) {
    ok = ok && (pos[x] == d + x);
  }
  foreach (x; B[N - 1] + 1 .. N + 1) {
    ok = ok && (pos[x] <= d + x - N - 1);
  }
  return ok ? (N - B[N - 1]) : -1;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      B = new int[N];
      foreach (i; 0 .. N) {
        B[i] = readInt();
      }
      
      pos = new int[N + 1];
      foreach (i; 0 .. N) {
        pos[A[i]] = i;
      }
      foreach (i; 0 .. N) {
        pos[B[i]] = N + i;
      }
      
      int ans = solveDirect();
      if (ans == -1) {
        int lo = -1, hi = 2 * N;
        for (; lo + 1 < hi; ) {
          const mid = (lo + hi) / 2;
          // 1 at 2 N + mid
          const d = (2 * N + mid) - 1;
          bool ok = true;
          foreach (x; 1 .. N + 1) {
            ok = ok && (pos[x] <= d + x - N - 1);
          }
          debug {
            writeln(mid, " ", d, " ", ok);
          }
          ok ? (hi = mid) : (lo = mid);
        }
        ans = hi + N;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}