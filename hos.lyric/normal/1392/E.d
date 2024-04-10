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




void main() {
  const N = readInt();
  
  auto board = new long[][](N, N);
  foreach (s; 1 .. 2 * N - 2) {
    foreach (x; 0 .. N) {
      const y = s - x;
      if (0 <= y && y < N) {
        board[x][y] = (cast(long)(x & 1)) << s;
      }
    }
  }
  foreach (x; 0 .. N) {
    board[x][N - 1 - x] = (cast(long)(x)) << (2 * N - 2);
  }
  foreach (x; 0 .. N) foreach (y; 0 .. N) {
    assert(0 <= board[x][y] && board[x][y] <= 10L^^16);
  }
  
  foreach (x; 0 .. N) {
    foreach (y; 0 .. N) {
      if (y > 0) write(" ");
      write(board[x][y]);
    }
    writeln;
  }
  stdout.flush;
  
  const Q = readInt();
  foreach (q; 0 .. Q) {
    const K = readLong();
    
    auto xs = new int[2 * N - 1];
    xs[0] = 0;
    xs[2 * N - 2] = N - 1;
    xs[N - 1] = cast(int)(K >> (2 * N - 2));
    foreach_reverse (s; 1 .. N - 1) {
      xs[s] = xs[s + 1];
      if ((xs[s] & 1) != ((K >> s) & 1)) {
        --xs[s];
      }
    }
    foreach (s; N .. 2 * N - 2) {
      xs[s] = xs[s - 1];
      if ((xs[s] & 1) != ((K >> s) & 1)) {
        ++xs[s];
      }
    }
    
    foreach (s; 0 .. 2 * N - 1) {
      writeln(xs[s] + 1, " ", (s - xs[s]) + 1);
    }
    stdout.flush;
    
    long k;
    foreach (s; 0 .. 2 * N - 1) {
      k += board[xs[s]][s - xs[s]];
    }
    assert(k == K);
  }
}