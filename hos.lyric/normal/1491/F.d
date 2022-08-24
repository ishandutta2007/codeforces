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


int N;
debug {
  string A;
  int numAsks;
}

int Ask(int[] xs, int[] ys) {
  writefln("? %s %s", xs.length, ys.length);
  foreach (index, x; xs) {
    if (index > 0) write(" ");
    write(x + 1);
  }
  writeln;
  foreach (index, y; ys) {
    if (index > 0) write(" ");
    write(y + 1);
  }
  writeln;
  stdout.flush;
  int ret;
  debug {
    ++numAsks;
    assert(numAsks <= N + bsr(N));
    int l, r;
    foreach (x; xs) {
      if (A[x] == 'N') ++l;
      if (A[x] == 'S') --l;
    }
    foreach (y; ys) {
      if (A[y] == 'N') ++r;
      if (A[y] == 'S') --r;
    }
    ret = l * r;
    writefln("%s %s: %s * %s = %s", xs, ys, l, r, ret);
    assert(abs(ret) <= N);
  } else {
    ret = readInt();
  }
  return ret;
}

void Answer(int[] zs) {
  zs.sort;
  writef("! %s", zs.length);
  foreach (z; zs) {
    write(" ", z + 1);
  }
  writeln;
  stdout.flush;
  debug {
    assert(A.count('-') == zs.length);
    foreach (z; zs) {
      assert(A[z] == '-');
    }
  }
}

void solve() {
  int[] ans;
  foreach (k; 1 .. N) {
    if (Ask(iota(k).array, [k]) != 0) {
      int lo = 0, hi = k;
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        if (Ask(iota(lo, mid).array, [k]) != 0) {
          hi = mid;
        } else {
          lo = mid;
        }
      }
      foreach (i; 0 .. k) {
        if (i != lo) {
          ans ~= i;
        }
      }
      foreach (i; k + 1 .. N) {
        if (Ask([k], [i]) == 0) {
          ans ~= i;
        }
      }
      break;
    }
  }
  Answer(ans);
}

void main() {
  const numCases = readInt();
  foreach (caseId; 0 .. numCases) {
    N = readInt();
    debug {
      A = readToken();
    }
    solve();
  }
}