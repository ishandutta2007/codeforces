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


enum MO = 10^^9 + 7;

Tuple!(int, int) brute(const(int) N, const(int[]) P) {
  int prod;
  int ans;
  auto perm = iota(N).array;
  do {
    int score;
    {
      auto uf = new int[N];
      uf[] = -1;
      foreach (u; 0 .. N) {
        uf.connect(u, perm[P[u]]);
      }
      score = 1;
      foreach (r; 0 .. N) {
        if (uf[r] < 0) {
          score *= (-uf[r]);
        }
      }
    }
    if (chmax(prod, score)) {
      ans = int.max;
    }
    if (prod == score) {
      auto uf = new int[N];
      uf[] = -1;
      foreach (u; 0 .. N) {
        uf.connect(u, perm[u]);
      }
      int cost;
      foreach (r; 0 .. N) {
        if (uf[r] < 0) {
          cost += (-uf[r]) - 1;
        }
      }
      chmin(ans, cost);
    }
  } while (perm.nextPermutation);
  return tuple(prod, ans);
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto P = new int[N];
        foreach (u; 0 .. N) {
          P[u] = readInt() - 1;
        }
        
        auto uf = new int[N];
        uf[] = -1;
        foreach (u; 0 .. N) {
          uf.connect(u, P[u]);
        }
        auto lss = new int[][3];
        foreach (r; 0 .. N) {
          if (uf[r] < 0) {
            lss[(-uf[r]) % 3] ~= (-uf[r]);
          }
        }
        foreach (s; 0 .. 3) {
          lss[s].sort;
        }
        debug {
          writeln("lss = ", lss);
        }
        
        long prod;
        int ans = int.max;
        
        int bara;
        foreach (l; lss[0]) bara += l / 3 - 1;
        foreach (l; lss[1]) bara += l / 3;
        foreach (l; lss[2]) bara += l / 3;
        
        int c1 = cast(int)(lss[1].length);
        int c2 = cast(int)(lss[2].length);
        
        int calc(int d1, int d2) {
          int cost;
          const tmp = min(d1, d2);
          cost += tmp;
          d1 -= tmp;
          d2 -= tmp;
          assert(d1 % 3 == 0);
          assert(d2 % 3 == 0);
          cost += d1 / 3 * 2;
          cost += d2 / 3 * 3;
          return cost;
        }
        
        switch (N % 3) {
          case 0: {
            prod = 1;
            foreach (_; 0 .. N / 3) (prod *= 3) %= MO;
            {
              int cost = bara;
              cost += calc(c1, c2);
              chmin(ans, cost);
            }
          } break;
          case 1: {
            prod = 4;
            foreach (_; 0 .. (N - 4) / 3) (prod *= 3) %= MO;
            ans = int.max;
            if (c1 >= 1 && lss[1][$ - 1] >= 4) {
              // 4
              int cost = bara;
              cost -= 1;
              cost += calc(c1 - 1, c2);
              chmin(ans, cost);
            }
            if (c1 >= 1) {
              // (3)+1
              int cost = bara;
              cost += 1;
              cost += calc(c1 - 1, c2);
              chmin(ans, cost);
            }
            if (c2 >= 2) {
              // 2+2
              int cost = bara;
              cost += calc(c1, c2 - 2);
              chmin(ans, cost);
            }
            if (c2 >= 1 && c1 >= 2) {
              // 2+1+1
              int cost = bara;
              cost += 1;
              cost += calc(c1 - 2, c2 - 1);
              chmin(ans, cost);
            }
            if (c1 >= 4) {
              // 1+1+1+1
              int cost = bara;
              cost += 2;
              cost += calc(c1 - 4, c2);
              chmin(ans, cost);
            }
          } break;
          case 2: {
            prod = 2;
            foreach (_; 0 .. (N - 2) / 3) (prod *= 3) %= MO;
            ans = int.max;
            if (c2 >= 1) {
              // 2
              int cost = bara;
              cost += calc(c1, c2 - 1);
              chmin(ans, cost);
            }
            if (c1 >= 2) {
              // 1+1
              int cost = bara;
              cost += 1;
              cost += calc(c1 - 2, c2);
              chmin(ans, cost);
            }
          } break;
          default: assert(false);
        }
        writeln(prod, " ", ans);
        
        debug {
          const brt = brute(N, P);
          // writeln("brt = ", brt);
          assert(brt[0] == prod && brt[1] == ans, format("%s %s %s: %s %s; %s %s", N, P, lss, brt[0], brt[1], prod, ans));
        }
      }
    }
  } catch (EOFException e) {
  }
}