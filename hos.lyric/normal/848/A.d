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


enum LIM = 10^^5 + 5;

void main() {
  auto prev = new int[LIM];
  prev[] = -1;
  prev[0] = 0;
  foreach (i; 0 .. 3) {
    foreach_reverse (x; 0 .. LIM) {
      if (prev[x] != -1) {
        for (int a = 2; x + a * (a - 1) / 2 < LIM; ++a) {
          const xx = x + a * (a - 1) / 2;
          if (prev[xx] == -1) {
            prev[xx] = a;
          }
        }
      }
    }
  }
  foreach (x; 0 .. LIM) {
    assert(prev[x] != -1);
  }
  
  try {
    for (; ; ) {
      const K = readInt();
      
      int[] as;
      as ~= 1;
      for (int x = K; x > 0; ) {
        const a = prev[x];
        as ~= a;
        x -= a * (a - 1) / 2;
      }
      
      string ans;
      foreach (i, a; as) {
        ans ~= (cast(char)('a' + i)).repeat(a).array;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}