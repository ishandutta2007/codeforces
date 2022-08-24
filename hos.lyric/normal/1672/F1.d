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
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt;
        }
        
        auto xss = new int[][N + 1];
        foreach (i; 0 .. N) {
          xss[A[i]] ~= i;
        }
        auto lens = new int[N + 1];
        foreach (a; 1 .. N + 1) {
          lens[a] = cast(int)(xss[a].length);
        }
        
        auto as = iota(1, N + 1).array;
        as.sort!((a, b) => (lens[a] > lens[b]));
        debug {
          writeln("xss = ", xss);
          writeln("lens = ", lens);
          writeln("as = ", as);
        }
        
        auto ans = new int[N];
        for (; lens[as[0]] >= 1; ) {
          int[] ys;
          foreach (a; as) {
            if (lens[a] == 0) {
              break;
            }
            ys ~= xss[a][--lens[a]];
          }
          debug {
            writeln("ys = ", ys);
          }
          const ysLen = cast(int)(ys.length);
          foreach (j; 0 .. ysLen - 1) {
            ans[ys[j]] = A[ys[j + 1]];
          }
          ans[ys[ysLen - 1]] = A[ys[0]];
        }
        
        foreach (i; 0 .. N) {
          if (i) write(" ");
          write(ans[i]);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}