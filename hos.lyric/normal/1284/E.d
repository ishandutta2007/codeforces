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


alias Pt = Tuple!(long, "x", long, "y");

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new Pt[N];
      foreach (i; 0 .. N) {
        P[i].x = readLong();
        P[i].y = readLong();
      }
      
      long ans;
      foreach (i; 0 .. N) {
        Pt[] ps;
        foreach (j; 0 .. N) {
          if (j != i) {
            ps ~= Pt(P[j].x - P[i].x, P[j].y - P[i].y);
          }
        }
        ps.sort!((ref Pt a, ref Pt b) {
          const sa = (a.y > 0) ? 1 : (a.y < 0) ? 3 : (a.x > 0) ? 0 : 2;
          const sb = (b.y > 0) ? 1 : (b.y < 0) ? 3 : (b.x > 0) ? 0 : 2;
          if (sa != sb) return (sa < sb);
          return (a.x * b.y > a.y * b.x);
        });
        int r;
        foreach (l; 0 .. N - 1) {
          for (chmax(r, l + 1); r < l + (N - 1) && ps[l].x * ps[r % (N - 1)].y > ps[l].y * ps[r % (N - 1)].x; ++r) {}
          const long m = r - l - 1;
          ans += m * (m - 1) * (m - 2) / 6;
        }
      }
      
      const long n = N;
      ans = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120 * 5 - ans;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}