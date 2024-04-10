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


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new int[N];
      foreach (i; 0 .. N) {
        P[i] = readInt() - 1;
      }
      
      auto Q = new int[N];
      foreach (i; 0 .. N) {
        Q[P[i]] = i;
      }
      
      auto ans = new long[N];
      
      // move
      int cntL, cntR;
      long sumL, sumR;
      auto setL = new RedBlackTree!int;
      auto setR = new RedBlackTree!int;
      foreach (j; 0 .. N) {
        if (setR.empty || Q[j] < setR.front) {
          cntL += 1;
          sumL += Q[j];
          setL.insert(Q[j]);
        } else {
          cntR += 1;
          sumR += Q[j];
          setR.insert(Q[j]);
        }
        for (; cntL > (j + 1) / 2; ) {
          const i = setL.back;
          cntL -= 1;
          sumL -= i;
          setL.removeKey(i);
          cntR += 1;
          sumR += i;
          setR.insert(i);
        }
        for (; cntL < (j + 1) / 2; ) {
          const i = setR.front;
          cntR -= 1;
          sumR -= i;
          setR.removeKey(i);
          cntL += 1;
          sumL += i;
          setL.insert(i);
        }
        debug {
          writeln("j = ", j);
          writeln("  L: ", cntL, " ", sumL, " ", setL);
          writeln("  R: ", cntR, " ", sumR, " ", setR);
        }
        const long i0 = setR.front;
        debug {
          writeln("  cost L: ", i0 * (i0 - 1) / 2 - (i0 - cntL) * (i0 - cntL - 1) / 2, " - ", sumL);
          writeln("  cost R: ", sumR, " - ", (i0 + cntR) * (i0 + cntR - 1) / 2 - i0 * (i0 - 1) / 2);
        }
        ans[j] += i0 * (i0 - 1) / 2 - (i0 - cntL) * (i0 - cntL - 1) / 2;
        ans[j] -= sumL;
        ans[j] += sumR;
        ans[j] -= (i0 + cntR) * (i0 + cntR - 1) / 2 - i0 * (i0 - 1) / 2;
      }
      debug {
        writeln("ans (move) = ", ans);
      }
      
      // inversion
      auto bit = new long[N];
      long now;
      foreach (j; 0 .. N) {
        now += j - bit.bSum(Q[j]);
        ans[j] += now;
        bit.bAdd(Q[j], 1);
      }
      
      foreach (j; 0 .. N) {
        if (j > 0) write(" ");
        write(ans[j]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}