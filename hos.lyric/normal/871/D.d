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


long solveSmall(const(int) N) {
  auto d = new int[][](N + 1, N + 1);
  foreach (u; 1 .. N + 1) foreach (v; 1 .. N + 1) {
    d[u][v] = (u == v) ? 0 : (gcd(u, v) != 1) ? 1 : N;
  }
  foreach (w; 1 .. N + 1) foreach (u; 1 .. N + 1) foreach (v; 1 .. N + 1) {
    chmin(d[u][v], d[u][w] + d[w][v]);
  }
  debug {
    foreach (u; 1 .. N + 1) {
      writef("%2d:", u);
      foreach (v; 1 .. N + 1) {
        writef(" %2d", d[u][v]);
      }
      writeln();
    }
  }
  long ans;
  auto freq = new long[4];
  foreach (u; 1 .. N + 1) foreach (v; u + 1 .. N + 1) {
    if (d[u][v] >= N) {
      ++freq[0];
    } else {
      ans += d[u][v];
      ++freq[d[u][v]];
    }
  }
  debug {
    writeln("freq = ", freq);
  }
  return ans;
}

long solve(const(int) N) {
  auto lpf = iota(N + 1).array;
  int[] primes;
  auto phi = iota(N + 1).array;
  auto moe = new int[N + 1];
  moe[] = 1;
  foreach (p; 2 .. N + 1) {
    if (lpf[p] == p) {
      primes ~= p;
      for (int n = 2 * p; n <= N; n += p) {
        chmin(lpf[n], p);
      }
      for (int n = p; n <= N; n += p) {
        phi[n] = phi[n] / p * (p - 1);
        moe[n] *= -1;
        if (n / p % p == 0) {
          moe[n] = 0;
        }
      }
    }
  }
  
  auto freq = new long[4];
  
  // 0
  long cnt0 = 1;
  foreach (p; primes) {
    if (2 * p > N) {
      ++cnt0;
    }
  }
  freq[0] = 1L * N * (N - 1) / 2 - 1L * (N - cnt0) * ((N - cnt0) - 1) / 2;
  
  // 1
  foreach (u; 2 .. N + 1) {
    freq[1] += (u - 1 - phi[u]);
  }
  
  // 2
  auto roughs = new long[][N + 1];
  foreach (p; primes) {
    if (2 * p > N) {
      continue;
    }
    roughs[p] = new long[N / p + 1];
    foreach (n; 1 .. N / p + 1) {
      if (n == 1 || lpf[n] >= p) {
        ++roughs[p][n];
      }
    }
    foreach (n; 1 .. N / p + 1) {
      roughs[p][n] += roughs[p][n - 1];
    }
  }
  foreach (p; primes) {
    foreach (q; primes) {
      if (q > N / p) {
        break;
      }
      if (p < q) {
        /*
          u = p u', v = q v'
          lpf(u') >= p, lpf(v') >= q
          gcd(u, v) = 1 <=> gcd(u', v') = 1 and q \| u'
        */
        foreach (d; 1 .. N / q + 1) {
          // d | u', d | v'
          if (d == 1 || lpf[d] > q) {
            freq[2] += moe[d] * (roughs[p][N / p / d] - roughs[p][N / p / d / q]) * roughs[q][N / q / d];
          }
        }
      }
    }
  }
  
  // 3
  freq[3] = 1L * N * (N - 1) / 2;
  foreach (d; 0 .. 3) {
    freq[3] -= freq[d];
  }
  
  debug {
    writeln("freq = ", freq);
  }
  long ans;
  foreach (d; 0 .. 4) {
    ans += freq[d] * d;
  }
  return ans;
}

void main() {
  debug {
    foreach (N; 1 .. 20 + 1) {
      const ansSmall = solveSmall(N);
      const ans = solve(N);
      writeln(N, ": ", ansSmall, " ", ans);
      assert(ansSmall == ans);
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      debug {
        const ansSmall = solveSmall(N);
        writeln(ansSmall);
      }
      const ans = solve(N);
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}