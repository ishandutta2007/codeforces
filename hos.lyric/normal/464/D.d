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


immutable LIM = 1000;

int N, K;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		
		real[] pa = new real[LIM];
		real[] pb = new real[LIM];
		real[] pc = new real[LIM];
		foreach (j; 1 .. LIM - 1) {
			pa[j] = 1.0 - 1.0 / K / (j + 1);
			pb[j] = 1.0 / K - 1.0 / K / (j + 1);
			pc[j] = 1.0 / K / (j + 1);
		}
		
		real[] dp = new real[LIM];
		dp[] = 0.0;
		foreach (i; 0 .. N) {
			foreach (j; 1 .. LIM - 1) {
				// dp[j] = (1.0 - 1.0 / K) * dp[j] + (1.0 / K - 1.0 / K / (j + 1)) * ((j + 1) / 2.0 + dp[j]) + (1.0 / K / (j + 1)) * (j + dp[j + 1]);
				dp[j] = pa[j] * dp[j] + pb[j] * ((j + 1) / 2.0) + pc[j] * (j + dp[j + 1]);
			}
		}
debug{
writeln(dp);
}
		const ans = dp[1] * K;
		writefln("%.10f", ans);
	}
	} catch (EOFException) {}
}