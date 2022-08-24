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


enum A = 10;
enum DIGITS = ["1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"];

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto S = new string[N];
      foreach (i; 0 .. N) {
        S[i] = readToken();
      }
      
      auto dks = new int[][](N, A);
      foreach (i; 0 .. N) {
        foreach (a; 0 .. A) {
          foreach (pos; 0 .. 7) {
            if (S[i][pos] > DIGITS[a][pos]) {
              dks[i][a] += K + 1;
            } else if (S[i][pos] < DIGITS[a][pos]) {
              dks[i][a] += 1;
            }
          }
        }
      }
      auto dp = new bool[][](N + 1, K + 1);
      dp[N][0] = true;
      foreach_reverse (i; 0 .. N) {
        foreach (a; 0 .. A) {
          const dk = dks[i][a];
          foreach (k; dk .. K + 1) {
            if (dp[i + 1][k - dk]) {
              dp[i][k] = true;
            }
          }
        }
      }
      
      if (dp[0][K]) {
        string ans;
        int k = K;
        foreach (i; 0 .. N) {
          foreach_reverse (a; 0 .. A) {
            if (k >= dks[i][a] && dp[i + 1][k - dks[i][a]]) {
              ans ~= cast(char)('0' + a);
              k -= dks[i][a];
              goto found;
            }
          }
          assert(false);
         found:
        }
        writeln(ans);
      } else {
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}