import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.math, std.range;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { tokens = readln.split; if (stdin.eof) throw new EOFException; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, const T f) { if (t > f) t = f; }
void chmax(T)(ref T t, const T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(S x, T y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(T[] as, bool delegate(T) test) { int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(T[] as, T val) { return as.binarySearch((T a) { return (a <  val); }); }
int upperBound(T)(T[] as, T val) { return as.binarySearch((T a) { return (a <= val); }); }
T[] unique(T)(T[] as) { T[] bs; foreach (a; as) if (bs.empty || bs[$ - 1] != a) bs ~= a; return bs; }


long MO;
void pl(ref long t, long f) {
	if ((t += f) >= MO) {
		t -= MO;
	}
}

int M;
long T;
long[] E;
long[] B;

long[][] bn;

long[] mul(long[] a, long[] b) {
	long[] ret = new long[M + 1];
	foreach (i; 0 .. M + 1) foreach (j; 0 .. M + 1) {
		long prod = (a[i] * b[j]) % MO;
		foreach (k; 0 .. j + 1) if (k <= i && j - k <= M - i) {
			long tmp = prod;
			(tmp *= bn[(i - k) + (j - k)][i - k]) %= MO;
			(tmp *= bn[k + ((M - i) - (j - k))][k]) %= MO;
			pl(ret[(i - k) + (j - k)], tmp);
		}
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		T = readLong;
		MO = readLong;
		E = new long[1 << M];
		foreach (x; 0 .. 1 << M) {
			E[x] = readLong;
		}
		B = new long[M + 1];
		foreach (i; 0 .. M + 1) {
			B[i] = readLong;
		}
		
		bn = new long[][](M + 1, M + 1);
		foreach (i; 0 .. M + 1) {
			bn[i][0] = bn[i][i] = 1;
			foreach (j; 1 .. i) {
				bn[i][j] = (bn[i - 1][j - 1] + bn[i - 1][j]) % MO;
			}
		}
		
		long[][] dp = new long[][](M + 1, 1 << M);
		dp[0][] = E[] % MO;
		foreach (i; 0 .. M) {
			foreach_reverse (j; 0 .. i + 1) {
				foreach (x; 0 .. 1 << M) {
					pl(dp[j + 1][x ^ 1 << i], dp[j][x]);
				}
			}
		}
// writeln(dp);
		
		long[] bx = new long[M + 1];
		long[] by = new long[M + 1];
		bx[] = B[] % MO;
		by[0] = 1;
		for (long e = T; e; e >>= 1, bx = mul(bx, bx)) {
			if (e & 1) {
				by = mul(by, bx);
			}
		}
// writeln("by = ",by);
		
		foreach (x; 0 .. 1 << M) {
			long ans;
			foreach (i; 0 .. M + 1) {
				(ans += by[i] * dp[i][x]) %= MO;
			}
			writeln(ans);
		}
	}
	} catch (EOFException) {}
}