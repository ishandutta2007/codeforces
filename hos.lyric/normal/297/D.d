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


int M, N, K;
char[][] A;

int[][] solve() {
	if (K == 1) {
		int nmr, dnm;
		foreach (x; 0 .. M) foreach (y; 0 .. N) {
			if (x > 0) {
				if (A[(x - 1) + x][y + y] == 'E') {
					++nmr;
				}
				++dnm;
			}
			if (y > 0) {
				if (A[x + x][(y - 1) + y] == 'E') {
					++nmr;
				}
				++dnm;
			}
		}
		if (nmr * 4 >= dnm * 3) {
			return new int[][](M, N);
		} else {
			return null;
		}
	} else {
		int m, n;
		char[][] a;
		if ((M - 1) * N <= M * (N - 1)) {
			m = M;
			n = N;
			a = A;
		} else {
			m = N;
			n = M;
			a = new char[][](m * 2, n * 2);
			foreach (x; 0 .. m * 2) foreach (y; 0 .. n * 2) {
				a[x][y] = A[y][x];
			}
		}
		int[][] ret = new int[][](m, n);
		foreach (x; 0 .. m) {
			foreach (src; 0 .. 2) {
				ret[x][0] = src;
				foreach (y; 1 .. n) {
					ret[x][y] = ret[x][y - 1] ^ ((a[x + x][(y - 1) + y] != 'E') ? 1 : 0);
				}
				if (x > 0) {
					int cnt;
					foreach (y; 0 .. n) {
						if ((a[(x - 1) + x][y + y] == 'E') == (ret[x - 1][y] == ret[x][y])) {
							++cnt;
						}
					}
					if (cnt * 2 >= n) {
						break;
					}
				} else {
					break;
				}
			}
		}
		int[][] RET;
		if ((M - 1) * N <= M * (N - 1)) {
			RET = ret;
		} else {
			RET = new int[][](M, N);
			foreach (x; 0 .. M) foreach (y; 0 .. N) {
				RET[x][y] = ret[y][x];
			}
		}
		return RET;
	}
}

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		K = readInt;
		A = new char[][](M * 2, N * 2);
		foreach (x; 0 .. M) {
			if (x > 0) {
				auto str = readToken;
				foreach (y; 0 .. N) {
					A[(x - 1) + x][y + y] = str[y];
				}
			}
			{
				auto str = readToken;
				foreach (y; 1 .. N) {
					A[x + x][(y - 1) + y] = str[y - 1];
				}
			}
		}
		
		if (auto res = solve) {
			writeln("YES");
			foreach (line; res) {
				line[] += 1;
				writeln(line.to!string.removechars("[],"));
			}
		} else {
			writeln("NO");
		}
	}
	} catch (EOFException) {}
}