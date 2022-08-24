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


int brute(int[] A) {
  const N = cast(int)(A.length);
  int ans = -1;
  auto perm = iota(N).array;
  do {
    bool ok = true;
    int cost;
    foreach (i; 0 .. N - 1) {
      ok = ok && (A[perm[i]] != A[perm[i + 1]]);
      if (abs(perm[i + 1] - perm[i]) > 1) {
        ++cost;
      }
    }
    if (ok) {
      if (ans == -1 || ans > cost) {
        ans = cost;
      }
    }
  } while (perm.nextPermutation);
  return ans;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt() - 1;
        }
        
        int[] cuts;
        cuts ~= 0;
        foreach (i; 1 .. N) {
          if (A[i - 1] == A[i]) {
            cuts ~= i;
          }
        }
        const m = cast(int)(cuts.length);
        cuts ~= N;
        
        auto cnt = new int[N];
        foreach (j; 0 .. m) {
          ++cnt[A[cuts[j]]];
          ++cnt[A[cuts[j + 1] - 1]];
        }
        const b = cnt.maxIndex;
        debug {
          writeln("cuts = ", cuts);
          writeln("m = ", m);
          writeln("cnt = ", cnt);
          writeln("b = ", b);
        }
        
        int ans = -1;
        if (cnt[b] <= m + 1) {
          ans = m - 1;
        } else {
          int[] ss;
          foreach (i; 1 .. N) {
            if (A[i - 1] != A[i]) {
              int s;
              if (A[i - 1] == b) ++s;
              if (A[i] == b) ++s;
              ss ~= s;
            }
          }
          ss.sort;
          int mm = m, cc = cnt[b];
          foreach (s; ss) {
            mm += 1;
            cc += s;
            if (cc <= mm + 1) {
              ans = mm - 1;
              break;
            }
          }
        }
        writeln(ans);
        
        debug {
          const brt = brute(A);
          assert(brt == ans, format("%s: %s %s", A, brt, ans));
        }
      }
    }
  } catch (EOFException e) {
  }
}