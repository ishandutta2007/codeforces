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
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e; e >>= 1) {
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
  ModInt opUnary(string op)() const if (op == "-") { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op)(long a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  string toString() const { return x.to!string; }
}

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


enum L = 32;

uint addVector(uint p, int x) {
  uint pp = p;
  foreach (y; 0 .. L) {
    if (p & 1U << y) {
      pp |= 1U << (y ^ x);
    }
  }
  return pp;
}

int N, M;
int[] A, B, W;
int[][] G;

int[] dep, sums;
int[] cycs, cycs0;

void dfs(int u, int p, int d, int s) {
  debug {
    writeln("dfs ", u, " ", p, " ", d, " ", s);
  }
  dep[u] = d;
  sums[u] = s;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      if (dep[v] == -1) {
        dfs(v, u, d + 1, s ^ W[i]);
      } else {
        if (dep[u] > dep[v]) {
          debug {
            writeln("back edge ", u, " ", v, " ", (sums[u] ^ sums[v] ^ W[i]));
          }
          ((v == 0) ? cycs0 : cycs) ~= (sums[u] ^ sums[v] ^ W[i]);
        }
      }
    }
  }
  
}

void main() {
  int V;
  int[uint] ids;
  int[] ps;
  DList!int que;
  que ~= 1U << 0;
  for (; !que.empty; ) {
    const p = que.front;
    que.removeFront;
    foreach (x; 0 .. L) {
      const pp = addVector(p, x);
      if (pp !in ids) {
        ids[pp] = V++;
        ps ~= pp;
        que ~= pp;
      }
    }
  }
  auto add = new int[][](V + 1, V + 1);
  foreach (u; 0 .. V + 1) foreach (v; 0 .. V + 1) {
    add[u][v] = V;
  }
  foreach (u; 0 .. V) foreach (v; 0 .. V) {
    bool orth = true;
    int pp;
    foreach (x; 0 .. L) foreach (y; 0 .. L) {
      if ((ps[u] & 1U << x) && (ps[v] & 1U << y)) {
        pp |= 1U << (x ^ y);
        if (x != 0 && y != 0) {
          orth = orth && ((x ^ y) != 0);
        }
      }
    }
    if (orth) {
      assert(pp in ids);
      add[u][v] = ids[pp];
    }
  }
  debug {
    writeln("V = ", V);
    /*
    foreach (u; 0 .. V) {
      foreach (x; 0 .. L) {
        write((ps[u] >> x) & 1U);
      }
      writeln();
    }
    */
  }
  
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      W = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        W[i] = readInt();
      }
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      dep = new int[N];
      dep[] = -1;
      dep[0] = 0;
      sums = new int[N];
      int[] us, us1;
      foreach (i; G[0]) {
        const int v = A[i] ^ B[i] ^ 0;
        if (dep[v] == -1) {
          cycs = [];
          cycs0 = [];
          dfs(v, 0, 1, W[i]);
          debug {
            writeln("0 -> ", v, ": ", cycs, " ", cycs0);
          }
          
          uint q = 1U << 0;
          bool orth = true;
          foreach (cyc; cycs) {
            orth = orth && !(q & 1U << cyc);
            q = addVector(q, cyc);
          }
          foreach (cyc; cycs0) {
            orth = orth && !(q & 1U << cyc);
            q = addVector(q, cyc);
          }
          us ~= orth ? ids[q] : V;
          debug {
            write("q = ");
            foreach (x; 0 .. L) {
              write((q >> x) & 1U);
            }
            writeln();
          }
          
          if (cycs0) {
            uint q1 = 1U << 0;
            bool orth1 = true;
            foreach (cyc; cycs) {
              orth1 = orth1 && !(q1 & 1U << cyc);
              q1 = addVector(q1, cyc);
            }
            us1 ~= orth1 ? ids[q1] : V;
            debug {
              write("q1 = ");
              foreach (x; 0 .. L) {
                write((q1 >> x) & 1U);
              }
              writeln();
            }
          } else {
            us1 ~= -1;
          }
        }
      }
      debug {
        writeln("us = ", us);
        writeln("us1 = ", us1);
      }
      
      const len = cast(int)(us.length);
      auto dp = new Mint[][](len + 1, V + 1);
      dp[0][0] = 1;
      foreach (j; 0 .. len) {
        if (us1[j] != -1) {
          foreach (u; 0 .. V + 1) {
            dp[j + 1][u] += dp[j][u];
            dp[j + 1][add[u][us1[j]]] += dp[j][u] * 2;
            dp[j + 1][add[u][us[j]]] += dp[j][u];
          }
        } else {
          foreach (u; 0 .. V + 1) {
            dp[j + 1][u] += dp[j][u];
            dp[j + 1][add[u][us[j]]] += dp[j][u];
          }
        }
      }
      debug {
        foreach (j; 0 .. len + 1) {
          write(j);
          foreach (u; 0 .. V + 1) {
            if (dp[j][u].x != 0) {
              write(" ", u, ":", dp[j][u]);
            }
          }
          writeln();
        }
      }
      const ans = dp[len][0 .. V].sum;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}