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


enum LIM = 10^^6 + 10;
int[] lpf, moe;

int[int] factorize(long[] as) {
  int[int] ret;
  foreach (a; as) {
    int aa = cast(int)(a);
    for (; aa > 1; ) {
      const p = lpf[aa];
      ++ret[p];
      aa /= p;
    }
  }
  return ret;
}

void main() {
  lpf = iota(LIM).array;
  moe = new int[LIM];
  moe[1 .. $] = 1;
  foreach (p; 2 .. LIM) {
    if (lpf[p] == p) {
      moe[p] *= -1;
      for (int n = 2 * p; n < LIM; n += p) {
        chmin(lpf[n], p);
        moe[n] *= -1;
        if (n / p % p == 0) {
          moe[n] = 0;
        }
      }
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        auto N = new long[3];
        foreach (i; 0 .. 3) {
          N[i] = readInt();
        }
        auto M = new long[3];
        foreach (i; 0 .. 3) {
          M[i] = readInt();
        }
        auto S = new long[3];
        foreach (i; 0 .. 3) {
          S[i] = readInt();
        }
        
        const MM = M[0] * M[1] * M[2];
        const NN = N[0] * N[1] * N[2];
        const SS = S[0] * S[1] * S[2];
        const ns = factorize(N);
        const ss = factorize(S ~ [2L]);
        debug {
          writeln("ns = ", ns);
          writeln("ss = ", ss);
        }
        
        long ansX, ansY;
        
        {
          int len;
          int[] ps, es, fs;
          foreach (p, e; ns) {
            ps ~= p;
            es ~= e;
            fs ~= (p in ss) ? ss[p] : 0;
            ++len;
          }
          debug {
            writeln("ps = ", ps);
            writeln("es = ", es);
            writeln("fs = ", fs);
          }
          void dfsN(int i, long m, long s) {
            if (i == len) {
              ansX += m * s;
            } else {
              // 0 <= v_p(d e) <= es[i]
              long mm = m;
              foreach (j; 0 .. es[i] + 1) {
                // 0 <= v_p(d) <= fs[i], 0 <= v_p(e) <= 1
                long ss;
                if (j <= fs[i]) {
                  ss += s;
                }
                if (0 <= j - 1 && j - 1 <= fs[i]) {
                  ss -= s;
                }
                if (mm != 0 && ss != 0) {
                  dfsN(i + 1, mm, ss);
                }
                mm /= ps[i];
              }
            }
          }
          dfsN(0, MM, 1);
        }
        
        {
          int len;
          int[] ps, es;
          foreach (p, e; ss) {
            ps ~= p;
            es ~= e;
            ++len;
          }
          void dfsS(int i, long n) {
            if (n == 0) {
              return;
            } else if (i == len) {
              ++ansY;
            } else {
              long nn = n;
              foreach (j; 0 .. es[i] + 1) {
                dfsS(i + 1, nn);
                nn /= ps[i];
              }
            }
          }
          dfsS(0, NN);
        }
        
        writeln(ansX + ansY);
        
        debug {
          writefln("%s %s %s: ans %s %s", MM, NN, SS, ansX, ansY);
          
          // \sum_{d|n, d|2s} \sum_{e|n/d} \mu(e) [m / (d e)]
          long slwX;
          foreach (d; 1 .. NN + 1) {
            if (NN % d == 0 && (2 * SS) % d == 0) {
              foreach (e; 1 .. NN / d + 1) {
                if ((NN / d) % e == 0) {
                  slwX += moe[cast(int)(e)] * (MM / (d * e));
                }
              }
            }
          }
          writefln("%s %s %s: slw %s", MM, NN, SS, slwX);
          
          long brtX, brtY;
          foreach (x; 1 .. MM + 1) {
            if ((2 * SS) % gcd(x, NN) == 0) {
              ++brtX;
            }
          }
          foreach (y; 1 .. NN + 1) {
            if ((2 * SS) % y == 0) {
              ++brtY;
            }
          }
          writefln("%s %s %s: brt %s %s", MM, NN, SS, brtX, brtY);
        }
      }
    }
  } catch (EOFException e) {
  }
}