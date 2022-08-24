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


int N, K;
int[] A;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		int ans = int.min;
		
		foreach (i; 0 .. N) foreach (j; i + 1 .. N + 1) {
			int[] xs, ys;
			foreach (k; 0 .. N) {
				((i <= k && k < j) ? xs : ys) ~= A[k];
			}
			xs.sort!"a < b";
			ys.sort!"a > b";
			int now = xs.reduce!"a + b";
			chmax(ans, now);
			foreach (l; 0 .. K) if (l < xs.length && l < ys.length) {
				now -= xs[l];
				now += ys[l];
				chmax(ans, now);
			}
		}
		
		writeln(ans);
		
	}
	} catch (EOFException) {}
}