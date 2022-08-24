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




void main() {
  /*
  debug {
    foreach (n; 1 .. 16 + 1) {
      auto dp = new int[1 << n];
      auto prev = new int[1 << n];
      foreach (p; 0 .. 1 << n) {
        dp[p] = popcnt(p);
        prev[p] = -1;
      }
      int iter;
      for (; ; ++iter) {
        bool upd;
        foreach_reverse (p; 0 .. 1 << n) {
          const sup = ((1 << n) - 1) ^ p;
          for (int q = sup; q; --q &= sup) {
            const k = popcnt(q);
            int mn = n + 1;
            foreach (i; 0 .. n) {
              int r = p | q;
              foreach (j; 0 .. k) {
                r &= ~(1 << ((i + j) % n));
              }
              chmin(mn, dp[r]);
            }
            if (chmax(dp[p], mn)) {
              upd = true;
              prev[p] = q;
            }
          }
        }
        if (!upd) {
          break;
        }
      }
      write(n, ": ", iter, " ", dp[0], " ");
      foreach (i; 0 .. n) {
        write((prev[0] >> i) & 1);
      }
      writeln;
      for (int p = 0; ; ) {
        foreach (i; 0 .. n) {
          write((p >> i) & 1);
        }
        writeln;
        if (prev[p] == -1) {
          break;
        }
        foreach (i; 0 .. n) {
          write(((p | prev[p]) >> i) & 1);
        }
        writeln;
        const k = popcnt(prev[p]);
        int mn = n + 1;
        int rm = -1;
        foreach (i; 0 .. n) {
          int r = p | prev[p];
          foreach (j; 0 .. k) {
            r &= ~(1 << ((i + j) % n));
          }
          assert(dp[p] <= dp[r]);
          if (dp[p] == dp[r]) {
            if (chmin(mn, popcnt(r))) {
              rm = r;
            }
          }
        }
        assert(rm != -1);
        p = rm;
      }
      stdout.flush;
    }
  }
  //*/
  
  debug {
    foreach (n; 1 .. 16 + 1) {
      int mx;
      foreach (a; 1 .. n + 1) {
        const q = n / a, r = n % a;
        int score;
        foreach (x; 1 .. a) {
          score += (q + ((x < r) ? 1 : 0)) - 1;
        }
        chmax(mx, score);
      }
      writeln(n, ": ", mx);
    }
  }
  
  const N = readInt();
  
  int mx = -1;
  int am;
  foreach (a; 1 .. N + 1) {
    const q = N / a, r = N % a;
    int score;
    foreach (x; 1 .. a) {
      score += (q + ((x < r) ? 1 : 0)) - 1;
    }
    if (chmax(mx, score)) {
      am = a;
    }
  }
  
  bool[] on;
  const qm = N / am, rm = N % am;
  foreach (x; 0 .. am) {
    const b = qm + ((x < rm) ? 1 : 0);
    foreach (y; 0 .. b) {
      on ~= (y != 0);
    }
  }
  debug {
    writeln(N, ": ", mx, " ", am, " ", qm, " ", rm, " ", on);
  }
  
  auto now = new bool[N];
  for (; ; ) {
    if (now.count(true) >= mx) {
      writeln(0);
      stdout.flush;
      return;
    }
    int[] js;
    foreach (j; 0 .. N) {
      if (on[j] && !now[j]) {
        js ~= j;
      }
    }
    const jsLen = cast(int)(js.length);
    writeln(jsLen);
    foreach (k; 0 .. jsLen) {
      if (jsLen > 0) write(" ");
      write(js[k] + 1);
    }
    writeln;
    stdout.flush;
    const res = readInt();
    if (res == -1) {
      stderr.writeln("ERROR");
      return;
    }
    now[] = on[];
    foreach (k; 0 .. jsLen) {
      now[(res - 1 + k) % N] = false;
    }
  }
}