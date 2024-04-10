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


immutable L = 26;
immutable INF = 1_000_000_000;

int M, N;
string[] A;

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		A = new string[M];
		foreach (x; 0 .. M) {
			A[x] = readToken;
		}
		
		auto costss = new int[][][](M, 2, L);
		foreach (x; 0 .. M) foreach (a; 0 .. L) {
			foreach (y; 0 .. N) {
				if (A[x][y] - 'a' != a) {
					++costss[x][y % 2][a];
				}
			}
		}
		auto costs = new int[][][](M, L, L);
		foreach (x; 0 .. M) foreach (a; 0 .. L) foreach (b; 0 .. L) {
			costs[x][a][b] = costss[x][0][a] + costss[x][1][b];
		}
		
		auto dp = new int[][][](M + 1, L, L);
		// auto prv = new Pair!(int, int)[][][](M + 1, L, L);
		foreach (x; 1 .. M + 1) foreach (a; 0 .. L) foreach (b; 0 .. L) {
			dp[x][a][b] = INF;
		}
		foreach (x; 0 .. M) foreach (a; 0 .. L) foreach (b; 0 .. L) if (dp[x][a][b] < INF) {
			foreach (aa; 0 .. L) if (a != aa) foreach (bb; 0 .. L) if (b != bb) if (aa != bb) {
				// if (dp[x + 1][aa][bb] > dp[x][a][b] + costs[x][aa][bb]) {
					// dp[x + 1][aa][bb] = dp[x][a][b] + costs[x][aa][bb];
					// prv[x + 1][aa][bb] = pair(a, b);
				// }
				chmin(dp[x + 1][aa][bb], dp[x][a][b] + costs[x][aa][bb]);
			}
		}
		
		int opt = INF;
		int am = -1, bm = -1;
		foreach (a; 0 .. L) foreach (b; 0 .. L) {
			if (opt > dp[M][a][b]) {
				opt = dp[M][a][b];
				am = a;
				bm = b;
			}
		}
		
		auto ans = new int[][M];
		for (int x = M, a = am, b = bm; x--; ) {
			ans[x] = [ a, b ];
			// const p = prv[x + 1][a][b];
			// a = p.x;
			// b = p.y;
			const aa = a, bb = b;
			for (a = 0; a < L; ++a) if (a != aa) for (b = 0; b < L; ++b) if (b != bb) {
				if (dp[x + 1][aa][bb] == dp[x][a][b] + costs[x][aa][bb]) {
					goto found;
				}
			}
			assert(false);
		// found:
		found:{}
		}
		
		writeln(opt);
		foreach (x; 0 .. M) {
			foreach (y; 0 .. N) {
				write(cast(char)('a' + ans[x][y % 2]));
			}
			writeln;
		}
		
	}
	} catch (EOFException) {}
}