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
  int[][] efs;
  foreach (e0; 0 .. 3) foreach (f0; 0 .. 3) {
    foreach (e1; 0 .. 3) foreach (f1; 0 .. 3) {
      if (e0 * 3 + f0 < e1 * 3 + f1) {
        if (min(e0, e1) <= 1 && 1 <= max(e0, e1) && min(f0, f1) <= 1 && 1 <= max(f0, f1)) {
          efs ~= [e0, f0, e1, f1];
        }
      }
    }
  }
  debug {
    writeln("|efs| = ", efs.length);
    writeln("efs = ", efs);
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      const Q = readInt();
      auto Y = new int[N];
      foreach (x; 0 .. N) {
        Y[x] = readInt() - 1;
      }
      auto X0 = new int[Q];
      auto Y0 = new int[Q];
      auto X1 = new int[Q];
      auto Y1 = new int[Q];
      foreach (q; 0 .. Q) {
        X0[q] = readInt() - 1;
        Y0[q] = readInt() - 1;
        X1[q] = readInt();
        Y1[q] = readInt();
      }
      
      auto z = new long[][][](Q, 3, 3);
      
      auto qss = new int[][N + 1];
      foreach (q; 0 .. Q) {
        qss[X0[q]] ~= q;
        qss[X1[q]] ~= q;
      }
      auto bit = new int[N];
      foreach (x; 0 .. N + 1) {
        foreach (q; qss[x]) {
          const e = (x == X0[q]) ? 0 : 1;
          z[q][e][0] = bit.bSum(Y0[q]);
          z[q][e][1] = bit.bSum(Y1[q]);
          z[q][e][2] = x;
        }
        if (x < N) {
          bit.bAdd(Y[x], +1);
        }
      }
      
      foreach (q; 0 .. Q) {
        z[q][2][0] = Y0[q];
        z[q][2][1] = Y1[q];
        z[q][2][2] = N;
        foreach_reverse (e; 0 .. 3 - 1) foreach (f; 0 .. 3) {
          z[q][e + 1][f] -= z[q][e][f];
        }
        foreach (e; 0 .. 3) foreach_reverse (f; 0 .. 3 - 1) {
          z[q][e][f + 1] -= z[q][e][f];
        }
        debug {
          writeln("z[q] = ", z[q]);
        }
        long ans = z[q][1][1] * (z[q][1][1] - 1) / 2;
        foreach (ef; efs) {
          ans += z[q][ef[0]][ef[1]] * z[q][ef[2]][ef[3]];
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}