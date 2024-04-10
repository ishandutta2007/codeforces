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

enum MO = 998244353;
alias Mint = ModInt!MO;

int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}

int N;
long[] X, V;
Mint[] P;

struct Info {
  Mint p, q, s;
  Info opBinary(string op)(ref const(Info) a) const if (op == "*") {
    return Info(p * a.p, q * a.q, s * a.p + q * a.s - q * a.p);
  }
}
enum IDENTITY = Info(Mint(1), Mint(1), Mint(1));
int segN;
Info[] seg;
Info get(int a, int b) {
  Info retL = IDENTITY;
  Info retR = IDENTITY;
  ++b;
  for (a += segN, b += segN; a < b; a >>= 1, b >>= 1) {
    if (a & 1) retL = retL * seg[a++];
    if (b & 1) retR = seg[--b] * retR;
  }
  return retL * retR;
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      X = new long[N];
      V = new long[N];
      P = new Mint[N];
      foreach (i; 0 .. N) {
        X[i] = readLong();
        V[i] = readLong();
        P[i] = Mint(readLong()) / 100;
      }
      
      for (segN = 1; segN < N; segN <<= 1) {}
      seg = new Info[segN << 1];
      seg[] = IDENTITY;
      foreach (i; 0 .. N) {
        seg[segN + i] = Info(P[i], Mint(1) - P[i], Mint(1));
      }
      foreach_reverse (a; 1 .. segN) {
        seg[a] = seg[a << 1] * seg[a << 1 | 1];
      }
      debug {
        foreach (i; 0 .. N) foreach (j; i .. N) {
          writeln(i, " ", j, ": ", get(i, j));
        }
      }
      
      alias Entry = Tuple!(long, "tp", long, "tq", int, "i", int, "typ");
      Entry[] es;
      foreach (i; 0 .. N - 1) {
        es ~= Entry(X[i + 1] - X[i], V[i] + V[i + 1], i, 0);
        if (V[i] > V[i + 1]) {
          es ~= Entry(X[i + 1] - X[i], V[i] - V[i + 1], i, +1);
        }
        if (V[i] < V[i + 1]) {
          es ~= Entry(X[i + 1] - X[i], V[i + 1] - V[i], i, -1);
        }
      }
      es.sort!((ea, eb) => (ea.tp * eb.tq < eb.tp * ea.tq));
      
      auto uf = new int[N];
      uf[] = -1;
      /*
        l       r
        o-o-o-o-o
        < <     >
          ll    rr
      */
      auto ls = iota(N).array;
      auto rs = iota(N).array;
      auto lls = new int[N];
      auto rrs = new int[N];
      lls[] = -1;
      rrs[] = N;
      Mint calc(int l, int ll, int rr, int r) {
        chmax(ll, l - 1);
        chmin(rr, r + 1);
        return get(l, ll).q * get(ll + 1, rr - 1).s * get(rr, r).p;
      }
      Mint calcJ(int j) {
        return calc(ls[j], lls[j], rrs[j], rs[j]);
      }
      
      Mint now = 1;
      Mint ans;
      foreach (ref e; es) {
        debug {
          writeln("e = ", e);
        }
        const i = e.i;
        switch (e.typ) {
          case 0: {
            const jL = uf.root(i);
            const jR = uf.root(i + 1);
            const l = ls[jL];
            const r = rs[jR];
            now *= (calcJ(jL) * calcJ(jR)).inv;
            const lr = min(rrs[jL], i);
            const rl = max(lls[jR], i + 1);
            if (lls[jL] < lr && rl < rrs[jR]) {
              Mint prob = now;
              prob *= calc(l, lls[jL], lr, i);
              prob *= calc(i + 1, rl, rrs[jR], r);
              debug {
                writeln("  prob = ", prob, "; ", prob * 32);
              }
              ans += prob * (Mint(e.tp) * Mint(e.tq).inv);
            }
            // no ><
            uf.connect(i, i + 1);
            const j = uf.root(i);
            ls[j] = l;
            rs[j] = r;
            lls[j] = max(lls[jL], lls[jR]);
            rrs[j] = min(rrs[jL], rrs[jR]);
            if (!(lls[j] < rrs[j])) {
              goto done;
            }
            now *= calcJ(j);
          } break;
          case +1: {
            assert(uf.root(i) == uf.root(i + 1));
            const j = uf.root(i);
            const l = ls[j];
            const r = rs[j];
            const ll = lls[j];
            const rr = min(rrs[j], i);
            now *= calcJ(j).inv;
            if (ll < rr) {
              Mint prob = now;
              prob *= calc(l, ll, rr, r);
              debug {
                writeln("  ", l, " ", ll, " ", rr, " ", r);
                writeln("  prob = ", prob, "; ", prob * 32);
              }
              ans += prob * (Mint(e.tp) * Mint(e.tq).inv);
            }
            // no ><, >>
            chmax(lls[j], i);
            if (!(lls[j] < rrs[j])) {
              goto done;
            }
            now *= calcJ(j);
          } break;
          case -1: {
            assert(uf.root(i) == uf.root(i + 1));
            const j = uf.root(i);
            const l = ls[j];
            const r = rs[j];
            const ll = max(lls[j], i + 1);
            const rr = rrs[j];
            now *= calcJ(j).inv;
            if (ll < rr) {
              Mint prob = now;
              prob *= calc(l, ll, rr, r);
              debug {
                writeln("  ", l, " ", ll, " ", rr, " ", r);
                writeln("  prob = ", prob, "; ", prob * 32);
              }
              ans += prob * (Mint(e.tp) * Mint(e.tq).inv);
            }
            // no ><, <<
            chmin(rrs[j], i + 1);
            if (!(lls[j] < rrs[j])) {
              goto done;
            }
            now *= calcJ(j);
          } break;
          default: assert(false);
        }
        debug {
          foreach (j; 0 .. N) {
            if (uf[j] < 0) {
              writeln(ls[j], " ", lls[j], " ", rrs[j], " ", rs[j]);
            }
          }
          writeln("now = ", now);
        }
      }
     done:
      writeln(ans);
      
      debug {
        Mint brt;
        foreach (h; 0 .. 1 << N) {
          long tp = 1, tq = 0;
          void check(long tp0, long tq0) {
            if (tp * tq0 > tp0 * tq) {
              tp = tp0;
              tq = tq0;
            }
          }
          foreach (i; 0 .. N - 1) {
            if (!(h & 1 << i) && (h & 1 << i + 1)) {
              check(X[i + 1] - X[i], V[i] + V[i + 1]);
            }
            if (V[i] > V[i + 1]) {
              if (!(h & 1 << i) && !(h & 1 << i + 1)) {
                check(X[i + 1] - X[i], V[i] - V[i + 1]);
              }
            }
            if (V[i] < V[i + 1]) {
              if ((h & 1 << i) && (h & 1 << i + 1)) {
                check(X[i + 1] - X[i], V[i + 1] - V[i]);
              }
            }
          }
          if (tq != 0) {
            Mint prob = 1;
            foreach (i; 0 .. N) {
              prob *= (h & 1 << i) ? (Mint(1) - P[i]) : P[i];
            }
            // writeln(prob, " ", tp, "/", tq);
            brt += prob * Mint(tp) * Mint(tq).inv;
          }
        }
        writeln("brt = ", brt);
      }
    }
  } catch (EOFException e) {
  }
}