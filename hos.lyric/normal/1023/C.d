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




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      const S = readToken();
      
      alias Entry = Tuple!(int, "h", int, "i", int, "j");
      Entry[] es;
      
      DList!int stack;
      int now;
      foreach (i; 0 .. N) {
        if (S[i] == '(') {
          stack ~= i;
          ++now;
        } else {
          const j = stack.back;
          stack.removeBack;
          --now;
          es ~= Entry(now, j, i);
        }
      }
      es.sort;
      debug {
        writeln("es = ", es);
      }
      
      auto used = new bool[N];
      foreach (k; 0 .. K / 2) {
        used[es[k].i] = used[es[k].j] = true;
      }
      string ans;
      foreach (i; 0 .. N) {
        if (used[i]) {
          ans ~= S[i];
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}