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


int N;
debug {
  string[] A;
}

bool Ask(int x0, int y0, int x1, int y1) {
  assert((x1 - x0) + (y1 - y0) >= N - 1);
  bool ret;
  debug {
    if (A[x0][y0] == '.' && A[x1][y1] == '.') {
      auto dp = new bool[][](N, N);
      dp[x0][y0] = true;
      foreach (x; 0 .. N) foreach (y; 0 .. N) {
        if (dp[x][y]) {
          if (x + 1 < N && A[x + 1][y] == '.') {
            dp[x + 1][y] = true;
          }
          if (y + 1 < N && A[x][y + 1] == '.') {
            dp[x][y + 1] = true;
          }
        }
      }
      ret = dp[x1][y1];
      writefln("Ask %s %s %s %s = %s", x0, y0, x1, y1, ret);
    } else {
      ret = false;
    }
  } else {
    writefln("? %s %s %s %s", x0 + 1, y0 + 1, x1 + 1, y1 + 1);
    stdout.flush;
    ret = (readToken() == "YES");
  }
  return ret;
}

void main() {
  N = readInt();
  debug {
    A = new string[N];
    foreach (x; 0 .. N) {
      A[x] = readToken();
    }
  }
  
  auto diagS = new bool[N];
  auto diagT = new bool[N];
  foreach (x; 0 .. N) {
    diagS[x] = Ask(0, 0, x, N - 1 - x);
    diagT[x] = Ask(x, N - 1 - x, N - 1, N - 1);
  }
  int xm = -1;
  foreach (x; 0 .. N) {
    if (diagS[x] && diagT[x]) {
      xm = x;
      break;
    }
  }
  debug {
    writeln("diagS = ", diagS);
    writeln("diagT = ", diagT);
    writeln("xm = ", xm);
  }
  
  string ansS, ansT;
  for (int x = 0, y = 0; !(x == xm && y == N - 1 - xm); ) {
    if (y + 1 <= N - 1 - xm && Ask(x, y + 1, N - 1, N - 1)) {
      ++y;
      ansS = ansS ~ 'R';
    } else {
      ++x;
      ansS = ansS ~ 'D';
    }
  }
  for (int x = N - 1, y = N - 1; !(x == xm && y == N - 1 - xm); ) {
    if (x - 1 >= xm && Ask(0, 0, x - 1, y)) {
      --x;
      ansT = 'D' ~ ansT;
    } else {
      --y;
      ansT = 'R' ~ ansT;
    }
  }
  
  writefln("! %s%s", ansS, ansT);
  stdout.flush;
}