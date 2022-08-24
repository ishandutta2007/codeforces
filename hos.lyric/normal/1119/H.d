import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum long MO = 998244353;
enum M = 3;

int N, K;
long[] X;
int[][] A;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      X = new long[M];
      foreach (m; 0 .. M) {
        X[m] = readLong();
      }
      A = new int[][](N, M);
      foreach (i; 0 .. N) {
        foreach (m; 0 .. M) {
          A[i][m] = readInt();
        }
      }
      
      // pw[p][j] := ((-1)^p[0] X[0] + ... + (-1)^p[M-1] X[M-1])^j
      auto pw = new long[][](1 << M, N + 1);
      foreach (p; 0 .. 1 << M) {
        pw[p][0] = 1;
        pw[p][1] = 0;
        foreach (m; 0 .. M) {
          pw[p][1] += (((p >> m) & 1) ? -1 : +1) * X[m];
          pw[p][1] %= MO;
        }
        foreach (j; 2 .. N + 1) {
          pw[p][j] = (pw[p][j - 1] * pw[p][1]) % MO;
        }
      }
      
      // d[p] := Sum_i (-1)^<v, XOR{A[i][m] | m in p}>
      auto d = new int[][](1 << M, 1 << K);
      foreach (p; 0 .. 1 << M) {
        foreach (i; 0 .. N) {
          int v;
          foreach (m; 0 .. M) {
            if ((p >> m) & 1) {
              v ^= A[i][m];
            }
          }
          ++d[p][v];
        }
        
        // Hadamard d[p]
        foreach (k; 0 .. K) {
          foreach (v; 0 .. 1 << K) {
            const w = v ^ 1 << k;
            if (v < w) {
              const tmpV = d[p][v];
              const tmpW = d[p][w];
              d[p][v] = tmpV + tmpW;
              d[p][w] = tmpV - tmpW;
            }
          }
        }
      }
      
      auto f = new long[1 << K];
      foreach (v; 0 .. 1 << K) {
        auto e = new int[1 << M];
        foreach (p; 0 .. 1 << M) {
          e[p] = d[p][v];
        }
        
        // Hadamard e
        foreach (m; 0 .. M) {
          foreach (p; 0 .. 1 << M) {
            const q = p ^ 1 << m;
            if (p < q) {
              const tmpP = e[p];
              const tmpQ = e[q];
              e[p] = tmpP + tmpQ;
              e[q] = tmpP - tmpQ;
            }
          }
        }
        
        foreach (p; 0 .. 1 << M) {
          e[p] >>= M;
        }
        // e[p] := #{i | <v, A[i][m]> = p[m]}
        debug {
          writefln("v = %s: e = %s", v, e);
        }
        f[v] = 1;
        foreach (p; 0 .. 1 << M) {
          f[v] *= pw[p][e[p]];
          f[v] %= MO;
        }
      }
      
      // Hadamard f
      foreach (k; 0 .. K) {
        foreach (v; 0 .. 1 << K) {
          const w = v ^ 1 << k;
          if (v < w) {
            const tmpV = f[v];
            const tmpW = f[w];
            f[v] = (tmpV + tmpW) % MO;
            f[w] = (tmpV - tmpW) % MO;
          }
        }
      }
      
      // 2^(-K)
      const INV2 = (1 + MO) / 2;
      long INV2K = 1;
      foreach (_; 0 .. K) {
        INV2K *= INV2;
        INV2K %= MO;
      }
      foreach (v; 0 .. 1 << K) {
        f[v] *= INV2K;
        f[v] %= MO;
      }
      
      foreach (v; 0 .. 1 << K) {
        f[v] = (f[v] % MO + MO) % MO;
        if (v > 0) {
          write(" ");
        }
        write(f[v]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}