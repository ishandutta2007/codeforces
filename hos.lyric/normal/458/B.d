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


immutable INF = 1_000_000_000_000_000_000;

int M, N;
long[] A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		A = new long[M];
		B = new long[N];
		foreach (i; 0 .. M) {
			A[i] = readLong;
		}
		foreach (j; 0 .. N) {
			B[j] = readLong;
		}
		
		A.sort();
		B.sort();
		long[] ASum = new long[M + 1];
		long[] BSum = new long[N + 1];
		foreach (i; 0 .. M) {
			ASum[i + 1] = ASum[i] + A[i];
		}
		foreach (j; 0 .. N) {
			BSum[j + 1] = BSum[j] + B[j];
		}
		
		long ans = INF;
		foreach (x; 1 .. M + 1) {
			if (BSum[N] > INF / x) {
				continue;
			}
			chmin(ans, ASum[M - x] + x * BSum[N]);
		}
		foreach (x; 1 .. N + 1) {
			if (ASum[M] > INF / x) {
				continue;
			}
			chmin(ans, BSum[N - x] + x * ASum[M]);
		}
		writeln(ans);
		
	}
	} catch (EOFException) {}
}