import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

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


immutable long MO = 1000000007;

immutable LIM = 500 * 500 + 5;
long[] two;

int N, K;

void main(string[] args) {
	two = new long[LIM];
	two[0] = 1;
	foreach (i; 1 .. LIM) {
		two[i] = (two[i - 1] * 2) % MO;
	}
	
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		
		long[][] dp = new long[][](K + 1, N + 1);
		dp[0][0] = 1;
		foreach (k; 0 .. K) foreach (i; 0 .. N) {
			foreach (j; i + 1 .. N + 1) {
				/*
					- use one of [x, j) s.t. i <= x < j
					- don't use any of [x, y) s.t. i <= x < y < j
					- whatever for [x, y) s.t. x < i < y <= j
				*/
				const a = j - i;
				const b = (j - i) * (j - i - 1) / 2;
				const c = i * (j - i);
// writeln(k,"  ",i," ",j," : ",a," ",b," ",c,"  ",a+b+c);
				long tmp = dp[k][i];
				(tmp *= (two[a] - 1)) %= MO;
				(tmp *= two[c]) %= MO;
				(dp[k + 1][j] += tmp) %= MO;
			}
		}
// writeln(dp);
		long ans;
		foreach (i; 0 .. N + 1) {
			/*
				- don't use any of [x, y) s.t. i <= x < y <= N
				- whatever for [x, y) s.t. x < i < y <= N
			*/
			const b = (N - i + 1) * (N - i + 1 - 1) / 2;
			const c = i * (N - i);
			long tmp = dp[K][i];
			(tmp *= two[c]) %= MO;
			(ans += tmp) %= MO;
		}
		
		ans = (ans % MO + MO) % MO;
		writeln(ans);
	}
	} catch (EOFException) {}
}