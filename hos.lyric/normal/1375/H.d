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


int N, Q;
int[] A;
int[] L, R;

int enc(int i, int j) {
  return i * (N + 1) + j;
}
int segN;
int[int][] seg;

int[][] sums;
int getSum(int i, int j, int l, int r) {
  return sums[i][l] - sums[i][r] - sums[j][l] + sums[j][r];
}

int E;
int[][] ops;
int[] ans;

int query(int u, int l, int r, int i, int j) {
  if (getSum(i, j, l, r) == 0) {
    // empty
    return -1;
  }
  // force l <= A[i] < r, l <= A[j - 1] < r
  {
    int lo = i, hi = j;
    for (; lo + 1 < hi; ) {
      const mid = (lo + hi) / 2;
      ((getSum(i, mid, l, r) == 0) ? lo : hi) = mid;
    }
    i = lo;
  }
  {
    int lo = i, hi = j;
    for (; lo + 1 < hi; ) {
      const mid = (lo + hi) / 2;
      ((getSum(mid, j, l, r) == 0) ? hi : lo) = mid;
    }
    j = hi;
  }
  const key = enc(i, j);
  int ret;
  seg[u].update(key, {
    const mid = (l + r) / 2;
    const resL = query(u << 1 | 0, l, mid, i, j);
    const resR = query(u << 1 | 1, mid, r, i, j);
    if (resL == -1) {
      ret = resR;
    } else if (resR == -1) {
      ret = resL;
    } else {
      ops ~= [resL, resR];
      ret = E++;
    }
    return ret;
  }, (ref int r) {
    return ret = r;
  });
  debug {
    writefln("query %s [%s, %s) [%s, %s) = %s", u, l, r, i, j, ret);
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      Q = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt() - 1;
      }
      L = new int[Q];
      R = new int[Q];
      foreach (q; 0 .. Q) {
        L[q] = readInt() - 1;
        R[q] = readInt();
      }
      
      for (segN = 1; segN < N; segN <<= 1) {}
      seg = new int[int][segN << 1];
      foreach (i; 0 .. N) {
        // {A[i]}
        seg[segN + A[i]][enc(i, i + 1)] = i;
      }
      
      sums = new int[][](N + 1, segN + 1);
      foreach (i; 0 .. N) {
        sums[i + 1][A[i] + 1] += 1;
      }
      foreach (i; 0 .. N) foreach (l; 0 .. segN + 1) {
        sums[i + 1][l] += sums[i][l];
      }
      foreach (i; 0 .. N + 1) foreach (l; 0 .. segN) {
        sums[i][l + 1] += sums[i][l];
      }
      
      E = N;
      ops = [];
      ans = new int[Q];
      foreach (q; 0 .. Q) {
        ans[q] = query(1, 0, segN, L[q], R[q]);
      }
      
      /*
      writeln(E);
      foreach (op; ops) {
        writeln(op[0] + 1, " ", op[1] + 1);
      }
      foreach (q; 0 .. Q) {
        if (q > 0) write(" ");
        write(ans[q] + 1);
      }
      writeln;
      */
      import core.stdc.stdio : printf;
      printf("%d\n", E);
      foreach (op; ops) {
        printf("%d %d\n", op[0] + 1, op[1] + 1);
      }
      foreach (q; 0 .. Q) {
        if (q > 0) printf(" ");
        printf("%d", ans[q] + 1);
      }
      printf("\n");
      
      debug {
        auto sets = new int[][E];
        foreach (i; 0 .. N) {
          sets[i] = [A[i]];
        }
        foreach (h; N .. E) {
          const op = ops[h - N];
          assert(sets[op[0]][$ - 1] < sets[op[1]][0]);
          sets[h] = sets[op[0]] ~ sets[op[1]];
          writeln(h, ": ", sets[h]);
        }
        foreach (q; 0 .. Q) {
          auto want = A[L[q] .. R[q]].dup;
          want.sort;
          assert(sets[ans[q]] == want, format("! %s %s %s", q, sets[ans[q]], want));
        }
      }
    }
  } catch (EOFException e) {
  }
}