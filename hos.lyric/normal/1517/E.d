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


struct ModInt(int M_) {
  import std.conv : to;
  alias M = M_;
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
    else static if (op == "/") { this *= a.inv(); }
    else static assert(false);
    return this;
  }
  ref ModInt opOpAssign(string op)(long a) {
    static if (op == "^^") {
      if (a < 0) return (this = inv()^^(-a));
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e > 0; e >>= 1) {
        if (e & 1) te *= t2;
        t2 *= t2;
      }
      x = cast(int)(te.x);
      return this;
    } else return mixin("this " ~ op ~ "= ModInt(a)");
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  ModInt opUnary(string op: "-")() const { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const {
    return mixin("ModInt(this) " ~ op ~ "= a");
  }
  ModInt opBinaryRight(string op)(long a) const {
    return mixin("ModInt(a) " ~ op ~ "= this");
  }
  bool opCast(T: bool)() const { return (x != 0); }
  string toString() const { return x.to!string; }
}

enum MO = 998244353;
alias Mint = ModInt!MO;


void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


void main() {
  debug {
    foreach (n; 1 .. 10 + 1) {
      int cnt;
      auto brt = new int[1 << n];
      foreach (p; 0 .. 1 << n) {
        int[][2] seqs;
        foreach (i; 0 .. n) {
          seqs[(p >> i) & 1] ~= i;
        }
        bool ok = true;
        foreach (j; 1 .. cast(int)(seqs[0].length) - 1) {
          ok = ok && (seqs[0][j] - seqs[0][j - 1] <= seqs[0][j + 1] - seqs[0][j]);
        }
        foreach (j; 1 .. cast(int)(seqs[1].length) - 1) {
          ok = ok && (seqs[1][j] - seqs[1][j - 1] >= seqs[1][j + 1] - seqs[1][j]);
        }
        if (ok) {
          int[2] mns = [n, n], mxs = [-1, -1];
          foreach (i; 0 .. n) {
            chmin(mns[(p >> i) & 1], i);
            chmax(mxs[(p >> i) & 1], i);
          }
          foreach (i; 0 .. n) {
            write((p >> i) & 1);
          }
          writeln(" ", seqs, " ", mns, " ", mxs);
          ++cnt;
          ++brt[p];
        }
      }
      writefln("n = %s: %s", n, cnt);
      stdout.flush;
      
      // s 0...0 01...01 1...1 t
      if (n >= 2) {
        auto grd = new int[1 << n];
        foreach (i; 0 .. n + 1) {
          ++grd[(1 << i) - 1];
        }
        foreach (i; 0 .. n + 1) for (int j = i + 2; j <= n; j += 2) {
          foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
            if (i == 0 && s == 1) continue;
            if (j == n && t == 0) continue;
            int p;
            for (int k = i + 1; k < j; k += 2) p |= 1 << k;
            foreach (k; j .. n) p |= 1 << k;
            p &= ~(1 << 0);
            p &= ~(1 << (n - 1));
            p |= s << 0;
            p |= t << (n - 1);
            ++grd[p];
          }
        }
        writeln(brt);
        writeln(grd);
        stdout.flush;
        assert(brt == grd);
      }
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new long[N];
        foreach (i; 0 .. N) {
          A[i] = readLong();
        }
        
        auto ASum = new long[N + 1];
        foreach (i; 0 .. N) {
          ASum[i + 1] = ASum[i] + A[i];
        }
        auto B0Sum = new long[N + 1];
        auto B1Sum = new long[N + 1];
        foreach (i; 0 .. N) {
          B0Sum[i + 1] = B1Sum[i];
          B1Sum[i + 1] = B0Sum[i] + A[i];
        }
        
        Mint ans;
        
        if (N == 1) {
          ans += 1;
        } else {
          // no 01
          foreach (i; 0 .. N + 1) {
            if (ASum[N] - ASum[i] < ASum[i]) {
              ans += 1;
            }
          }
          // [0, N)
          if (N % 2 == 0) {
            if (B0Sum[N] < B1Sum[N]) {
              ans += 1;
            }
          }
          // [0, *)
          for (int j = 2; j < N; j += 2) {
            if (B0Sum[j] + A[N - 1] < B1Sum[j] + (ASum[N - 1] - ASum[j])) {
              ans += 1;
            }
            if (B0Sum[j] < B1Sum[j] + (ASum[N - 1] - ASum[j]) + A[N - 1]) {
              ans += 1;
            }
          }
          // [*, N)
          for (int i = N - 2; i > 0; i -= 2) {
            if (A[0] + (ASum[i] - ASum[1]) + (B0Sum[N] - B0Sum[i]) < (B1Sum[N] - B1Sum[i])) {
              ans += 1;
            }
            if ((ASum[i] - ASum[1]) + (B0Sum[N] - B0Sum[i]) < A[0] + (B1Sum[N] - B1Sum[i])) {
              ans += 1;
            }
          }
          // [*, *)
          foreach (i0; [1, 2]) {
            foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
              /*
                d - A[1, i) - B0[i, j) + B1[i, j) + A[j, N - 1)
                = d - ASum[i] + ASum[1] - B0Sum[j] + B0Sum[i] + B1Sum[j] - B1Sum[i] + ASum[N - 1] - ASum[j]
                = (d + ASum[1] + ASum[N - 1]) + (- ASum[i] + B0Sum[i] - B1Sum[i]) + (- B0Sum[j] + B1Sum[j] - ASum[j])
                
                d + f + g > 0
                g > -(d + f)
              */
              long d;
              (s == 0) ? (d -= A[0]) : (d += A[0]);
              (t == 0) ? (d -= A[N - 1]) : (d += A[N - 1]);
              d += ASum[1];
              d += ASum[N - 1];
              auto fs = new long[N + 1];
              auto gs = new long[N + 1];
              for (int i = i0; i < N; i += 2) {
                fs[i] -= ASum[i];
                fs[i] += B0Sum[i];
                fs[i] -= B1Sum[i];
                fs[i] = -(d + fs[i]);
              }
              for (int j = i0; j < N; j += 2) {
                gs[j] -= B0Sum[j];
                gs[j] += B1Sum[j];
                gs[j] -= ASum[j];
              }
              debug {
                writeln(i0, " ", s, " ", t, " ", fs, " ", gs);
              }
              long[] xs = fs ~ gs;
              xs = xs.sort.uniq.array;
              const xsLen = cast(int)(xs.length);
              auto bit = new int[xsLen];
              for (int i = i0; i < N; i += 2) {
                ans += bit.bSum(xs.lowerBound(gs[i]));
                bit.bAdd(xs.lowerBound(fs[i]), 1);
              }
            }
          }
        }
        
        debug {
          const n = N;
          auto grd = new int[1 << n];
          if (n <= 2) {
            grd[] = 1;
          } else {
            foreach (i; 0 .. n + 1) {
              ++grd[(1 << i) - 1];
            }
            foreach (i; 0 .. n + 1) for (int j = i + 2; j <= n; j += 2) {
              foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
                if (i == 0 && s == 1) continue;
                if (j == n && t == 0) continue;
                int p;
                for (int k = i + 1; k < j; k += 2) p |= 1 << k;
                foreach (k; j .. n) p |= 1 << k;
                p &= ~(1 << 0);
                p &= ~(1 << (n - 1));
                p |= s << 0;
                p |= t << (n - 1);
                ++grd[p];
              }
            }
          }
          auto sums = new long[1 << n];
          foreach (i; 0 .. n) {
            foreach (p; 0 .. 1 << i) {
              sums[p | 1 << i] = sums[p] + A[i];
            }
          }
          int brt;
          foreach (p; 0 .. 1 << n) {
            if (grd[p]) {
              if (sums[$ - 1] - sums[p] < sums[p]) {
                debug {
                  write("ok ");
                  foreach (i; 0 .. n) {
                    write((p >> i) & 1);
                  }
                  writeln;
                }
                ++brt;
              }
            }
          }
          writeln("brt = ", brt);
          assert(brt == ans.x);
        }
        
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}