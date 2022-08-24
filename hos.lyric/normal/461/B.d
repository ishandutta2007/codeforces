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
void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(    const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(inout(S) x, inout(T) y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) { return (a <  val); }); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) { return (a <= val); }); }
T[] unique(T)(in T[] as) { T[] bs; foreach (a; as) if (bs.empty || bs[$ - 1] != a) bs ~= a; return bs; }


immutable MO = 1000000007L;

int N;
int[] P;
int[] X;
int[][] G;

long[] solve(int u) {
	long[] dp = new long[2];
	dp[X[u]] += 1;
	foreach (v; G[u]) {
		long[] res = solve(v);
		dp[1] = (dp[1] * (res[0] + res[1]) + dp[0] * res[1]) % MO;
		dp[0] = (dp[0] * (res[0] + res[1])                 ) % MO;
	}
debug{
writeln(u," ",dp);
}
	return dp;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		P = new int[N];
		X = new int[N];
		P[0] = -1;
		foreach (u; 1 .. N) {
			P[u] = readInt;
		}
		foreach (u; 0 .. N) {
			X[u] = readInt;
		}
		
		G = new int[][N];
		foreach (u; 1 .. N) {
			G[P[u]] ~= u;
		}
		
		const res = solve(0);
		long ans = (res[1] % MO + MO) % MO;
		writeln(ans);
	}
	} catch (EOFException) {}
}