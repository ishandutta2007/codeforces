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


immutable LIM = 100005;

int N;

void main(string[] args) {
	bool[] isnp = new bool[LIM];
	for (int i = 2; i * i < LIM; ++i) if (!isnp[i]) for (int j = i * i; j < LIM; j += i) isnp[j] = true;
	
	try {
	for (; ; ) {
		N = readInt;
		
		Pair!(int, int)[] ans;
		bool[] used = new bool[N + 1];
		for (int d = N; d >= 2; --d) if (!isnp[d]) {
			int[] xs;
			for (int x = d; x <= N; x += d) if (!used[x]) {
				xs ~= x;
			}
			if (xs.length >= 2 && xs[1] == d * 2) {
				swap(xs[0], xs[1]);
			}
			for (int j = xs.length % 2; j < xs.length; j += 2) {
				ans ~= pair(xs[j], xs[j + 1]);
				used[xs[j]] = true;
				used[xs[j + 1]] = true;
			}
		}
		
		writeln(ans.length);
		foreach (p; ans) {
			writeln(p.x, " ", p.y);
		}
		
	}
	} catch (EOFException) {}
}