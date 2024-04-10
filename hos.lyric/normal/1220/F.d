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

enum E = 18;

int N;
int[] A;

int[] B;
Tuple!(int, int)[][] BMins;

int getMinIndex(int l, int r) {
  const e = bsr(r - l);
  return min(BMins[e][l], BMins[e][r - (1 << e)])[1];
}

int calc(int l, int r) {
  if (r - l == 0) {
    return 0;
  } else {
    const mid = getMinIndex(l, r);
    const resL = calc(l, mid);
    const resR = calc(mid + 1, r);
    return max(resL, resR) + 1;
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      const i0 = A.minIndex;
      B = A[i0 .. N] ~ A[0 .. i0];
      BMins = new Tuple!(int, int)[][](E, N);
      foreach (i; 0 .. N) {
        BMins[0][i] = tuple(B[i], i);
      }
      foreach (e; 0 .. E - 1) {
        foreach (i; 0 .. N) {
          BMins[e + 1][i] = BMins[e][i];
          if (i + (1 << e) < N) {
            chmin(BMins[e + 1][i], BMins[e][i + (1 << e)]);
          }
        }
      }
      debug {
        writeln("B = ", B);
        foreach (i; 0 .. N) foreach (j; i + 1 .. N + 1) {
          int km = i;
          foreach (k; i .. j) {
            if (B[km] > B[k]) {
              km = k;
            }
          }
          assert(km == getMinIndex(i, j));
        }
      }
      
      int lo = 0, hi = N - 1;
      for (; lo + 1 < hi; ) {
        // (mid) B[0] (N - 1 - mid)
        const mid = (lo + hi) / 2;
        const resL = calc(N - mid, N);
        const resR = calc(1, N - mid);
        (resL < resR) ? (lo = mid) : (hi = mid);
      }
      
      long ans;
      {
        const resL = calc(N - hi, N);
        const resR = calc(1, N - hi);
        ans = max(resL, resR) + 1;
      }
      int shift = i0;
      shift += N - hi;
      shift %= N;
      writeln(ans, " ", shift);
      
      debug {
        auto dp = new int[][](2 * N + 1, 2 * N + 1);
        foreach (i; 0 .. 2 * N) {
          dp[i][i + 1] = 1;
        }
        foreach (w; 2 .. 2 * N + 1) {
          foreach (i; 0 .. 2 * N - w + 1) {
            const j = i + w;
            int km = i;
            foreach (k; i .. j) {
              if (A[km % N] > A[k % N]) {
                km = k;
              }
            }
            dp[i][j] = max(dp[i][km], dp[km + 1][j]) + 1;
          }
        }
        /*
        writeln("dp = ");
        foreach (i; 0 .. 2 * N + 1) {
          writeln(dp[i]);
        }
        //*/
        int brt = N + 1;
        foreach (i; 0 .. N) {
          writeln(i, ": ", dp[i][i + N]);
          chmin(brt, dp[i][i + N]);
        }
        assert(brt == ans);
        assert(brt == dp[shift][shift + N]);
      }
    }
  } catch (EOFException e) {
  }
}