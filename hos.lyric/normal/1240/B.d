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

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        N = readInt();
        A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt() - 1;
        }
        
        auto ls = new int[N];
        auto rs = new int[N];
        ls[] = N;
        rs[] = -1;
        foreach (i; 0 .. N) {
          chmin(ls[A[i]], i);
          chmax(rs[A[i]], i);
        }
        
        Tuple!(int, int)[] ps;
        foreach (x; 0 .. N) {
          if (ls[x] <= rs[x]) {
            ps ~= tuple(ls[x], rs[x]);
          }
        }
        debug {
          writeln("ps = ", ps);
        }
        const psLen = cast(int)(ps.length);
        int last = -1;
        int mx;
        foreach (j; 0 .. psLen) {
          if (j == 0 || ps[j - 1][1] > ps[j][0]) {
            last = j;
          }
          chmax(mx, j - last + 1);
        }
        writeln(psLen - mx);
      }
    }
  } catch (EOFException e) {
  }
}