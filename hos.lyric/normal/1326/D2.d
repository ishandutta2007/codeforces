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

int[] manacher(T)(T a) {
  const n = cast(int)(a.length);
  auto r = new int[n * 2];
  for (int i = 0, j = 0, k; i < n * 2; i += k, j = max(j - k, 0)) {
    for (; 0 <= i - j && i + j + 1 < n * 2 && a[(i - j) / 2] == a[(i + j + 1) / 2]; ++j) {}
    r[i] = j;
    for (k = 1; 0 <= i - k && 0 <= j - k && r[i - k] != j - k; ++k) {
      r[i + k] = min(r[i - k], j - k);
    }
  }
  return r;
}



void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const S = readToken();
        const L = cast(int)(S.length);
        
        const rads = manacher(S);
        debug {
          writeln("rads = ", rads);
        }
        
        auto ls = new int[L + 1];
        ls[] = -1;
        foreach (x; 0 .. L) {
          // x - rads[x] <= 2 k
          chmax(ls[(x - rads[x] + 1) / 2], x);
        }
        foreach (k; 1 .. L + 1) {
          chmax(ls[k], ls[k - 1]);
        }
        auto rs = new int[L + 1];
        rs[] = 2 * L;
        foreach (x; L - 1 .. 2 * L - 1) {
          // 2 (L - 1 - k) <= x + rads[x]
          chmin(rs[(2 * (L - 1) - x - rads[x] + 1) / 2], x);
        }
        foreach (k; 1 .. L + 1) {
          chmin(rs[k], rs[k - 1]);
        }
        debug {
          writeln("ls = ", ls);
          writeln("rs = ", rs);
        }
        
        int ansA, ansB;
        void check(int a, int b) {
          if (ansA + ansB < a + b) {
            ansA = a;
            ansB = b;
          }
        }
        foreach (k; 0 .. L + 1) {
          check(k, k);
          if (ls[k] != -1) {
            const i = k;
            const j = ls[k] - i;
            check(k + (j - i + 1), k);
          }
          if (rs[k] != 2 * L) {
            const i = L - 1 - k;
            const j = rs[k] - i;
            check(k, (i - j + 1) + k);
          }
          if ((k + 1) + (k + 1) > L) {
            break;
          }
          if (S[k] != S[L - 1 - k]) {
            break;
          }
        }
        writeln(S[0 .. ansA] ~ S[L - ansB .. L]);
      }
    }
  } catch (EOFException e) {
  }
}