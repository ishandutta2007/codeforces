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


int[][] PERM3S = [
	[ 0, 1, 2 ], 
	[ 0, 2, 1 ], 
	[ 1, 0, 2 ], 
	[ 1, 2, 0 ], 
	[ 2, 0, 1 ], 
	[ 2, 1, 0 ], 
];

long dot(long[] a, long[] b) {
	long ret;
	foreach (d; 0 .. 3) {
		ret += a[d] * b[d];
	}
	return ret;
}

long[][] A;

void solve() {
	foreach (i; 0 .. 8) {
		foreach (j; 0 .. 8) foreach (k; 0 .. 8) foreach (l; 0 .. 8) {
			if (j != i && k != i && l != i && j < k && k < l) {
				foreach (sj; 0 .. 6) foreach (sk; 0 .. 6) foreach (sl; 0 .. 6) {
					long[][] vs = new long[][](8, 3);
					foreach (d; 0 .. 3) {
						vs[1][d] = A[j][PERM3S[sj][d]] - A[i][d];
						vs[2][d] = A[k][PERM3S[sk][d]] - A[i][d];
						vs[4][d] = A[l][PERM3S[sl][d]] - A[i][d];
					}
					
					const pjj = dot(vs[1], vs[1]);
					const pjk = dot(vs[1], vs[2]);
					const pjl = dot(vs[1], vs[4]);
					const pkk = dot(vs[2], vs[2]);
					const pkl = dot(vs[2], vs[4]);
					const pll = dot(vs[4], vs[4]);
					if (pjj == pkk && pkk == pll && pll > 0 && pjk == 0 && pjl == 0 && pkl == 0) {
debug{
writeln(i,"  ",j," ",k," ",l);
writeln(vs[1]," ",vs[2]," ",vs[4]);
}
						long[][] as, bs;
						foreach (m; 0 .. 8) {
							if (m != i && m != j && m != k && m != l) {
								as ~= A[m];
							}
						}
						foreach (f; 0 .. 8) if (f & (f - 1)) {
							long[] b = new long[3];
							if (f & 1) b[] += vs[1][];
							if (f & 2) b[] += vs[2][];
							if (f & 4) b[] += vs[4][];
							bs ~= b;
						}
						assert(as.length == 4);
						assert(bs.length == 4);
						int[] perm = [ 0, 1, 2, 3 ];
						do {
							bool ok = true;
							int[] ss;
							foreach (x; 0 .. 4) {
								bool found;
								foreach (s; 0 .. 6) {
									bool eq = true;
									foreach (d; 0 .. 3) {
										eq = eq && (bs[perm[x]][d] == as[x][PERM3S[s][d]] - A[i][d]);
									}
									if (eq) {
										found = true;
										ss ~= s;
										break;
									}
								}
								ok = ok && found;
							}
							if (ok) {
debug{
writeln("ss = ",ss);
}
								writeln("YES");
								int pos;
								foreach (h; 0 .. 8) {
									const s = (h == i) ? 0 : (h == j) ? sj : (h == k) ? sk : (h == l) ? sl : ss[pos++];
									foreach (d; 0 .. 3) {
										if (d > 0) write(" ");
										write(A[h][PERM3S[s][d]]);
									}
									writeln;
								}
								return;
							}
						} while (perm.nextPermutation);
					}
				}
			}
		}
	}
	writeln("NO");
}

void main(string[] args) {
	try {
	for (; ; ) {
		A = new long[][](8, 3);
		foreach (i; 0 .. 8) {
			foreach (d; 0 .. 3) {
				A[i][d] = readLong;
			}
		}
		
		solve;
	}
	} catch (EOFException) {}
}