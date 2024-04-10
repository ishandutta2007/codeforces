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


alias Op = Tuple!(int, "l", int, "r");
alias Result = Tuple!(string, "str", Op[], "ops");
Result solve(const(int) N, const(int) K, const(string) A) {
  auto cs = A.dup;
  Op[] ops;
  void rev(int l, int r) {
    for (int x = l, y = r - 1; x < y; ++x, --y) {
      swap(cs[x], cs[y]);
    }
    ops ~= Op(l, r);
    debug {
      // writeln(l, " ", r, " ", cs);
    }
  }
  
  const M = cast(int)(cs.count('1'));
  
  int xsLen;
  auto xs = new int[M];
  void getXs(int s) {
    xsLen = 0;
    foreach (x; s .. N) {
      if (cs[x] == '1') {
        xs[xsLen++] = x;
      }
    }
    xs[xsLen .. M] = -1;
  }
  
  if (K == 0 || K == N) {
    //
  } else {
    if (M < K) {
      //
    } else if (M == K) {
      getXs(0);
      auto ds = cs.dup;
      ds[xs[0] .. xs[K - 1] + 1].reverse;
      if (cs <= ds) {
        rev(xs[0], xs[K - 1] + 1);
        getXs(0);
        rev(0, xs[K - 1] + 1);
      } else {
        rev(0, xs[K - 1] + 1);
      }
    } else {
      foreach (i; 0 .. M - K) {
        getXs(i);
        rev(i, xs[K - 1] + 1);
      }
      if (K % 2 == 0) {
        foreach (_; 0 .. K) {
          getXs(M - K - 1);
          rev(xs[0], xs[K]);
          getXs(M - K - 1);
          rev(xs[0] + 1, xs[K] + 1);
        }
      } else {
        foreach (_; 0 .. K) {
          getXs(M - K - 1);
          rev(M - K - 1, xs[K - 1] + 1);
          rev(M - K, xs[K] + 1);
        }
      }
    }
  }
  debug {
    writeln("ret = ", cs, " ", ops);
  }
  return Result(cs.to!string, ops);
}

void main() {
  /*
  debug {
    foreach (n; 1 .. 8 + 1) {
      foreach (k; 1 .. n) {
        auto uf = new int[1 << n];
        uf[] = -1;
        foreach (p; 0 .. 1 << n) {
          foreach (i; 0 .. n + 1) foreach (j; i + 1 .. n + 1) {
            if (popcnt(p & ((1 << j) - (1 << i))) == k) {
              int pp = p;
              foreach (h; i .. j) {
                if (p & 1 << h) {
                  pp ^= 1 << h;
                  pp ^= 1 << (i + j - 1 - h);
                }
              }
              uf.connect(p, pp);
            }
          }
        }
        auto pss = new int[][1 << n];
        foreach (p; 0 .. 1 << n) {
          pss[uf.root(p)] ~= p;
        }
        writefln("n = %s, k = %s", n, k);
        foreach (h; 0 .. n + 1) {
          writeln("  ", h);
          foreach (r; 0 .. 1 << n) {
            if (uf[r] < 0 && popcnt(r) == h) {
              write("    ", -uf[r]);
              foreach (p; pss[r]) {
                write(" ");
                foreach (i; 0 .. n) {
                  write((p >> i) & 1);
                }
              }
              writeln;
            }
          }
        }
        writeln;
        stdout.flush;
      }
    }
  }
  */
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const K = readInt();
        const A = readToken();
        const B = readToken();
        
        const resA = solve(N, K, A);
        const resB = solve(N, K, B);
        if (resA.str == resB.str) {
          writeln(resA.ops.length + resB.ops.length);
          foreach (op; resA.ops) {
            writeln(op.l + 1, " ", op.r);
          }
          foreach_reverse (op; resB.ops) {
            writeln(op.l + 1, " ", op.r);
          }
          
          debug {
            auto cs = A.dup;
            writeln("! ", cs);
            foreach (op; resA.ops) {
              cs[op.l .. op.r].reverse;
              write("A ");
              foreach (i; 0 .. N) write((op.l <= i && i < op.r) ? '-' : ' ');
              writeln;
              writeln("! ", cs);
            }
            foreach_reverse (op; resB.ops) {
              cs[op.l .. op.r].reverse;
              write("B ");
              foreach (i; 0 .. N) write((op.l <= i && i < op.r) ? '-' : ' ');
              writeln;
              writeln("! ", cs);
            }
            assert(cs == B);
          }
        } else {
          writeln(-1);
        }
      }
    }
  } catch (EOFException e) {
  }
}