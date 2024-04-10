import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


char tr(int x) {
  if (x < 10) return cast(char)('0' + x);
  if (x < 36) return cast(char)('A' + (x - 10));
  if (x < 62) return cast(char)('a' + (x - 36));
  assert(false);
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const M = readInt();
        const N = readInt();
        const K = readInt();
        auto A = new string[M];
        foreach (x; 0 .. M) {
          A[x] = readToken();
        }
        
        int rice;
        foreach (x; 0 .. M) {
          rice += A[x].count('R');
        }
        const q = rice / K, r = rice % K;
        
        alias Pt = Tuple!(int, "x", int, "y");
        Pt[] ps;
        foreach (x; 0 .. M) {
          if (x % 2 == 0) {
            foreach (y; 0 .. N) {
              ps ~= Pt(x, y);
            }
          } else {
            foreach_reverse (y; 0 .. N) {
              ps ~= Pt(x, y);
            }
          }
        }
        const psLen = cast(int)(ps.length);
        
        auto ans = new int[][](M, N);
        int pos;
        foreach (k; 0 .. K) {
          int need = q + ((k < r) ? 1 : 0);
          int cnt;
          for (; cnt < need; ++pos) {
            const x = ps[pos].x, y = ps[pos].y;
            ans[x][y] = k;
            if (A[x][y] == 'R') {
              ++cnt;
            }
          }
        }
        for (; pos < psLen; ++pos) {
          const x = ps[pos].x, y = ps[pos].y;
          ans[x][y] = K - 1;
        }
        
        foreach (x; 0 .. M) {
          foreach (y; 0 .. N) {
            write(tr(ans[x][y]));
          }
          writeln();
        }
      }
    }
  } catch (EOFException e) {
  }
}