import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
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


BigInt[] fac;

int N;
string S;

string ans;

void dfs(int i, BigInt p, string s) {
debug{
// writeln("dfs ",i," ",p," ",s);
}
	if (i < 7 && p % 7 == 0) {
		return;
	}
	if (i < 5 && p % 5 == 0) {
		return;
	}
	if (i < 3 && p % 3 == 0) {
		return;
	}
	if (i == 1) {
		if (p == 1) {
			if (ans.length < s.length || (ans.length == s.length && ans < s)) {
				ans = s;
			}
		}
		return;
	}
	for (; ; ) {
		dfs(i - 1, p, s);
		if (p % fac[i] != 0) {
			break;
		}
		p /= fac[i];
		s ~= cast(char)('0' + i);
	}
}

void main(string[] args) {
	fac.length = 10;
	fac[0] = 1;
	foreach (i; 1 .. 10) {
		fac[i] = fac[i - 1] * i;
	}
debug{
writeln(fac);
}
	
	try {
	for (; ; ) {
		N = readInt;
		S = readToken;
		
		BigInt p = 1;
		foreach (c; S) {
			p *= fac[c - '0'];
		}
debug{
writeln("p = ",p);
}
		
		ans = "";
		dfs(9, p, "");
		writeln(ans);
		
	}
	} catch (EOFException) {}
}