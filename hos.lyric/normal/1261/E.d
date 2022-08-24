import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


char[][] solve(int[] A) {
  const N = cast(int)(A.length);
  auto ans = new char[][](N + 1, N);
  auto used = new bool[N];
  auto xss = [iota(N + 1).array];
  foreach (h; 0 .. N) {
    int im = -1;
    foreach (i; 0 .. N) {
      if (!used[i]) {
        if (im == -1 || A[im] < A[i]) {
          im = i;
        }
      }
    }
    used[im] = true;
    debug {
      writeln("xss = ", xss);
      writeln("im = ", im);
    }
    const xssLen = cast(int)(xss.length);
    auto ls = new int[xssLen];
    foreach (j; 0 .. xssLen) {
      ls[j] = cast(int)(xss[j].length);
    }
    int numLarge;
    foreach (j; 0 .. xssLen) {
      if (ls[j] >= 2) {
        ++numLarge;
      }
    }
    auto ms = new int[xssLen];
    if (A[im] <= numLarge) {
      ms[0 .. A[im]] = 1;
    } else if (N + 1 - A[im] <= numLarge) {
      ms[] = ls[];
      ms[0 .. (N + 1 - A[im])] -= 1;
    } else {
      int a = A[im] - numLarge;
      ms[0 .. numLarge] = 1;
      foreach (j; 0 .. numLarge) {
        const tmp = min(a, ls[j] - 2);
        a -= tmp;
        ms[j] += tmp;
      }
      foreach (j; numLarge .. xssLen) {
        const tmp = min(a, ls[j]);
        a -= tmp;
        ms[j] += tmp;
      }
      assert(a == 0);
    }
    debug {
      writeln("  ms = ", ms);
    }
    int[][] xssNext;
    foreach (j; 0 .. xssLen) {
      foreach (x; xss[j][0 .. ms[j]]) {
        ans[x][im] = '1';
      }
      foreach (x; xss[j][ms[j] .. ls[j]]) {
        ans[x][im] = '0';
      }
      if (0 < ms[j]) {
        xssNext ~= xss[j][0 .. ms[j]];
      }
      if (ms[j] < ls[j]) {
        xssNext ~= xss[j][ms[j] .. ls[j]];
      }
    }
    xss = xssNext;
    xss.sort!"a.length > b.length";
  }
  return ans;
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      const ans = solve(A);
      writeln(ans.length);
      foreach (row; ans) {
        writeln(row);
      }
    }
  } catch (EOFException e) {
  }
}