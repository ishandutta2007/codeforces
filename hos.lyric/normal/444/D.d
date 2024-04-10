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


immutable L = 4;

int N;
string S;

void main(string[] args) {
	try {
	for (; ; ) {
		S = readToken;
		N = S.length;
		
		int[][] apps = new int[][27 ^^ L];
		foreach (i; 0 .. N) {
			int u;
			foreach (l; 0 .. L) if (i + l < N) {
				u = u * 27 + (S[i + l] - 'a' + 1);
				apps[u] ~= i;
			}
		}
		
		int[int][] cache = new int[int][27 ^^ L];
		
		foreach (q; 0 .. readInt) {
			string s = readToken;
			string t = readToken;
			int u, v;
			foreach (c; s) {
				u = u * 27 + (c - 'a' + 1);
			}
			foreach (c; t) {
				v = v * 27 + (c - 'a' + 1);
			}
debug{
writeln("apps[u] = ",apps[u]);
writeln("apps[v] = ",apps[v]);
writeln;
}
			if (pair(apps[u].length, u) > pair(apps[v].length, v)) {
				swap(s, t);
				swap(u, v);
			}
			int calcUnionLength(int i, int j) {
				return max(i + s.length, j + t.length) - min(i, j);
			}
			if (v !in cache[u]) {
				int ret = N + 1;
				foreach (i; apps[u]) {
					const idx = apps[v].lowerBound(i);
					if (idx - 1 >= 0) {
						chmin(ret, calcUnionLength(i, apps[v][idx - 1]));
					}
					if (idx < apps[v].length) {
						chmin(ret, calcUnionLength(i, apps[v][idx]));
					}
				}
				if (ret > N) {
					ret = -1;
				}
				cache[u][v] = ret;
			}
			writeln(cache[u][v]);
		}
	}
	} catch (EOFException) {}
}