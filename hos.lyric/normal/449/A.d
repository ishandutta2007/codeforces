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


immutable long LIM = 100000;

long A, B, K;

void main(string[] args) {
	try {
	for (; ; ) {
		A = readLong;
		B = readLong;
		K = readLong;
		
		long ans = -1;
		
		// foreach (phase; 0 .. 2) {
			foreach (x; 0 .. LIM) {
				//	[A / (x + 1)] + [B / (y + 1)]
				const y = K - x;
				if (0 <= x && x < A && 0 <= y && y < B) {
					chmax(ans, (A / (x + 1)) * (B / (y + 1)));
				}
			}
			
			foreach (a; 1 .. LIM) {
				//	[A / (x + 1)] = a
				/*
					want x to be large
					a <= A / (x + 1) < a + 1
					a (x + 1) <= A < (a + 1) (x + 1)
					A / (a + 1) < x + 1 <= A / a
				*/
				const x = min(A / a - 1, K);
				const y = K - x;
				if (0 <= x && x < A && 0 <= y && y < B) {
					chmax(ans, (A / (x + 1)) * (B / (y + 1)));
				}
			}
			// swap(A, B);
		// }
		
		writeln(ans);
		
	}
	} catch (EOFException) {}
}