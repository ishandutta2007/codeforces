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


immutable M = 100_005;
immutable L = 400;

int N;
int[] X, Y;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		X = new int[N];
		Y = new int[N];
		foreach (i; 0 .. N) {
			X[i] = readInt;
			Y[i] = readInt;
		}
		
		int[] cnt = new int[M];
		int[][] ys = new int[][M];
		bool[int][] has = new bool[int][M];
		foreach (i; 0 .. N) {
			++cnt[X[i]];
			ys[X[i]] ~= Y[i];
			has[X[i]][Y[i]] = true;
		}
		foreach (x; 0 .. M) {
			ys[x].sort();
		}
		
		long ans;
		
		foreach (x; 0 .. M) if (2 <= cnt[x] && cnt[x] <= L) {
			foreach (i; 0 .. cnt[x]) foreach (j; i + 1 .. cnt[x]) {
				const yi = ys[x][i];
				const yj = ys[x][j];
				foreach (s; [ +1, -1 ]) {
					const xx = x + s * (yj - yi);
					if (0 <= xx && xx < M) {
						if (s < 0 && cnt[xx] <= L) {
							continue;
						}
						if (yi in has[xx] && yj in has[xx]) {
							++ans;
						}
					}
				}
			}
		}
		
		int[] bigs;
		foreach (x; 0 .. M) if (cnt[x] > L) {
			bigs ~= x;
		}
		foreach (i; 0 .. bigs.length) foreach (j; i + 1 .. bigs.length) {
			const xi = bigs[i];
			const xj = bigs[j];
			for (int k = 0, l = 0; k < cnt[xi] && l < cnt[xj]; ) {
				if (ys[xi][k] == ys[xj][l]) {
					const yy = ys[xi][k] + (xj - xi);
					if (yy in has[xi] && yy in has[xj]) {
						++ans;
					}
				}
				if (ys[xi][k] <= ys[xj][l]) {
					++k;
				} else {
					++l;
				}
			}
		}
		
		writeln(ans);
		
	}
	} catch (EOFException) {}
}