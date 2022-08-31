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

void bChmax(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bChmax: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    chmax(bit[x], val);
  }
}

// max of [0, pos)
T bMax(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bMax: 0 <= pos <= |bit| must hold");
}
do {
  T ret = -1;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    chmax(ret, bit[x]);
  }
  return ret;
}



void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto SA = new long[N];
      auto TA = new long[N];
      auto SB = new long[N];
      auto TB = new long[N];
      foreach (i; 0 .. N) {
        SA[i] = readLong();
        TA[i] = readLong();
        SB[i] = readLong();
        TB[i] = readLong();
      }
      
      bool ans = true;
      foreach (phase; 0 .. 2) {
        auto xs = SA.dup ~ TA.dup ~ SB.dup ~ TB.dup;
        xs = xs.sort.uniq.array;
        const xsLen = cast(int)(xs.length);
        
        auto lecsSA = iota(N).array;
        auto lecsTA = iota(N).array;
        lecsSA.sort!((i, j) => (SA[i] < SA[j]));
        lecsTA.sort!((i, j) => (TA[i] < TA[j]));
        
        auto bit = new long[xsLen];
        bit[] = -1;
        int posI;
        foreach (j; lecsSA) {
          for (; posI < N && TA[lecsTA[posI]] < SA[j]; ++posI) {
            const i = lecsTA[posI];
            debug {
              writeln("add i = ", i);
            }
            const key = xs.lowerBound(SB[i]);
            bit.bChmax(key, TB[i]);
          }
          {
            debug {
              writeln("check j = ", j);
            }
            const key = xs.lowerBound(TB[j]);
            const res = bit.bMax(key + 1);
            if (res >= SB[j]) {
              debug {
                writefln("found j = %s, res = %s", j, res);
              }
              ans = false;
            }
          }
        }
        
        swap(SA, SB);
        swap(TA, TB);
      }
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}