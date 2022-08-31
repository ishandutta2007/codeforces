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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto W = new long[N];
        foreach (u; 0 .. N) {
          W[u] = readLong();
        }
        auto A = new int[N - 1];
        auto B = new int[N - 1];
        foreach (i; 0 .. N - 1) {
          A[i] = readInt() - 1;
          B[i] = readInt() - 1;
        }
        
        auto deg = new int[N];
        foreach (i; 0 .. N - 1) {
          ++deg[A[i]];
          ++deg[B[i]];
        }
        
        long[] ws;
        foreach (u; 0 .. N) {
          foreach (_; 0 .. deg[u] - 1) {
            ws ~= W[u];
          }
        }
        ws.sort!"a > b";
        
        auto ans = new long[N - 1];
        ans[0] = W.sum;
        foreach (k; 0 .. N - 2) {
          ans[k + 1] = ans[k] + ws[k];
        }
        
        foreach (k; 0 .. N - 1) {
          if (k > 0) write(" ");
          write(ans[k]);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}