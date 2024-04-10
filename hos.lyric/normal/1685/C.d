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


enum FAIL = [-1];

int N;
string S;

int[] hs;
int im;

int[] solve0() {
  foreach (i; 0 .. 2 * N + 1) {
    if (hs[i] < 0) {
      return FAIL;
    }
  }
  return [];
}

int[] solve1() {
  int a = -1, b = -1;
  foreach         (i; 0 .. 2 * N + 1) if (hs[i] < 0) { a = i - 1; break; }
  foreach_reverse (i; 0 .. 2 * N + 1) if (hs[i] < 0) { b = i + 1; break; }
  assert(hs[a] == 0);
  assert(hs[b] == 0);
  debug {
    writeln("  a = ", a, ", b = ", b);
  }
  
  if (im <= a) return [im, 2 * N];
  if (b <= im) return [0, im];
  
  int am, bm;
  foreach (i; 0 .. a + 1)     if (hs[am] < hs[i]) am = i;
  foreach (i; b .. 2 * N + 1) if (hs[bm] < hs[i]) bm = i;
  debug {
    writeln("  am = ", am, ", bm = ", bm);
  }
  if (hs[am] + hs[bm] - hs[im] >= 0) {
    return [am, bm];
  }
  
  return FAIL;
}

int[] solve2() {
  return [0, im, im, 2 * N];
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        S = readToken;
        
        hs = new int[2 * N + 1];
        foreach (i; 0 .. 2 * N) {
          hs[i + 1] = hs[i] + ((S[i] == '(') ? +1 : -1);
        }
        im = 0;
        foreach (i; 0 .. 2 * N + 1) {
          if (hs[im] < hs[i]) {
            im = i;
          }
        }
        debug {
          writeln("  hs = ", hs);
          writeln("  im = ", im);
        }
        
        int[] ans;
        
        ans = solve0;
        if (ans != FAIL) {
          debug {
            writeln("  ", S);
          }
          writeln(0);
          continue;
        }
        ans = solve1;
        if (ans != FAIL) {
          debug {
            auto cs = S.dup;
            cs[ans[0] .. ans[1]].reverse;
            writeln("  ", cs);
          }
          writeln(1);
          writeln(ans[0] + 1, " ", ans[1]);
          continue;
        }
        ans = solve2;
        if (ans != FAIL) {
          debug {
            auto cs = S.dup;
            cs[ans[0] .. ans[1]].reverse;
            cs[ans[2] .. ans[3]].reverse;
            writeln("  ", cs);
          }
          writeln(2);
          writeln(ans[0] + 1, " ", ans[1]);
          writeln(ans[2] + 1, " ", ans[3]);
          continue;
        }
        
        assert(false);
      }
    }
  } catch (EOFException e) {
  }
}