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


int N, A, B;
int[] P;

int[] solve() {
	int[int] ids;
	foreach (u; 0 .. N) {
		ids[P[u]] = u;
	}
	int[] cs = new int[N];
	cs[] = -1;
	foreach (src; -1 .. N) {
debug{
writeln(src," ",cs);
}
		int[] q;
		if (src == -1) {
			foreach (u; 0 .. N) {
				if (A - P[u] !in ids) {
					if (cs[u] == 0) {
						return null;
					}
					if (cs[u] == -1) {
						cs[u] = 1;
						q ~= u;
					}
				}
				if (B - P[u] !in ids) {
					if (cs[u] == 1) {
						return null;
					}
					if (cs[u] == -1) {
						cs[u] = 0;
						q ~= u;
					}
				}
			}
		} else {
			if (cs[src] != -1) {
				continue;
			}
			cs[src] = 0;
			q ~= src;
		}
		for (; !q.empty; ) {
			const u = q.front;
			q.popFront;
			if (cs[u] == 0) {
				if (A - P[u] in ids) {
					const v = ids[A - P[u]];
					if (cs[v] == 1) {
						return null;
					}
					if (cs[v] == -1) {
						cs[v] = 0;
						q ~= v;
					}
				}
				if (B - P[u] in ids) {
					const v = ids[B - P[u]];
					if (cs[v] == 1) {
						return null;
					}
					if (cs[v] == -1) {
						cs[v] = 0;
						q ~= v;
					}
				}
			} else {
				if (A - P[u] in ids) {
					const v = ids[A - P[u]];
					if (cs[v] == 0) {
						return null;
					}
					if (cs[v] == -1) {
						cs[v] = 1;
						q ~= v;
					}
				}
				if (B - P[u] in ids) {
					const v = ids[B - P[u]];
					if (cs[v] == 0) {
						return null;
					}
					if (cs[v] == -1) {
						cs[v] = 1;
						q ~= v;
					}
				}
			}
		}
	}
	return cs;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = readInt;
		B = readInt;
		P = new int[N];
		foreach (u; 0 .. N) {
			P[u] = readInt;
		}
		
		int[] res = solve;
		if (res is null) {
			writeln("NO");
		} else {
			writeln("YES");
debug{
writeln(res);
}
			foreach (u; 0 .. N) {
				if (u > 0) {
					write(" ");
				}
				write((res[u] == 0) ? 0 : 1);
			}
			writeln;
		}
		
	}
	} catch (EOFException) {}
}