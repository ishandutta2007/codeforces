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


int isDigit(char c) {
	return ('0' <= c && c <= '9');
}
int isAlpha(char c) {
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int N;
string[] S;
string T;

/*
	0: ()
	1-4: op
	8: (), suspicious
	9-12: op, suspicious
*/
int[string] macros;

int oper(char op, int a, int b) {
	int ret;
	ret |= a & 8;
	ret |= b & 8;
	a &= 7;
	b &= 7;
	switch (op) {
		case '+': {
			ret |= 1;
			
		} break;
		case '-': {
			ret |= 2;
			if (b == 1 || b == 2) {
				ret |= 8;
			}
		} break;
		case '*': {
			ret |= 3;
			if (a == 1 || a == 2 || b == 1 || b == 2) {
				ret |= 8;
			}
		} break;
		case '/': {
			ret |= 4;
			if (a == 1 || a == 2 || b == 1 || b == 2 || b == 3 || b == 4) {
				ret |= 8;
			}
		} break;
		default: assert(false);
	}
	return ret;
}

int parse(string s) {
	s = s.removechars("\n\t ") ~ "$";
// writeln("s = ",s);
	int c;
	struct Parser {
		int expr() {
			int ret = factor;
			for (; s[c] == '+' || s[c] == '-'; ) {
				char op = s[c];
				++c;
				int tmp = factor;
				ret = oper(op, ret, tmp);
			}
			return ret;
		}
		int factor() {
			int ret = term;
			for (; s[c] == '*' || s[c] == '/'; ) {
				char op = s[c];
				++c;
				int tmp = term;
				ret = oper(op, ret, tmp);
			}
			return ret;
		}
		int term() {
			int ret;
			if (s[c] == '(') {
				++c;
				ret = expr;
				assert(s[c] == ')');
				++c;
				ret &= 8;
			} else if (isDigit(s[c])) {
				for (; isDigit(s[c]); ) {
					++c;
				}
				ret = 0;
			} else {
				string name;
				for (; isAlpha(s[c]); ) {
					name ~= s[c];
					++c;
				}
				if (name in macros) {
					ret = macros[name];
				} else {
					ret = 0;
				}
			}
			return ret;
		}
	}
	const res = Parser().expr;
	assert(s[c] == '$');
	return res;
}

void main(string[] args) {
	for (string line; (line = readln) != null; ) {
		N = line.chomp.to!int;
		S = new string[N];
		foreach (i; 0 .. N) {
			S[i] = readln.chomp;
		}
		T = readln.chomp;
		
		macros.clear;
		foreach (i; 0 .. N) {
			// auto captures = S[i].matchFirst(`^\s*#\s*define\s+([A-Za-z]+)\s+(.*)$`).captures;
			auto captures = S[i].match(`^\s*#\s*define\s+([A-Za-z]+)\s+(.*)$`).captures;
// writeln(captures);
			assert(captures.length == 3);
			assert(captures[1] !in macros);
			const res = parse(captures[2]);
// writeln("  ",res);
			macros[captures[1]] = res;
		}
		
		const ans = parse(T);
		writeln((ans & 8) ? "Suspicious" : "OK");
		
	}
}