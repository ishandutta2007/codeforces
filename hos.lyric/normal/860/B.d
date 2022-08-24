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


enum L = 9;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new string[N];
      foreach (i; 0 .. N) {
        A[i] = readToken();
      }
      
      alias Entry = Tuple!(int, "val", int, "i");
      auto ess = new Entry[][L + 1];
      foreach (i; 0 .. N) {
        foreach (x; 0 .. L) {
          int val;
          foreach (y; x .. L) {
            val = val * 10 + (A[i][y] - '0');
            ess[y + 1 - x] ~= Entry(val, i);
          }
        }
      }
      
      auto opt = new int[N];
      opt[] = L + 1;
      auto ans = new int[N];
      foreach (l; 1 .. L + 1) {
        auto es = ess[l];
        es.sort;
        const esLen = cast(int)(es.length);
        for (int j = 0, k; j < esLen; j = k) {
          for (k = j; k < esLen && es[j].val == es[k].val; ++k) {}
          if (es[j].i == es[k - 1].i) {
            const i = es[j].i;
            if (chmin(opt[i], l)) {
              ans[i] = es[j].val;
            }
          }
        }
      }
      
      foreach (i; 0 .. N) {
        writefln("%0*d", opt[i], ans[i]);
      }
    }
  } catch (EOFException e) {
  }
}