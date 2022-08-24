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
long K;

long solve(int[] head) {
	if (head[0] != 0) {
		return 0;
	}
// writeln("head = ",head);
	const int m = head.length;
	bool fine(int pos, int val) {
		return (pos >= m || head[pos] == val);
	}
	long ret;
	foreach (l0; 0 .. N + 1) foreach (l1; 0 .. N +1) {
		/*
			x[i] = head[i] (0 <= i < m)
			x[i] = (!)x[N - 1 - i] (0 <= i < l)
			x[l] < (!)x[N - 1 - l] (if l < N)
		*/
		long tmp = 1;
		foreach (i; 0 .. N) if (i <= N - 1 - i) {
			long cnt;
			foreach (s; 0 .. 2) foreach (t; 0 .. 2) if (fine(i, s) && fine(N - 1 - i, t)) {
				bool ok = true;
				if (i == N - 1 - i) {
					ok = ok && (s == t);
				} 
				
				if (i < l0) {
					ok = ok && (s == t);
				} else if (i == l0) {
					ok = ok && (s < t);
				}
				if (N - 1 - i < l0) {
					ok = ok && (t == s);
				} else if (N - 1 - i == l0) {
					ok = ok && (t < s);
				}
				
				if (i < l1) {
					ok = ok && (s == 1 - t);
				} else if (i == l1) {
					ok = ok && (s < 1 - t);
				}
				if (N - 1 - i < l1) {
					ok = ok && (t == 1 - s);
				} else if (N - 1 - i == l1) {
					ok = ok && (t < 1 - s);
				}
				
				if (ok) {
					++cnt;
				}
			}
			tmp *= cnt;
		}
// writeln("  l0 = ",l0,", l1 = ",l1," : ",tmp);
		ret += tmp;
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		K = readLong;
		
		long k = K + 1;
		
		int[] a = new int[N];
		bool ok = true;
		foreach (i; 0 .. N) {
			for (a[i] = 0; a[i] < 2; ++a[i]) {
				const res = solve(a[0 .. i + 1]);
				if (k > res) {
					k -= res;
				} else {
					break;
				}
			}
			if (a[i] == 2) {
				assert(i == 0);
				writeln(-1);
				ok = false;
				break;
			}
		}
		if (ok) {
			writeln(a.to!string.removechars("[], "));
		}
	}
	} catch (EOFException) {}
}