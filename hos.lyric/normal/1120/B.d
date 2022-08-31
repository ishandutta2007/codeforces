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
      const A = readToken();
      const B = readToken();
      
      auto ds = new long[N];
      foreach (i; 0 .. N) {
        ds[i] = B[i] - A[i];
      }
      foreach (i; 0 .. N - 1) {
        ds[i + 1] -= ds[i];
      }
      debug {
        writeln("ds = ", ds);
      }
      if (ds[N - 1] == 0) {
        long total;
        foreach (i; 0 .. N - 1) {
          total += abs(ds[i]);
        }
        writeln(total);
        auto as = new int[N];
        foreach (i; 0 .. N) {
          as[i] = A[i] - '0';
        }
        auto oks = new bool[N - 1];
        auto set = new RedBlackTree!int;
        void check(int i) {
          if (0 <= i && i < N - 1) {
            if (ds[i] > 0) {
              oks[i] = (as[i] < 9 && as[i + 1] < 9);
            } else if (ds[i] < 0) {
              oks[i] = (as[i] > ((i == 0) ? 1 : 0) && as[i + 1] > 0);
            } else {
              oks[i] = false;
            }
            if (oks[i]) {
              set.insert(i);
            } else {
              set.removeKey(i);
            }
          }
        }
        foreach (i; 0 .. N - 1) {
          check(i);
        }
        foreach (iter; 0 .. min(total, 10^^5)) {
          debug {
            writeln("oks = ", oks);
          }
          assert(!set.empty);
          const i = set.front;
          if (ds[i] > 0) {
            writeln(i + 1, " ", 1);
            --ds[i];
            ++as[i];
            ++as[i + 1];
          } else if (ds[i] < 0) {
            writeln(i + 1, " ", -1);
            ++ds[i];
            --as[i];
            --as[i + 1];
          } else {
            assert(false);
          }
          check(i - 1);
          check(i);
          check(i + 1);
        }
      } else {
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}