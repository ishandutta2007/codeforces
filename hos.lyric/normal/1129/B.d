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


int K;

int N;
int[] A;

int Alice() {
  int res = 0;
  int cur = 0;
  int k = -1;
  foreach (i; 0 .. N) {
    cur += A[i];
    if (cur < 0) {
      cur = 0;
      k = i;
    }
    chmax(res, (i - k) * cur);
  }
  return res;
}

int Bob() {
  int ret = 0;
  foreach (i; 0 .. N) {
    int sum;
    foreach (j; i .. N) {
      sum += A[j];
      chmax(ret, (j + 1 - i) * sum);
    }
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      K = readInt();
      foreach (b; 2 .. 10^^6 + 1) {
        const x0 = min(K / (b - 1), 2000);
        for (int x = x0; x < x0 + 10; ++x) {
          const y = x * (b - 1) - K;
          if (y >= 1 && x + y <= 2000) {
            N = x + y;
            A = new int[N];
            A[0 .. x - 1] = 0;
            A[x - 1] = -1;
            foreach (i; 0 .. y) {
              A[x + i] = b / y + ((i < b % y) ? 1 : 0);
            }
            goto found;
          }
        }
      }
     found:
      debug {
        writeln("Alice = ", Alice());
        writeln("Bob = ", Bob());
      }
      writeln(N);
      writeln(A.to!string.replaceAll(regex(`[\[\],]`), ""));
    }
  } catch (EOFException e) {
  }
}