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
      const M = readInt();
      const K = readInt();
      const N = readInt();
      const S = readInt();
      auto A = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt();
      }
      auto B = new int[S];
      foreach (s; 0 .. S) {
        B[s] = readInt();
      }
      
      const lim = max(A.maxElement, B.maxElement) + 1;
      auto cnt = new int[lim];
      
      B.sort;
      const BGroup = B.group.array;
      
      const width = M - K * (N - 1);
      foreach (i; 0 .. width) {
        ++cnt[A[i]];
      }
      
      int[] ans;
      foreach (x; 0 .. N) {
        // K x to the left, K (N - 1 - x) to the right
        bool ok = true;
        foreach (g; BGroup) {
          ok = ok && (cnt[g[0]] >= g[1]);
        }
        if (ok) {
          debug {
            writeln("found x = ", x);
          }
          auto need = new int[lim];
          foreach (g; BGroup) {
            need[g[0]] += g[1];
          }
          foreach (i; K * x .. K * x + width) {
            if (need[A[i]] > 0) {
              --need[A[i]];
            } else {
              ans ~= i;
            }
          }
          if (ans.length >= width - K) {
            ans.length = width - K;
          }
          writeln(ans.length);
          foreach (index, i; ans) {
            if (index > 0) write(" ");
            write(i + 1);
          }
          writeln();
          goto found;
        }
        if (x + 1 < N) {
          foreach (i; K * x .. K * (x + 1)) {
            --cnt[A[i]];
            ++cnt[A[i + width]];
          }
        }
      }
      writeln(-1);
     found:
    }
  } catch (EOFException e) {
  }
}