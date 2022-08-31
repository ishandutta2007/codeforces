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


alias Pt = Tuple!(long, "x", long, "y", int, "id");

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto V = new Pt[N];
      foreach (i; 0 .. N) {
        V[i].x = readLong();
        V[i].y = readLong();
        V[i].id = i;
      }
      V.sort!((a, b) => (a.x^^2 + a.y^^2 < b.x^^2 + b.y^^2));
      debug {
        writeln("V = ", V);
      }
      
      auto ans = new int[N];
      
      ans[V[0].id] = +1;
      long x = V[0].x, y = V[0].y;
      if (N % 2 == 0) {
        foreach (s; [+1, -1]) {
          const xx = x + s * V[1].x;
          const yy = y + s * V[1].y;
          if (xx^^2 + yy^^2 <= 2 * (V[1].x^^2 + V[1].y^^2)) {
            debug {
              writeln(s, " ", V[1]);
              writeln(xx, " ", yy);
            }
            ans[V[1].id] = s;
            x = xx;
            y = yy;
            goto found2;
          }
        }
        assert(false);
       found2:
      }
      for (int i = (N % 2 == 0) ? 2 : 1; i < N; i += 2) {
        foreach (s; [+1, -1]) foreach (t; [+1, -1]) {
          const xx = x + s * V[i].x + t * V[i + 1].x;
          const yy = y + s * V[i].y + t * V[i + 1].y;
          if (xx^^2 + yy^^2 <= 2 * (V[i + 1].x^^2 + V[i + 1].y^^2)) {
            debug {
              writeln(s, " ", V[i], ", ", t, " ", V[i + 1]);
              writeln(xx, " ", yy);
            }
            ans[V[i].id] = s;
            ans[V[i + 1].id] = t;
            x = xx;
            y = yy;
            goto found;
          }
        }
        assert(false);
       found:
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