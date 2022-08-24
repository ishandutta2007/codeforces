import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex, std.typecons;
import core.bitop, core.thread;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return readToken().to!int; }
long readLong() { return readToken().to!long; }
real readReal() { return readToken().to!real; }

void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = cast(int)(as.length); for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a < val)); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a <= val)); }


immutable CS = "ACGT";

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
      auto rowCost = new int[][][](4, 4, M);
      auto colCost = new int[][][](4, 4, N);
      foreach (p; 0 .. 4) foreach (q; 0 .. 4) {
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          if (A[x][y] != CS[[p, q][y % 2]]) {
            ++rowCost[p][q][x];
          }
          if (A[x][y] != CS[[p, q][x % 2]]) {
            ++colCost[p][q][y];
          }
        }
      }
      int opt = M * N + 1;
      int[] permOpt;
      int dirOpt = -1;
      foreach (dir; 0 .. 2) {
        int[] perm = iota(4).array;
        do {
          int sum;
          if (dir == 0) {
            foreach (x; 0 .. M) {
              const p = perm[(x % 2) * 2 + 0];
              const q = perm[(x % 2) * 2 + 1];
              sum += min(rowCost[p][q][x], rowCost[q][p][x]);
            }
          } else {
            foreach (y; 0 .. N) {
              const p = perm[(y % 2) * 2 + 0];
              const q = perm[(y % 2) * 2 + 1];
              sum += min(colCost[p][q][y], colCost[q][p][y]);
            }
          }
          if (opt > sum) {
            opt = sum;
            permOpt = perm.dup;
            dirOpt = dir;
          }
        } while (perm.nextPermutation);
      }
      debug {
        writefln("opt = %s", opt);
        writefln("permOpt = %s", permOpt);
        writefln("dirOpt = %s", dirOpt);
      }
      auto ans = new char[][](M, N);
      if (dirOpt == 0) {
        foreach (x; 0 .. M) {
          int p = permOpt[(x % 2) * 2 + 0];
          int q = permOpt[(x % 2) * 2 + 1];
          if (rowCost[p][q][x] > rowCost[q][p][x]) {
            swap(p, q);
          }
          foreach (y; 0 .. N) {
            ans[x][y] = CS[[p, q][y % 2]];
          }
        }
      } else {
        foreach (y; 0 .. N) {
          int p = permOpt[(y % 2) * 2 + 0];
          int q = permOpt[(y % 2) * 2 + 1];
          if (colCost[p][q][y] > colCost[q][p][y]) {
            swap(p, q);
          }
          foreach (x; 0 .. M) {
            ans[x][y] = CS[[p, q][x % 2]];
          }
        }
      }
      int cnt;
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        if (A[x][y] != ans[x][y]) {
          ++cnt;
        }
      }
      assert(opt == cnt);
      foreach (x; 0 .. M) {
        foreach (y; 0 .. N) {
          write(ans[x][y]);
        }
        writeln();
      }
    }
  } catch (EOFException e) {
  }
}