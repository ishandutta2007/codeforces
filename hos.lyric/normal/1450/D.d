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


string brute(int[] A) {
  const N = cast(int)(A.length);
  string ans;
  foreach (k; 1 .. N + 1) {
    auto cnt = new int[N + 1];
    foreach (i; 0 .. N - k + 1) {
      ++cnt[A[i .. i + k].minElement];
    }
    bool ok = true;
    foreach (j; 1 .. N - k + 1 + 1) {
      ok = ok && (cnt[j] == 1);
    }
    ans ~= ok ? '1' : '0';
  }
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
          A[i] = readInt();
        }
        
        auto ls = new int[N + 1];
        auto rs = new int[N + 1];
        ls[] = -1;
        rs[] = -1;
        ls[0] = 0;
        rs[0] = N;
        foreach (j; 1 .. N + 1) {
          if ((A[ls[j - 1]] == j) == (A[rs[j - 1] - 1] == j)) {
            break;
          }
          if (A[ls[j - 1]] == j) {
            ls[j] = ls[j - 1] + 1;
            rs[j] = rs[j - 1];
          } else {
            ls[j] = ls[j - 1];
            rs[j] = rs[j - 1] - 1;
          }
        }
        debug {
          writeln("ls = ", ls);
          writeln("rs = ", rs);
        }
        
        auto ans = new char[N];
        ans[] = '0';
        
        {
          auto cnt = new int[N + 1];
          foreach (i; 0 .. N) {
            ++cnt[A[i]];
          }
          bool ok = true;
          foreach (j; 1 .. N + 1) {
            ok = ok && (cnt[j] == 1);
          }
          if (ok) {
            ans[N - N] = '1';
          }
        }
        
        int l = -1, r = -1;
        int mn = N + 1;
        foreach_reverse (j; 0 .. N - 1) {
          if (ls[j] != -1) {
            if (l == -1) {
              l = r = ls[j];
            }
            for (; l > ls[j]; ) {
              chmin(mn, A[--l]);
            }
            for (; r < rs[j]; ) {
              chmin(mn, A[r++]);
            }
            if (mn == j + 1) {
              ans[N - (j + 1)] = '1';
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