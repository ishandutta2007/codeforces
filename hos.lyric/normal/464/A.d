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


int N, P;
string S;

string solve() {
	if (P == 1) {
		if (N == 1) {
			if (S < "a") return "a";
			return "";
		} else {
			return "";
		}
	} else if (P == 2) {
		if (N == 1) {
			if (S < "a") return "a";
			if (S < "b") return "b";
			return "";
		} else if (N == 2) {
			if (S < "ab") return "ab";
			if (S < "ba") return "ba";
			return "";
		} else {
			return "";
		}
	} else {
		foreach_reverse (k; 0 .. N) {
			string ret = S[0 .. k];
			bool ok = true;
			foreach (i; k .. N) {
				bool found;
				foreach (x; 0 .. P) {
					if (i == k && x <= S[k] - 'a') {
						continue;
					}
					if (i >= 1 && ret[i - 1] - 'a' == x) {
						continue;
					}
					if (i >= 2 && ret[i - 2] - 'a' == x) {
						continue;
					}
					found = true;
					ret ~= cast(char)('a' + x);
					break;
				}
				if (!found) {
					ok = false;
					break;
				}
			}
			if (ok) {
				return ret;
			}
		}
		return "";
	}
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		P = readInt;
		S = readToken;
		
		string res = solve;
		if (res == "") {
			writeln("NO");
		} else {
			writeln(res);
		}
	}
	} catch (EOFException) {}
}