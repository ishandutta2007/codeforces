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


/*
Jabber ID on the national Berland service Babber has a form <username>@<hostname>[/resource], where

<username>  is a sequence of Latin letters (lowercase or uppercase), 
	digits or underscores characters _, the length of <username> is between 1 and 16, inclusive.
<hostname>  is a sequence of word separated by periods (characters .), 
	where each word should contain only characters allowed for <username>, 
	the length of each word is between 1 and 16, inclusive. 
	The length of <hostname> is between 1 and 32, inclusive.
<resource>  is a sequence of Latin letters (lowercase or uppercase), 
	digits or underscores characters _, the length of <resource> is between 1 and 16, inclusive.
*/

string S;

bool solve() {
	if (auto m = S.match(`^\w{1,16}\@([\w||\.]{1,32})(\/\w{1,16}){0,1}$`)) {
// writeln(m);
		if (m.captures[1].match(`^\w{1,16}(\.\w{1,16})*$`)) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void main(string[] args) {
	try {
	for (; ; ) {
		S = readToken;
		
		const res = solve;
		writeln(res ? "YES" : "NO");
	}
	} catch (EOFException) {}
}