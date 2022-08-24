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


enum EPS = 1e-12L;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const L = readReal();
        auto A = new real[N + 2];
        A[0] = 0.0L;
        A[N + 1] = L;
        foreach (i; 1 .. N + 1) {
          A[i] = readReal();
        }
        
        auto ls = new real[N + 2];
        auto rs = new real[N + 2];
        ls[0] = 0.0L;
        foreach (i; 0 .. N + 1) {
          ls[i + 1] = ls[i] + (A[i + 1] - A[i]) / (1 + i);
        }
        rs[N + 1] = 0.0L;
        foreach_reverse (i; 0 .. N + 1) {
          rs[i] = (A[i + 1] - A[i]) / (N + 1 - i) + rs[i + 1];
        }
        debug {
          writeln("ls = ", ls);
          writeln("rs = ", rs);
        }
        
        real ans;
        foreach (i; 0 .. N + 1) {
          if (ls[i] <= rs[i] + EPS && ls[i + 1] + EPS >= rs[i + 1]) {
            const real u = 1 + i;
            const real v = N + 1 - i;
            const d = A[i + 1] - A[i];
            ans = (d + u * ls[i] + v * rs[i + 1]) / (u + v);
            break;
          }
        }
        writefln("%.12f", ans);
      }
    }
  } catch (EOFException e) {
  }
}