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


// floor(a / b)
Int divFloor(Int)(Int a, Int b) {
  return a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);
}

// ceil(a / b)
Int divCeil(Int)(Int a, Int b) {
  return a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);
}


void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


enum M = 11;
enum A = 4;

int[] readDNA() {
  return readToken().map!((dchar c) {
    switch (c) {
      case 'A': return 0;
      case 'C': return 1;
      case 'G': return 2;
      case 'T': return 3;
      default: assert(false);
    }
  }).array;
}

void main() {
  try {
    for (; ; ) {
      const S = readDNA();
      const N = cast(int)(S.length);
      
      auto ss = S.dup;
      auto bits = new int[][][][M + 1];
      foreach (m; 1 .. M + 1) {
        bits[m] = new int[][][](m, A, (N + m - 1) / m);
        foreach (i; 0 .. N) {
          bits[m][i % m][ss[i]].bAdd(i / m, +1);
        }
      }
      
      const Q = readInt();
      foreach (q; 0 .. Q) {
        const typ = readInt();
        switch (typ) {
          case 1: {
            const X = readInt() - 1;
            const C = readDNA();
            foreach (m; 1 .. M + 1) {
              bits[m][X % m][ss[X]].bAdd(X / m, -1);
            }
            ss[X] = C[0];
            foreach (m; 1 .. M + 1) {
              bits[m][X % m][ss[X]].bAdd(X / m, +1);
            }
          } break;
          case 2: {
            const L = readInt() - 1;
            const R = readInt();
            const E = readDNA();
            const m = cast(int)(E.length);
            int ans;
            foreach (r; 0 .. m) {
              // L <= m y + r < R
              int j = (r - L) % m;
              if (j < 0) j += m;
              ans -= bits[m][r][E[j]].bSum(divCeil(L - r, m));
              ans += bits[m][r][E[j]].bSum(divCeil(R - r, m));
            }
            writeln(ans);
          } break;
          default: assert(false);
        }
      }
    }
  } catch (EOFException e) {
  }
}