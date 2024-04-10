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


int M, N, A, B, C;

char getColor(int x, int y) {
	return 'a' + ((x % 5) * 5 + (y % 5));
}

char[][] solve() {
	char[][] ret = new char[][](M, N);
	if ((M * N) % 2 != 0) {
		return null;
	}
	if (M * N > A * 2 + B * 2 + C * 4) {
		return null;
	}
	if (M % 2 != 0) {
		if (N / 2 > A) {
			return null;
		}
		for (int y = 0; y < N; y += 2) {
			ret[M - 1][y] = ret[M - 1][y + 1] = getColor(M - 1, y);
		}
		--M;
		A -= N / 2;
	}
	if (N % 2 != 0) {
		if (M / 2 > B) {
			return null;
		}
		for (int x = 0; x < M; x += 2) {
			ret[x][N - 1] = ret[x + 1][N - 1] = getColor(x, N - 1);
		}
		--N;
		B -= M / 2;
	}
	for (int x = 0; x < M; x += 2) for (int y = 0; y < N; y += 2) {
		if (A >= 2) {
			ret[x][y] = ret[x][y + 1] = getColor(x, y);
			ret[x + 1][y] = ret[x + 1][y + 1] = getColor(x + 1, y);
			A -= 2;
		} else if (B >= 2) {
			ret[x][y] = ret[x + 1][y] = getColor(x, y);
			ret[x][y + 1] = ret[x + 1][y + 1] = getColor(x, y + 1);
			B -= 2;
		} else if (C >= 1) {
			ret[x][y] = ret[x][y + 1] = ret[x + 1][y] = ret[x + 1][y + 1] = getColor(x, y);
			C -= 1;
		} else {
			return null;
		}
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		A = readInt;
		B = readInt;
		C = readInt;
		
		if (const res = solve) {
			foreach (line; res) {
				writeln(line.to!string);
			}
		} else {
			writeln("IMPOSSIBLE");
		}
	}
	} catch (EOFException) {}
}