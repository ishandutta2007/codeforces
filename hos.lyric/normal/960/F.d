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
      const M = readInt();
      auto A = new int[M];
      auto B = new int[M];
      auto W = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        W[i] = readInt();
      }
      
      // incr w, incr val
      alias Entry = Tuple!(int, "w", int, "val");
      auto sets = new RedBlackTree!Entry[N];
      foreach (u; 0 .. N) {
        sets[u] = new RedBlackTree!Entry;
      }
      auto dp = new int[M];
      foreach (i; 0 .. M) {
        // w < W[i]
        auto ranA = sets[A[i]].lowerBound(Entry(W[i], -1));
        if (!ranA.empty) {
          dp[i] = ranA.back.val;
        }
        dp[i] += 1;
        // insert
        auto ranL = sets[B[i]].lowerBound(Entry(W[i], M + 1));
        if (!ranL.empty && ranL.back.val >= dp[i]) {
          continue;
        }
        auto ranR = sets[B[i]].upperBound(Entry(W[i], -1));
        Entry[] rems;
        foreach (e; ranR) {
          if (dp[i] >= e.val) {
            rems ~= e;
          } else {
            break;
          }
        }
        foreach (e; rems) {
          sets[B[i]].removeKey(e);
        }
        sets[B[i]].insert(Entry(W[i], dp[i]));
      }
      debug {
        writeln("dp = ", dp);
      }
      const ans = dp.maxElement;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}