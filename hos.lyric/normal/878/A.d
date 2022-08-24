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


enum E = 10;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new string[N];
      auto X = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readToken();
        X[i] = readInt();
      }
      
      int[] ans = [(1 << E) - 1, 0, 0];
      foreach (e; 0 .. E) {
        auto ts = new int[2];
        foreach (s; 0 .. 2) {
          int z = s << e;
          foreach (i; 0 .. N) {
            switch (A[i]) {
              case "&": z &= X[i]; break;
              case "|": z |= X[i]; break;
              case "^": z ^= X[i]; break;
              default: assert(false);
            }
          }
          ts[s] = (z >> e) & 1;
        }
        debug {
          writeln(e, ": ", ts);
        }
        switch (ts[0] << 0 | ts[1] << 1) {
          case 0: ans[0] ^= 1 << e; break;
          case 1: ans[2] ^= 1 << e; break;
          case 2: break;
          case 3: ans[1] ^= 1 << e; break;
          default: assert(false);
        }
      }
      writeln(3);
      writefln("& %s", ans[0]);
      writefln("| %s", ans[1]);
      writefln("^ %s", ans[2]);
      
      debug {
        foreach (z; 0 .. 1 << E) {
          int expected = z;
          foreach (i; 0 .. N) {
            switch (A[i]) {
              case "&": expected &= X[i]; break;
              case "|": expected |= X[i]; break;
              case "^": expected ^= X[i]; break;
              default: assert(false);
            }
          }
          int actual = z;
          actual &= ans[0];
          actual |= ans[1];
          actual ^= ans[2];
          assert(expected == actual);
        }
      }
    }
  } catch (EOFException e) {
  }
}