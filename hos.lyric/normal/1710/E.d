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


int M, N;
int[] A, B;
int A0, B0;
int X0, Y0;

bool alice(int tar) {
  auto fs = new int[M + 1];
  auto gs = new int[N + 1];
  for (int x = 0, y = N; !(x == M && y == 0); ) {
    if (y == 0 || (x < M && A[x] + B[y - 1] <= tar)) {
      fs[x++] = y;
    } else {
      gs[--y] = x;
    }
  }
  auto fsSum = new long[M + 1];
  foreach (x; 0 .. M) {
    fsSum[x + 1] = fsSum[x] + fs[x];
  }
  
  debug {
    writeln("tar = ", tar);
    foreach (x; 0 .. M) {
      write("  ");
      foreach (y; 0 .. N) {
        write((x == X0 && y == Y0) ? '@' : (A[x] + B[y] <= tar) ? '1' : '0');
      }
      writeln;
    }
    writeln("  fs = ", fs);
    writeln("  gs = ", gs);
  }
  
  alias Entry = Tuple!(long, "ind", bool, "without");
  Entry mx = Entry(-1, false);
  
  // 1 in [0, x) [0, y) and 0 in [x, M) [y, N)
  Entry cut(int x, int y) {
    assert(0 <= x); assert(x <= M);
    assert(0 <= y); assert(y <= N);
    Entry ret;
    if (y < fs[x]) {
      ret.ind += 1L * x * y;
      ret.ind += 1L * (M - x) * (N - y);
      ret.ind -= ((fsSum[gs[y]] - fsSum[x]) - 1L * (gs[y] - x) * y);
    } else {
      ret.ind += 1L * gs[y] * y;
      ret.ind += (fsSum[x] - fsSum[gs[y]]);
      ret.ind += 1L * (M - x) * (N - y);
    }
    ret.without = !(x <= X0 && y <= Y0);
    debug {
      writefln("  cut %s %s = %s", x, y, ret);
    }
    chmax(mx, ret);
    return ret;
  }
  
  {
    int y;
    foreach (x; 0 .. M + 1) {
      Entry now = cut(x, y);
      for (; y < N; ) {
        const res = cut(x, y + 1);
        if (now <= res) {
          now = res;
          ++y;
        } else {
          break;
        }
      }
    }
  }
  
  // every matching has (X0, Y0) <=> there exists max ind set without (X0, Y0)
  return mx.without;
}

void main() {
  try {
    for (; ; ) {
      M = readInt;
      N = readInt;
      A = new int[M];
      foreach (x; 0 .. M) A[x] = readInt;
      B = new int[N];
      foreach (y; 0 .. N) B[y] = readInt;
      
      A0 = A[0];
      B0 = B[0];
      A.sort;
      B.sort;
      X0 = A.lowerBound(A0);
      Y0 = B.lowerBound(B0);
      debug {
        writefln("A = %s, X0 = %s", A, X0);
        writefln("B = %s, Y0 = %s", B, Y0);
      }
      
      int lo = A[0] + B[0] - 1, hi = A0 + B0;
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        (alice(mid) ? hi : lo) = mid;
      }
      writeln(hi);
    }
  } catch (EOFException e) {
  }
}