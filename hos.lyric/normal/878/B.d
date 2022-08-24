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


long solve(long K, int[] as) {
  debug {
    writeln("solve ", K, " ", as);
  }
  int len;
  auto keys = new int[as.length + 1];
  auto nums = new int[as.length + 1];
  long ret;
  void push(int a) {
    for (; ; ) {
      if (len >= 1 && keys[len - 1] == a) {
        ++nums[len - 1];
        break;
      }
      if (len >= 1) {
        ret += nums[len - 1] / K;
        nums[len - 1] %= K;
        if (nums[len - 1] == 0) {
          --len;
          continue;
        }
      }
      keys[len] = a;
      nums[len] = 1;
      ++len;
      break;
    }
  }
  foreach (a; as) {
    push(a);
  }
  push(-1);
  debug {
    writeln("  ret = ", ret);
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      int N = readInt();
      const K = readLong();
      const M = readLong();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      debug {
        writefln("N = %s, K = %s, M = %s, A = %s", N, K, M, A);
        stdout.flush;
      }
      
      const long inpN = N;
      long ans;
      
      {
        int len;
        auto keys = new int[A.length + 1];
        auto nums = new int[A.length + 1];
        long ret;
        void push(int a) {
          for (; ; ) {
            if (len >= 1 && keys[len - 1] == a) {
              ++nums[len - 1];
              break;
            }
            if (len >= 1) {
              ret += nums[len - 1] / K;
              nums[len - 1] %= K;
              if (nums[len - 1] == 0) {
                --len;
                continue;
              }
            }
            keys[len] = a;
            nums[len] = 1;
            ++len;
            break;
          }
        }
        foreach (a; A) {
          push(a);
        }
        push(-1);
        debug {
          writeln("  ret = ", ret);
        }
        ans += ret * M;
        A = [];
        foreach (j; 0 .. len) {
          if (keys[j] != -1) {
            foreach (_; 0 .. nums[j]) {
              A ~= keys[j];
            }
          }
        }
        N = cast(int)(A.length);
      }
      
      debug {
        writefln("N = %s, K = %s, M = %s, A = %s; ans = %s", N, K, M, A, ans);
        stdout.flush;
      }
      
      auto lef = new int[N];
      auto rig = new int[N];
      foreach (i; 0 .. N) {
        lef[i] = (i - 1 >= 0 && A[i - 1] == A[i]) ? lef[i - 1] : i;
      }
      foreach_reverse (i; 0 .. N) {
        rig[i] = (i + 1 < N && A[i + 1] == A[i]) ? rig[i + 1] : i;
      }
      debug {
        writeln("lef = ", lef);
        writeln("rig = ", rig);
      }
      
      if (N == 0) {
      } else if (M == 1) {
        ans += solve(K, A);
      } else {
        // [0, x] [y, N - 1]
        int x = N - 1, y = 0;
        for (; ; ) {
          debug {
            writefln("x = %s, y = %s", x, y);
          }
          if (lef[x] == y) {
            // [0, y) [y, x] (deleted) [y, x] (x, N - 1]
            const sz = (x - y + 1) * M;
            ans += sz / K;
            if (sz % K != 0) {
              debug {
                writeln("break ", __LINE__);
              }
              ans += solve(K, A[0 .. y]);
              ans += solve(K, A[x + 1 .. N]);
              break;
            } else {
              debug {
                writeln("break ", __LINE__);
              }
              ans += solve(K, A[0 .. y] ~ A[x + 1 .. N]);
              break;
            }
          } else if (x - lef[x] + 1 >= K) {
            ans += (M - 1);
            x -= K;
          } else if (rig[y] - y + 1 >= K) {
            ans += (M - 1);
            y += K;
          } else if (A[x] == A[y]) {
            const sz = (x - lef[x] + 1) + (rig[y] - y + 1);
            ans += (sz / K) * (M - 1);
            x = lef[x] - 1;
            y = rig[y] + 1;
            if (sz % K != 0) {
              debug {
                writeln("break ", __LINE__);
              }
              ans += solve(K, A[0 .. x + 1]);
              ans += solve(K, A[y .. N]);
              break;
            }
          } else {
            debug {
              writeln("break ", __LINE__);
            }
            ans += solve(K, A[0 .. x + 1]);
            ans += solve(K, A[y + 1 .. x]) * (M - 2);
            ans += solve(K, A[y .. N]);
            break;
          }
        }
      }
      ans = inpN * M - ans * K;
      writeln(ans);
      
      debug {
        const k = cast(int)(K);
        int[] brt;
        foreach (_; 0 .. M) {
          brt ~= A;
        }
        for (; ; ) {
          const brtLen = cast(int)(brt.length);
          foreach (i; 0 .. brtLen - k + 1) {
            if (brt[i .. i + k].all!(a => (a == brt[i]))) {
              brt = brt[0 .. i] ~ brt[i + k .. $];
              goto found;
            }
          }
          break;
         found:
        }
        writeln("brt = ", brt);
        stdout.flush;
        assert(ans == brt.length);
      }
    }
  } catch (EOFException e) {
  }
}