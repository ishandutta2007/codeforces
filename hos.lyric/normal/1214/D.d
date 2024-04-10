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



enum K = 1;
enum MOS = [987654323, 998244353, 10^^9 + 7, 10^^9 + 9];

void add(int k, ref int t, in int f) {
  if ((t += f) >= MOS[k]) {
    t -= MOS[k];
  }
}

int M, N;
string[] A;

void main() {
  try {
    for (; ; ) {
      M = readInt();
      N = readInt();
      A = new string[M];
      foreach (x; 0 .. M) {
        A[x] = readToken();
      }
      
      auto dpS = new int[][][](K, M, N);
      auto dpT = new int[][][](K, M, N);
      foreach (k; 0 .. K) {
        dpS[k][0][0] = 1;
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          if (A[x][y] == '.') {
            if (x + 1 < M && A[x + 1][y] == '.') {
              add(k, dpS[k][x + 1][y], dpS[k][x][y]);
            }
            if (y + 1 < N && A[x][y + 1] == '.') {
              add(k, dpS[k][x][y + 1], dpS[k][x][y]);
            }
          }
        }
        dpT[k][M - 1][N - 1] = 1;
        foreach_reverse (x; 0 .. M) foreach_reverse (y; 0 .. N) {
          if (A[x][y] == '.') {
            if (x - 1 >= 0 && A[x - 1][y] == '.') {
              add(k, dpT[k][x - 1][y], dpT[k][x][y]);
            }
            if (y - 1 >= 0 && A[x][y - 1] == '.') {
              add(k, dpT[k][x][y - 1], dpT[k][x][y]);
            }
          }
        }
      }
      
      int ans;
      
      bool zero = true;
      foreach (k; 0 .. K) {
        zero = zero && (dpT[k][0][0] == 0);
      }
      if (zero) {
        ans = 0;
      } else {
        ans = 2;
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          if (A[x][y] == '.' && !(x == 0 && y == 0) && !(x == M - 1 && y == N - 1)) {
            bool all = true;
            foreach (k; 0 .. K) {
              all = all && (dpT[k][0][0] == (1L * dpS[k][x][y] * dpT[k][x][y]) % MOS[k]);
            }
            if (all) {
              debug {
                writeln("block ", x, " ", y);
              }
              ans = 1;
            }
          }
        }
      }
      
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}