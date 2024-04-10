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
        const K = readInt();
        const S = readToken();
        
        auto app = new bool[][](K, 2);
        foreach (i; 0 .. N) {
          if (S[i] != '?') {
            app[i % K][S[i] - '0'] = true;
          }
        }
        
        bool ok = true;
        auto cnt = new int[2];
        foreach (r; 0 .. K) {
          if (app[r][0] && app[r][1]) {
            ok = false;
          }
          foreach (s; 0 .. 2) {
            if (app[r][s]) {
              ++cnt[s];
            }
          }
        }
        
        bool ans;
        if (ok) {
          if (2 * cnt[0] <= K && 2 * cnt[1] <= K) {
            ans = true;
          }
        }
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}