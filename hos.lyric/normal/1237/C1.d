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

alias Pt = Tuple!(int, "x", int, "y", int, "z", int, "id");


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new Pt[N];
      foreach (i; 0 .. N) {
        P[i].x = readInt();
        P[i].y = readInt();
        P[i].z = readInt();
        P[i].id = i;
      }
      
      sort(P);
      
      int[] ans;
      
      int[] as;
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && P[i].x == P[j].x; ++j) {}
        int[] bs;
        for (int k = i, l; k < j; k = l) {
          for (l = k; l < j && P[k].y == P[l].y; ++l) {}
          foreach (m; k .. k + (l - k) / 2 * 2) {
            ans ~= P[m].id;
          }
          if ((l - k) % 2 != 0) {
            bs ~= P[l - 1].id;
          }
        }
        const bsLen = cast(int)(bs.length);
        foreach (m; 0 .. bsLen / 2 * 2) {
          ans ~= bs[m];
        }
        if (bsLen % 2 != 0) {
          as ~= bs[$ - 1];
        }
      }
      assert(as.length % 2 == 0);
      ans ~= as;
      
      for (int i = 0; i < N; i += 2) {
        writeln(ans[i] + 1, " ", ans[i + 1] + 1);
      }
    }
  } catch (EOFException e) {
  }
}