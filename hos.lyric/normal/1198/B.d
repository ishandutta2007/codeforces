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


int N;
int[] A;
int Q;
int[] T, P, X;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      Q = readInt();
      T = new int[Q];
      P = new int[Q];
      X = new int[Q];
      foreach (q; 0 .. Q) {
        T[q] = readInt();
        if (T[q] == 1) {
          P[q] = readInt() - 1;
        }
        X[q] = readInt();
      }
      
      auto ans = new int[N];
      ans[] = -1;
      int maxPay;
      foreach_reverse (q; 0 .. Q) {
        switch (T[q]) {
          case 1: {
            if (ans[P[q]] == -1) {
              ans[P[q]] = max(X[q], maxPay);
            }
          } break;
          case 2: {
            chmax(maxPay, X[q]);
          } break;
          default: assert(false);
        }
      }
      foreach (i; 0 .. N) {
        if (ans[i] == -1) {
          ans[i] = max(A[i], maxPay);
        }
      }
      
      foreach (i; 0 .. N) {
        if (i > 0) {
          write(" ");
        }
        write(ans[i]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}