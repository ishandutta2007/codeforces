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
  try {
    for (; ; ) {
      const M = readInt();
      const N = readInt();
      auto A = new string[M];
      foreach (x; 0 .. M) {
        A[x] = readToken();
      }
      const S = readToken();
      
      int sx, sy;
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        if (A[x][y] == 'S') {
          sx = x;
          sy = y;
        }
      }
      
      int ans;
      auto perm = iota(4).array;
      do {
        bool ok;
        int x = sx, y = sy;
        foreach (s; S) {
          const dir = perm[s - '0'];
          const xx = x + [+1, 0, -1, 0][dir];
          const yy = y + [0, -1, 0, +1][dir];
          if (0 <= xx && xx < M && 0 <= yy && yy < N && A[xx][yy] != '#') {
            x = xx;
            y = yy;
            if (A[x][y] == 'E') {
              ok = true;
              break;
            }
          } else {
            break;
          }
        }
        if (ok) {
          ++ans;
        }
      } while (perm.nextPermutation);
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}