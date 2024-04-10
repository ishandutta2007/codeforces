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


int M, N, K;
long P;
long[][] A;

long[] solve(long[] xs, long dec) {
	auto q = heapify(xs);
	long[] ret = new long[K + 1];
	foreach (k; 0 .. K) {
		const now = q.front;
		q.removeFront;
		ret[k + 1] = ret[k] + now;
		q.insert(now - dec);
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		K = readInt;
		P = readLong;
		A = new long[][](M, N);
		foreach (x; 0 .. M) foreach (y; 0 .. N) {
			A[x][y] = readLong;
		}
		
		long[] bs = new long[M];
		long[] cs = new long[N];
		foreach (x; 0 .. M) foreach (y; 0 .. N) {
			bs[x] += A[x][y];
			cs[y] += A[x][y];
		}
		
		long[] fbs = solve(bs, P * N);
		long[] fcs = solve(cs, P * M);
// writeln(fbs);
// writeln(fcs);
		long ans = long.min;
		foreach (k; 0 .. K + 1) {
			chmax(ans, fbs[k] + fcs[K - k] - P * k * (K - k));
		}
		writeln(ans);
		
	}
	} catch (EOFException) {}
}