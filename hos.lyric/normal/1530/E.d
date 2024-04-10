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


enum V = 26;

char chr(int u) {
  return cast(char)('a' + u);
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const S = readToken();
        const N = cast(int)(S.length);
        debug {
          writeln("S = ", S);
          stdout.flush;
        }
        
        auto freq = new int[V];
        foreach (i; 0 .. N) {
          ++freq[S[i] - 'a'];
        }
        
        int ansLen;
        auto ans = new char[N];
        ans[] = '?';
        foreach (u; 0 .. V) {
          if (freq[u] == N) {
            ans[] = chr(u);
            goto done;
          }
        }
        foreach (u; 0 .. V) {
          if (freq[u] == 1) {
            ans[ansLen++] = chr(u);
            foreach (v; 0 .. V) {
              if (u != v) {
                foreach (_; 0 .. freq[v]) {
                  ans[ansLen++] = chr(v);
                }
              }
            }
            goto done;
          }
        }
        {
          int u0 = -1;
          foreach (u; 0 .. V) {
            if (freq[u] > 0) {
              u0 = u;
              break;
            }
          }
          assert(~u0);
          if (freq[u0] <= N / 2 + 1) {
            ans[0] = chr(u0);
            int pos = 1;
            foreach (_; 1 .. freq[u0]) {
              ans[pos] = chr(u0);
              pos += 2;
            }
            pos = 0;
            foreach (v; u0 + 1 .. V) {
              foreach (_; 0 .. freq[v]) {
                for (; ans[pos] != '?'; ++pos) {}
                ans[pos] = chr(v);
              }
            }
          } else {
            int u1 = -1;
            foreach (u; u0 + 1 .. V) {
              if (freq[u] > 0) {
                u1 = u;
                break;
              }
            }
            assert(~u1);
            int u2 = -1;
            foreach (u; u1 + 1 .. V) {
              if (freq[u] > 0) {
                u2 = u;
                break;
              }
            }
            if (~u2) {
              ans[ansLen++] = chr(u0);
              ans[ansLen++] = chr(u1);
              foreach (_; 1 .. freq[u0]) ans[ansLen++] = chr(u0);
              ans[ansLen++] = chr(u2);
              foreach (_; 1 .. freq[u1]) ans[ansLen++] = chr(u1);
              foreach (_; 1 .. freq[u2]) ans[ansLen++] = chr(u2);
              foreach (u; u2 + 1 .. V) {
                foreach (_; 0 .. freq[u]) ans[ansLen++] = chr(u);
              }
            } else {
              ans[ansLen++] = chr(u0);
              foreach (_; 0 .. freq[u1]) ans[ansLen++] = chr(u1);
              foreach (_; 1 .. freq[u0]) ans[ansLen++] = chr(u0);
            }
          }
        }
       done:{}
        writeln(ans);
        
        debug {
          auto A = new int[N];
          foreach (i; 0 .. N) {
            A[i] = S[i] - 'a';
          }
          A.sort;
          int mn = N + 1;
          int[] ams;
          do {
            auto fail = new int[N + 1];
            int j = fail[0] = -1;
            foreach (i; 0 .. N) {
              for (; ~j && A[j] != A[i]; j = fail[j]) {}
              fail[i + 1] = ++j;
            }
            const cost = fail.maxElement;
            // writeln(A, ": ", fail, " ", cost);
            if (chmin(mn, cost)) {
              ams = A.dup;
            }
          } while (A.nextPermutation);
          writeln("mn = ", mn);
          string brt;
          foreach (i; 0 .. N) {
            brt ~= chr(ams[i]);
          }
          writeln("brt = ", brt);
          assert(brt == ans);
        }
      }
    }
  } catch (EOFException e) {
  }
}