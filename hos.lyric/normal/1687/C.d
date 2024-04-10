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




void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        const M = readInt;
        auto A = new long[N]; foreach (u; 0 .. N) A[u] = readInt;
        auto B = new long[N]; foreach (u; 0 .. N) B[u] = readInt;
        auto L = new int[M];
        auto R = new int[M];
        foreach (i; 0 .. M) {
          L[i] = readInt - 1;
          R[i] = readInt;
        }
        
        auto G = new int[][N + 1];
        foreach (i; 0 .. M) {
          G[L[i]] ~= i;
          G[R[i]] ~= i;
        }
        
        auto ds = new long[N + 1];
        foreach (u; 0 .. N) {
          ds[u + 1] = ds[u] + (B[u] - A[u]);
        }
        
        auto fs = new bool[N + 1];
        foreach (u; 0 .. N + 1) {
          fs[u] = (ds[u] != 0);
        }
        auto set = redBlackTree(iota(N + 1).array);
        DList!int que;
        foreach (i; 0 .. M) {
          if (!fs[L[i]] && !fs[R[i]]) {
            que ~= i;
          }
        }
        for (; !que.empty; ) {
          const i = que.front;
          que.removeFront;
          auto ran = set.upperBound(L[i]);
          int[] us;
          foreach (u; ran) {
            if (u >= R[i]) break;
            us ~= u;
          }
          foreach (u; us) {
            fs[u] = false;
            foreach (j; G[u]) {
              if (!fs[L[j]] && !fs[R[j]]) {
                que ~= j;
              }
            }
          }
          set.removeKey(us);
        }
        
        bool ans = true;
        foreach (u; 0 .. N + 1) {
          ans = ans && !fs[u];
        }
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}