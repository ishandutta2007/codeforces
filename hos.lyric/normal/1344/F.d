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


enum MUL = [
  [0, 0, 0, 0],
  [0, 1, 2, 3],
  [0, 2, 3, 1],
  [0, 3, 1, 2],
];

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto typ = new string[K];
      auto mix = new string[K];
      auto M = new int[K];
      auto J = new int[][K];
      foreach (k; 0 .. K) {
        typ[k] = readToken();
        M[k] = readInt();
        J[k] = new int[M[k]];
        foreach (m; 0 .. M[k]) {
          J[k][m] = readInt() - 1;
        }
        if (typ[k] == "mix") {
          mix[k] = readToken();
        }
      }
      
      // F_2[X] / (1 + X + X^2)
      // W: 0, R: 1, Y: X, B: 1 + X
      // t -> fs[i] t^(2^gs[i])
      auto fs = new int[N];
      auto gs = new int[N];
      fs[] = 1;
      gs[] = 0;
      int aLen;
      auto a = new BitArray[K << 1];
      foreach (k; 0 .. K) {
        switch (typ[k]) {
          case "mix": {
            const num = "WRYB".indexOf(mix[k]);
            a[aLen + 0] = BitArray(new bool[N << 1 | 1]);
            a[aLen + 1] = BitArray(new bool[N << 1 | 1]);
            foreach (i; J[k]) {
              const p = (fs[i] >> 0) & 1;
              const q = (fs[i] >> 1) & 1;
              switch (gs[i]) {
                case 0: {
                  // (p + q X) (a + b X) = (p a + q b) + (q a + (p + q) b) X
                  a[aLen + 0][i << 1 | 0] = p;
                  a[aLen + 0][i << 1 | 1] = q;
                  a[aLen + 1][i << 1 | 0] = q;
                  a[aLen + 1][i << 1 | 1] = p ^ q;
                } break;
                case 1: {
                  // (p + q X) (a + b X)^2 = (p a + (p + q) b) + (q a + p b) X
                  a[aLen + 0][i << 1 | 0] = p;
                  a[aLen + 0][i << 1 | 1] = p ^ q;
                  a[aLen + 1][i << 1 | 0] = q;
                  a[aLen + 1][i << 1 | 1] = p;
                } break;
                default: assert(false);
              }
            }
            a[aLen + 0][N << 1] = (num >> 0) & 1;
            a[aLen + 1][N << 1] = (num >> 1) & 1;
            aLen += 2;
          } break;
          case "RY": {
            // 1 <-> X
            // t -> X t^2
            foreach (i; J[k]) {
              fs[i] = MUL[2][MUL[fs[i]][fs[i]]];
              gs[i] ^= 1;
            }
          } break;
          case "RB": {
            // 1 <-> 1 + X
            // t -> (1 + X) t^2
            foreach (i; J[k]) {
              fs[i] = MUL[3][MUL[fs[i]][fs[i]]];
              gs[i] ^= 1;
            }
          } break;
          case "YB": {
            // X <-> 1 + X
            // t -> t^2
            foreach (i; J[k]) {
              fs[i] = MUL[1][MUL[fs[i]][fs[i]]];
              gs[i] ^= 1;
            }
          } break;
          default: assert(false);
        }
      }
      a.length = aLen;
      debug {
        foreach (i; 0 .. aLen) {
          foreach (j; 0 .. (N << 1) + 1) {
            write(a[i][j] ? 1 : 0);
          }
          writeln();
        }
        writeln("----");
      }
      
      int r;
      int[] hs;
      foreach (h; 0 .. N << 1) {
        foreach (i; r .. aLen) {
          if (a[i][h]) {
            swap(a[r], a[i]);
            break;
          }
        }
        if (r < aLen && a[r][h]) {
          foreach (i; r + 1 .. aLen) {
            if (a[i][h]) {
              a[i] ^= a[r];
            }
          }
          ++r;
          hs ~= h;
        }
      }
      bool ok = true;
      foreach (i; r .. aLen) {
        ok = ok && !a[i][N << 1];
      }
      if (ok) {
        auto sol = new bool[N << 1];
        foreach_reverse (i; 0 .. r) {
          bool x = a[i][N << 1];
          foreach (j; hs[i] + 1 .. N << 1) {
            if (a[i][j] && sol[j]) {
              x = !x;
            }
          }
          sol[hs[i]] = x;
        }
        writeln("YES");
        foreach (i; 0 .. N) {
          write(".RYB"[cast(int)(sol[i << 1 | 0]) << 0 | cast(int)(sol[i << 1 | 1]) << 1]);
        }
        writeln();
      } else {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}