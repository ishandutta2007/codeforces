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


immutable DX = [ +1, 0, -1, 0, ];
immutable DY = [ 0, +1, 0, -1, ];

long[] X, Y;

bool check() {
	foreach (i; 0 .. 3) {
		if (X[(i + 1) % 3] - X[i] == 0 && Y[(i + 1) % 3] - Y[i] == 0) {
			continue;
		}
		if (X[(i + 2) % 3] - X[i] == 0 && Y[(i + 2) % 3] - Y[i] == 0) {
			continue;
		}
		if ((X[(i + 1) % 3] - X[i]) * (X[(i + 2) % 3] - X[i]) + (Y[(i + 1) % 3] - Y[i]) * (Y[(i + 2) % 3] - Y[i]) == 0) {
			return true;
		}
	}
	return false;
}

int solve() {
	if (check) {
		return 0;
	}
	foreach (j; 0 .. 3) foreach (dir; 0 .. 4) {
		X[j] += DX[dir];
		Y[j] += DY[dir];
		if (check) {
			return 1;
		}
		X[j] -= DX[dir];
		Y[j] -= DY[dir];
	}
	return 2;
}

void main(string[] args) {
	try {
	for (; ; ) {
		X = new long[3];
		Y = new long[3];
		foreach (i; 0 .. 3) {
			X[i] = readLong;
			Y[i] = readLong;
		}
		
		int res = solve;
		writeln([ "RIGHT", "ALMOST", "NEITHER" ][res]);
		
	}
	} catch (EOFException) {}
}