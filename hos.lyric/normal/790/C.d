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


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const S = readToken();
      
      int[] ks, vs, os;
      foreach (i; 0 .. N) {
        switch (S[i]) {
          case 'K': ks ~= i; break;
          case 'V': vs ~= i; break;
          default: os ~= i;
        }
      }
      const ksLen = cast(int)(ks.length);
      const vsLen = cast(int)(vs.length);
      const osLen = cast(int)(os.length);
      debug {
        writeln("ks = ", ks);
        writeln("vs = ", vs);
        writeln("os = ", os);
      }
      
      auto costO = new int[][][](osLen + 1, ksLen + 1, vsLen + 1);
      auto costK = new int[][][](osLen + 1, ksLen + 1, vsLen + 1);
      auto costV = new int[][][](osLen + 1, ksLen + 1, vsLen + 1);
      foreach (i; 0 .. osLen + 1) foreach (x; 0 .. ksLen + 1) foreach (y; 0 .. vsLen + 1) {
        if (i < osLen) {
          foreach (xx; 0 .. x) if (ks[xx] > os[i]) ++costO[i][x][y];
          foreach (yy; 0 .. y) if (vs[yy] > os[i]) ++costO[i][x][y];
        }
        if (x < ksLen) {
          foreach (ii; 0 .. i) if (os[ii] > ks[x]) ++costK[i][x][y];
          foreach (yy; 0 .. y) if (vs[yy] > ks[x]) ++costK[i][x][y];
        }
        if (y < vsLen) {
          foreach (ii; 0 .. i) if (os[ii] > vs[y]) ++costV[i][x][y];
          foreach (xx; 0 .. x) if (ks[xx] > vs[y]) ++costV[i][x][y];
        }
      }
      
      auto dp = new int[][][](osLen + 2, ksLen + 1, vsLen + 1);
      foreach (i; 0 .. osLen + 2) {
        foreach (x; 0 .. ksLen + 1) foreach (y; 0 .. vsLen + 1) {
          dp[i][x][y] = INF;
        }
      }
      dp[0][0][0] = 0;
      foreach (i; 0 .. osLen + 1) {
        foreach (x; 0 .. ksLen + 1) foreach (y; 0 .. vsLen + 1) {
          if (dp[i][x][y] < INF) {
            int cK = dp[i][x][y];
            foreach (xx; x .. ksLen + 1) {
              int cKV = cK;
              foreach (yy; y .. vsLen + 1) {
                int cc = cKV;
                if (i < osLen) {
                  cc += costO[i][xx][yy];
                }
                chmin(dp[i + 1][xx][yy], cc);
                if (yy < vsLen) {
                  cKV += costV[i][xx][yy];
                }
              }
              if (xx < ksLen) {
                cK += costK[i][xx][y];
              }
            }
          }
        }
      }
      debug {
        foreach (i; 0 .. osLen + 2) {
          writefln("dp[%s] = %s", i, dp[i]);
        }
      }
      
      const ans = dp[osLen + 1][ksLen][vsLen];
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}