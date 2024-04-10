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


enum K = 10;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto S = new string[N];
      foreach (i; 0 .. N) {
        S[i] = readToken();
      }
      const M = readInt();
      auto A = new int[M];
      auto B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      auto heads = new string[N + M];
      auto tails = new string[N + M];
      auto has = new bool[][][](N + M, K);
      foreach (i; 0 .. N + M) {
        foreach (k; 0 .. K) {
          has[i][k] = new bool[1 << k];
        }
      }
      foreach (i; 0 .. N) {
        const len = cast(int)(S[i].length);
        if (len > K) {
          heads[i] = S[i][0 .. K];
          tails[i] = S[i][$ - K .. $];
        } else {
          heads[i] = tails[i] = S[i];
        }
        foreach (k; 1 .. K) {
          foreach (x; 0 .. len - k + 1) {
            int p;
            foreach (l; 0 .. k) {
              p |= (S[i][x + l] - '0') << l;
            }
            has[i][k][p] = true;
          }
        }
      }
      
      foreach (j; 0 .. M) {
        const i = N + j;
        heads[i] = heads[A[j]] ~ heads[B[j]];
        if (heads[i].length > K) {
          heads[i] = heads[i][0 .. K];
        }
        tails[i] = tails[A[j]] ~ tails[B[j]];
        if (tails[i].length > K) {
          tails[i] = tails[i][$ - K .. $];
        }
        foreach (k; 1 .. K) {
          foreach (p; 0 .. 1 << k) {
            has[i][k][p] = has[A[j]][k][p] || has[B[j]][k][p];
          }
        }
        const lenA = cast(int)(tails[A[j]].length);
        const lenB = cast(int)(heads[B[j]].length);
        foreach (kA; 1 .. lenA + 1) foreach (kB; 1 .. lenB + 1) {
          if (kA + kB < K) {
            int p;
            foreach (l; 0 .. kA) {
              p |= (tails[A[j]][lenA - kA + l] - '0') << l;
            }
            foreach (l; 0 .. kB) {
              p |= (heads[B[j]][l] - '0') << (kA + l);
            }
            has[i][kA + kB][p] = true;
          }
        }
        int ans;
        foreach (k; 1 .. K) {
          if (has[i][k].all) {
            ans = k;
          }
        }
        writeln(ans);
      }
      
    }
  } catch (EOFException e) {
  }
}