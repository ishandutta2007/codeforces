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


enum E = 21;

void chmax2(int[] t, int[] f) {
  /*
  foreach (j; 0 .. 2) {
    int tmp = f[j];
    foreach (i; 0 .. 2) {
      if (t[i] < tmp) {
        swap(t[i], tmp);
      }
    }
  }
  */
  int tmp = f[0];
  if (t[0] < tmp) swap(t[0], tmp);
  if (t[1] < tmp) t[1] = tmp;
  if (t[1] < f[1]) t[1] = f[1];
}

int N;
int[] A;

int L;
int[] B;

int[] mx0, mx1;

bool check() {
  mx0[0 .. 1 << L] = -1;
  mx1[0 .. 1 << L] = -1;
  foreach (i; 0 .. N) {
    int tmp = i;
    if (mx0[B[i]] < tmp) swap(mx0[B[i]], tmp);
    if (mx1[B[i]] < tmp) mx1[B[i]] = tmp;
  }
  foreach (l; 0 .. L) {
    foreach (p; 0 .. 1 << L) {
      if (!((p & 1 << l))) {
        int tmp = mx0[p | 1 << l];
        if (mx0[p] < tmp) swap(mx0[p], tmp);
        if (mx1[p] < tmp) mx1[p] = tmp;
        if (mx1[p] < mx1[p | 1 << l]) mx1[p] = mx1[p | 1 << l];
      }
    }
  }
  foreach (i; 0 .. N) {
    if (i < mx1[((1 << L) - 1) & ~B[i]]) {
      return true;
    }
  }
  return false;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      int ans;
      L = 0;
      B = new int[N];
      mx0 = new int[1 << E];
      mx1 = new int[1 << E];
      foreach_reverse (e; 0 .. E) {
        foreach (i; 0 .. N) {
          if ((A[i] >> e) & 1) {
            B[i] |= 1 << L;
          }
        }
        ++L;
        if (check()) {
          ans |= 1 << e;
        } else {
          --L;
          B[] &= ((1 << L) - 1);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}