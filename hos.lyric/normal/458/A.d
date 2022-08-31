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


int[] reduce(string s, int n) {
	int[] ret = new int[n];
	foreach (i; 0 .. s.length) {
		ret[n - s.length + i] = s[i] - '0';
	}
	foreach (_; 0 .. 20) {
		foreach_reverse (i; 0 .. n - 2) {
			const tmp = min(ret[i + 1], ret[i + 2]);
			ret[i] += tmp;
			ret[i + 1] -= tmp;
			ret[i + 2] -= tmp;
		}
		foreach (i; 0 .. n - 3) {
			if (ret[i + 1] > 1) {
				ret[i] += 1;
				ret[i + 1] -= 2;
				ret[i + 3] += 1;
			}
		}
	}
	return ret;
}

string A, B;

void main(string[] args) {
	try {
	for (; ; ) {
		A = readToken;
		B = readToken;
		
		const int n = max(A.length, B.length) + 1;
		auto as = A.reduce(n);
		auto bs = B.reduce(n);
debug{
writeln(as);
writeln(bs);
}
		
		int ans;
		/*
		foreach (i; 0 .. n) {
			if (as[i] != bs[i]) {
				ans = (as[i] < bs[i]) ? -1 : +1;
				break;
			}
		}
		*/
		/*
		foreach (i; 0 .. n) {
			if (as[i] < bs[i]) {
				if (i < n - 2 && as[i + 1] && as[i + 2]) {
					--bs[i];
					--as[i + 1];
					--as[i + 2];
				} else {
					ans = -1;
					break;
				}
			}
			if (as[i] > bs[i]) {
				if (i < n - 2 && bs[i + 1] && bs[i + 2]) {
					--as[i];
					--bs[i + 1];
					--bs[i + 2];
				} else {
					ans = +1;
					break;
				}
			}
		}
		*/
		ans = (as < bs) ? -1 : (as > bs) ? +1 : 0;
		writeln("<=>"[1 + ans]);
		
	}
	} catch (EOFException) {}
}