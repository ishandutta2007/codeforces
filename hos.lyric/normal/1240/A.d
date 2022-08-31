import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
        auto P = new long[N];
        foreach (i; 0 .. N) {
          P[i] = readLong();
        }
        const X = readLong();
        const A = readInt();
        const Y = readLong();
        const B = readInt();
        const K = readLong();
        
        sort(P);
        reverse(P);
        
        bool check(int l) {
          auto zs = new long[l];
          foreach (i; 0 .. l) {
            if ((i + 1) % A == 0) {
              zs[i] += X;
            }
            if ((i + 1) % B == 0) {
              zs[i] += Y;
            }
          }
          sort(zs);
          reverse(zs);
          long sum;
          foreach (i; 0 .. l) {
            sum += P[i] / 100 * zs[i];
          }
          return (sum >= K);
        }
        
        int lo = -1, hi = N + 1;
        for (; lo + 1 < hi; ) {
          const mid = (lo + hi) / 2;
          check(mid) ? (hi = mid) : (lo = mid);
        }
        writeln((hi <= N) ? hi : -1);
      }
    }
  } catch (EOFException e) {
  }
}