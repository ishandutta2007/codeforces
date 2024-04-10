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


int N;
int[] A;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		int[] ls = new int[N];
		int[] rs = new int[N];
		ls[0] = 0;
		foreach (i; 1 .. N) {
			ls[i] = (A[i - 1] < A[i]) ? ls[i - 1] : i;
		}
		rs[N - 1] = N - 1;
		foreach_reverse (i; 0 .. N - 1) {
			rs[i] = (A[i] < A[i + 1]) ? rs[i + 1] : i;
		}
		
		int ans;
		
		//	no change
		foreach (i; 0 .. N) {
			chmax(ans, rs[i] - i + 1);
		}
		
		//	one change, one side
		foreach (i; 0 .. N) {
			if (i - 1 >= 0) {
				chmax(ans, i - ls[i - 1] + 1);
			}
			if (i + 1 < N) {
				chmax(ans, rs[i + 1] - i + 1);
			}
		}
		
		//	one change, two sides
		foreach (i; 1 .. N - 1) {
			if (A[i + 1] - A[i - 1] >= 2) {
				chmax(ans, rs[i + 1] - ls[i - 1] + 1);
			}
		}
		
		writeln(ans);
		
	}
	} catch (EOFException) {}
}