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


int N, K;
debug {
  int[] A;
}

bool Ask(int x, int y) {
  bool ret;
  debug {
    int xm = N, ym = N;
    foreach (a; A) {
      chmin(xm, abs(x - a));
      chmin(ym, abs(y - a));
    }
    ret = (xm <= ym);
    writefln("Ask %s %s = %s", x, y, ret);
  } else {
    writefln("1 %s %s", x, y);
    stdout.flush;
    const res = readToken();
    ret = (res == "TAK");
  }
  return ret;
}

void Answer(int x, int y) {
  writefln("2 %s %s", x, y);
  stdout.flush;
  debug {
    assert(A.count(x) > 0);
    assert(A.count(y) > 0);
  }
}

void main() {
  N = readInt();
  K = readInt();
  debug {
    A = new int[K];
    foreach (i; 0 .. K) {
      A[i] = readInt();
    }
  }
  
  int solve(int lo, int hi, int ini = 0) {
    for (; lo + 1 < hi; ) {
      int mid = (lo + hi) / 2;
      if (ini == 1) {
        mid = (lo + lo + hi) / 3;
        ini = 0;
      }
      if (ini == 2) {
        mid = (lo + hi + hi) / 3;
        ini = 0;
      }
      if (Ask(mid, mid + 1)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return Ask(lo, hi) ? lo : hi;
  }
  
  int ans0, ans1;
  
  ans0 = solve(1, N);
  if (1 <= ans0 - 1) {
    const res = solve(1, ans0 - 1, 1);
    if (Ask(res, ans0)) {
      ans1 = res;
    }
  }
  if (!ans1) {
    ans1 = solve(ans0 + 1, N, 2);
  }
  
  Answer(ans0, ans1);
}