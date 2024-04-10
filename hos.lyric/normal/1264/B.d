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


int[] solveGreedy(int[] as) {
  const n = as.sum;
  foreach (s; 0 .. 4) {
    int[] ps;
    auto bs = as.dup;
    if (bs[s] > 0) {
      --bs[s];
      ps ~= s;
      foreach (i; 1 .. n) {
        foreach (x; 0 .. 4) {
          if (bs[x] > 0 && abs(x - ps[i - 1]) == 1) {
            --bs[x];
            ps ~= x;
            goto found;
          }
        }
        goto failed;
       found:
      }
      return ps;
    }
   failed:
  }
  return null;
}

void main() {
  debug {
    foreach (a; 0 .. 10) foreach (b; 0 .. 10) foreach (c; 0 .. 10) foreach (d; 0 .. 10) {
      const n = a + b + c + d;
      if (0 < n && n <= 10) {
        int[] perm;
        perm ~= repeat(0, a).array;
        perm ~= repeat(1, b).array;
        perm ~= repeat(2, c).array;
        perm ~= repeat(3, d).array;
        int[] ans;
        do {
          bool ok = true;
          foreach (i; 0 .. n - 1) {
            ok = ok && (abs(perm[i + 1] - perm[i]) == 1);
          }
          if (ok) {
            ans = perm.dup;
            break;
          }
        } while (perm.nextPermutation);
        const res = solveGreedy([a, b, c, d]);
        writeln([a, b, c, d], ": ", ans, " ", res);
        assert((ans != null) == (res != null));
      }
    }
  }
  
  try {
    for (; ; ) {
      auto A = new int[4];
      foreach (x; 0 .. 4) {
        A[x] = readInt();
      }
      const res = solveGreedy(A);
      if (res) {
        writeln("YES");
        foreach (i, x; res) {
          if (i > 0) write(" ");
          write(x);
        }
        writeln();
      } else {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}