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

enum E = 20;


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      auto mx = new int[][](E, N);
      auto mn = new int[][](E, N);
      auto live = new bool[][](E, N);
      foreach (i; 0 .. N) {
        mx[0][i] = A[i];
        mn[0][i] = A[i];
        live[0][i] = true;
      }
      foreach (e; 0 .. E - 1) {
        foreach (i; 0 .. N) {
          const j = (i + (1 << e)) % N;
          mx[e + 1][i] = max(mx[e][i], mx[e][j]);
          mn[e + 1][i] = min(mn[e][i], mn[e][j]);
          live[e + 1][i] = live[e][i] && live[e][j] && !(mx[e][i] > 2 * mn[e][j]);
        }
      }
      auto ans = new int[N];
      foreach (i; 0 .. N) {
        int m = 0;
        int sum;
        int j = i;
        foreach_reverse (e; 0 .. E) {
          if (live[e][j] && !(m > 2 * mn[e][j])) {
            chmax(m, mx[e][j]);
            sum += 1 << e;
            j = (j + (1 << e)) % N;
          }
        }
        ans[i] = (sum >= 2 * N) ? -1 : sum;
      }
      
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(ans[i]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}