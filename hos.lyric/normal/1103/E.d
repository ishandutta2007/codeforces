import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = cast(int)(as.length); for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a < val)); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a <= val)); }


// a^-1 (mod 2^64)
long modInv(long a)
in {
  assert(a & 1, "modInv: a must be odd");
}
do {
  long b = ((a << 1) + a) ^ 2;
  b *= 2 - a * b;
  b *= 2 - a * b;
  b *= 2 - a * b;
  b *= 2 - a * b;
  return b;
}


enum L = 10;
enum H = 5;
enum MO = 2L^^58;

alias Z = Tuple!(long, long, long, long);

Z add(in Z a, in Z b) {
  return Z(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

// 1 - X + X^2 - X^3 + X^4
Z mul(in Z a, in Z b) {
  Z c = Z(
    a[0] * b[0],
    a[0] * b[1] + a[1] * b[0],
    a[0] * b[2] + a[1] * b[1] + a[2] * b[0],
    a[0] * b[3] + a[1] * b[2] + a[2] * b[1] + a[3] * b[0],
  );
  long c4 = a[1] * b[3] + a[2] * b[2] + a[3] * b[1];
  long c5 = a[2] * b[3] + a[3] * b[2];
  long c6 = a[3] * b[3];
  c[2] -= c6; c[3] += c6; c4 -= c6; c5 += c6;
  c[1] -= c5; c[2] += c5; c[3] -= c5; c4 += c5;
  c[0] -= c4; c[1] += c4; c[2] -= c4; c[3] += c4;
  return c;
}

void main() {
  Z[] G = new Z[L + 1];
  G[0] = Z(1, 0, 0, 0);
  G[1] = Z(0, 1, 0, 0);
  foreach (i; 1 .. L + 1) {
    G[i] = mul(G[i - 1], G[1]);
  }
  debug {
    foreach (i; 0 .. L + 1) {
      writefln("G[%s] = %s", i, G[i]);
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      auto X = new int[N];
      foreach (n; 0 .. N) {
        X[n] = readInt();
      }
      Z[] a = new Z[L^^H];
      foreach (n; 0 .. N) {
        ++a[X[n]][0];
      }
      foreach (h; 0 .. H) {
        foreach (i; 0 .. L^^H) {
          if (i / L^^h % L == 0) {
            Z[] x = new Z[L];
            foreach (j; 0 .. L) {
              x[j] = a[i + L^^h * j];
            }
            Z[] y = new Z[L];
            foreach (j; 0 .. L) foreach (k; 0 .. L) {
              y[k] = add(y[k], mul(G[(j * k) % L], x[j]));
            }
            foreach (j; 0 .. L) {
              a[i + L^^h * j] = y[j];
            }
          }
        }
      }
      foreach (i; 0 .. L^^H) {
        Z b = a[i];
        a[i] = Z(1, 0, 0, 0);
        for (int e = N; e; e >>= 1) {
          if (e & 1) {
            a[i] = mul(a[i], b);
          }
          b = mul(b, b);
        }
      }
      foreach_reverse (h; 0 .. H) {
        foreach (i; 0 .. L^^H) {
          if (i / L^^h % L == 0) {
            Z[] x = new Z[L];
            foreach (j; 0 .. L) {
              x[j] = a[i + L^^h * j];
            }
            Z[] y = new Z[L];
            foreach (j; 0 .. L) foreach (k; 0 .. L) {
              y[k] = add(y[k], mul(G[L - (j * k) % L], x[j]));
            }
            foreach (j; 0 .. L) {
              a[i + L^^h * j] = y[j];
            }
          }
        }
      }
      foreach (n; 0 .. N) {
        assert(a[n][1] == 0);
        assert(a[n][2] == 0);
        assert(a[n][3] == 0);
        long ans = a[n][0];
        // ans /= L^H
        ans *= modInv(5^^H);
        assert(ans % 2^^H == 0);
        ans /= 2^^H;
        ans = (ans % MO + MO) % MO;
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}