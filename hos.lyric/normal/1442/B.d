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


enum MO = 998244353;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const K = readInt();
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt();
        }
        auto B = new int[K];
        foreach (k; 0 .. K) {
          B[k] = readInt();
        }
        
        auto lef = new int[N + 1];
        auto rig = new int[N + 1];
        rig[0] = A[0];
        lef[A[0]] = 0;
        foreach (i; 0 .. N - 1) {
          rig[A[i]] = A[i + 1];
          lef[A[i + 1]] = A[i];
        }
        rig[A[N - 1]] = 0;
        lef[0] = A[N - 1];
        
        auto del = new bool[N + 1];
        del[0] = true;
        foreach (k; 0 .. K) {
          del[B[k]] = true;
        }
        
        long ans = 1;
        foreach (k; 0 .. K) {
          const l = lef[B[k]];
          const r = rig[B[k]];
          rig[l] = r;
          lef[r] = l;
          int num;
          if (!del[l]) ++num;
          if (!del[r]) ++num;
          (ans *= num) %= MO;
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}