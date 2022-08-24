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
        auto P = new int[N];
        foreach (i; 0 .. N) {
          P[i] = readInt();
        }
        
        const grp = P.group.array;
        const grpLen = cast(int)(grp.length);
        debug {
          writeln("grp = ", grp);
        }
        auto sum = new int[grpLen + 1];
        foreach (j; 0 .. grpLen) {
          sum[j + 1] = sum[j] + grp[j][1];
        }
        
        auto ans = new int[3];
        foreach (j; 2 .. grpLen) {
          if (sum[1] - sum[0] < sum[j] - sum[1]) {
            foreach (k; j + 1 .. grpLen + 1) {
              if (sum[1] - sum[0] < sum[k] - sum[j] && 2 * sum[k] <= N) {
                if (ans.sum < sum[k]) {
                  ans = [sum[1] - sum[0], sum[j] - sum[1], sum[k] - sum[j]];
                }
              }
            }
            break;
          }
        }
        writeln(ans[0], " ", ans[1], " ", ans[2]);
      }
    }
  } catch (EOFException e) {
  }
}