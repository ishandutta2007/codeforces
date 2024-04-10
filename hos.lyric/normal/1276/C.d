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
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      A.sort;
      
      auto ds = new int[N + 1];
      ds[1 .. $] = 1;
      foreach (d; 1 .. N + 1) {
        for (int m = d; m <= N; m += d) {
          chmax(ds[m], min(d, m / d));
        }
      }
      debug {
        writeln("ds = ", ds);
      }
      
      BinaryHeap!(Array!(Tuple!(int, int))) que;
      foreach (grp; A.group) {
        que.insert(tuple(cast(int)(grp[1]), grp[0]));
      }
      for (int m = N; m > 0; --m) {
        if (que.front[0] <= ds[m]) {
          const d = ds[m], e = m / ds[m];
          auto ans = new int[][](d, e);
          int pos;
          for (; !que.empty; ) {
            auto t = que.front;
            que.removeFront;
            foreach (_; 0 .. t[0]) {
              ans[pos % d][(pos % d + pos / d) % e] = t[1];
              ++pos;
            }
          }
          writeln(m);
          writeln(d, " ", e);
          foreach (x; 0 .. d) {
            foreach (y; 0 .. e) {
              if (y > 0) write(" ");
              write(ans[x][y]);
            }
            writeln();
          }
          break;
        }
        auto t = que.front;
        que.removeFront;
        if (t[0] >= 2) {
          que.insert(tuple(t[0] - 1, t[1]));
        }
      }
    }
  } catch (EOFException e) {
  }
}