#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) {out << "[ "; for(auto e : v) out << e << ' '; return out << " ]   ";}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 5005;
const long long TMP = 200;
const long long TMP_REG = 300;
const long long ONE = 400;
const long long MUL_OFFSET = 100;
const long long ZERO = MUL_OFFSET - 1;
const long long X = 1;
const long long Y = 2;
const long long X_Y = 3;
const long long X2 = 4;
const long long Y2 = 5;
const long long X_Y2 = 6;

long long n, d, p, a[N], comb[14][14], nrop = 0, t[N];
vector <long long> v[N];

void add(long long a, long long b, long long c) {
	cout << "+ " << a << ' ' << b << ' ' << c << endl;
	t[c] = (t[a] + t[b]) % p;
	nrop++;
}
long long powMod(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base % p;

	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp)% p;
	if(exp % 2) tmp = (1LL * tmp * base) % p;
	return tmp;
}

long long invMod(long long x) {
	return powMod(x, p - 2);
}

void pow_d(long long a, long long b) {
	cout << "^ " << a << ' ' << b << endl;
	t[b] = powMod(t[a], d);
	nrop++;
}

void multiply(long long start_pos, long long result_pos, long long coef, int refa = 1) {

	/// ma ajut de casutele [OFFSET, OFFSET + 30]
	if(refa) {
		add(start_pos, ZERO, MUL_OFFSET);

		for(long long i = 0; i < 29; i++)
			add(MUL_OFFSET + i, MUL_OFFSET + i, MUL_OFFSET + i + 1);
	}
	add(ZERO, ZERO, result_pos);

	for(long long i = 0; i < 30; i++)
		if(coef & (1 << i)) {
			add(MUL_OFFSET + i, result_pos, result_pos);
		}

}

void make_zero() {

	a[MUL_OFFSET] = 1;
	for(long long i = 0; i < 30; i++) {
		add(MUL_OFFSET + i, MUL_OFFSET + i, MUL_OFFSET + i + 1);
		a[MUL_OFFSET + i + 1] = 2 * a[MUL_OFFSET + i];
	}

	for(long long i = 0; i < 30; i++)
		if((p - 1) & (1 << i)) {
			add(MUL_OFFSET + i, ZERO, ZERO);
		}
}


vector <long long> mul(vector <long long> a, long long b) {
	vector <long long> ret;
	for(auto i : a)
		ret.push_back((i * b) % p);
	return ret;
}

vector <long long> addv(const vector <long long> a, const vector <long long> b) {
	vector <long long> ret;
	for(long long i = 0; i < a.size(); i++)
		ret.push_back((a[i] + b[i]) % p);
	return ret;
}

void Gauss(long long who, long long final) {

	// for()

	// dbg(t[TMP_REG]);
	for(long long i = 0; i < d - 2; i++) {
		// dbg(v[TMP + d - 2]);
		// dbg(t[TMP + d - 2]);
		for(long long j = 0; j <= d - 2; j++) 
			dbg(v[TMP + j]);
		for(long long j = i + 1; j <= d - 2; j++) {
			long long sus = v[TMP + i][v[TMP + i].size() - i - 1];
			long long jos = v[TMP + j][v[TMP + j].size() - i - 1];
			long long to_mul = p-((1LL * invMod(sus) * jos) % p);
			// dbg(j, to_mul);
			dbg(i, j, sus, jos, to_mul);
			multiply(TMP + i, TMP_REG, to_mul, (j == i + 1));
			
			v[TMP_REG] = mul(v[TMP + i], to_mul);
			// dbg(v[TMP_REG]);
			// dbg(v[TMP + j]);
			// dbg(t[TMP_REG]);
			add(TMP + j, TMP_REG, TMP + j);

			v[TMP + j] = addv(v[TMP + j], v[TMP_REG]);
		}
		long long gg = 0;
		// dbg(v[TMP + d - 2]);
		// dbg(t[TMP + d - 2]);
		
		for(int j = 0; j < v[TMP].size(); j++)
			gg += v[TMP + d - 2][j] * powMod(t[who], j);
		gg %= p;
		// dbg(i, gg);
		assert(gg == t[TMP + d - 2]);
		dbg_ok;

	}	
	if(d > 2) {

		multiply(ONE, TMP_REG, p - v[TMP + d - 2][0]);
		v[TMP_REG] = vector <long long> (d + 1, 0);
		v[TMP_REG][0] = p - v[TMP + d - 2][0];
		add(TMP + d - 2, TMP_REG, TMP + d - 2);
		v[TMP + d - 2] = addv(v[TMP + d - 2], v[TMP_REG]);

		// dbg(v[TMP + d - 2]);

		multiply(who, TMP_REG, p - v[TMP + d - 2][1]);

		v[TMP_REG] = vector <long long> (d + 1, 0);
		v[TMP_REG][1] = p - v[TMP + d - 2][1];
		add(TMP + d - 2, TMP_REG, TMP + d - 2);
		v[TMP + d - 2] = addv(v[TMP + d - 2], v[TMP_REG]);

		// dbg(v[TMP + d - 2]);
		multiply(TMP + d - 2, TMP + d - 2, invMod(v[TMP + d - 2][2]));
	}

	dbg(v[TMP + d - 2]);


	add(TMP + d - 2, ZERO, final);
}

void pre() {
	comb[0][1] = 1;
	for(long long i = 1; i <= d; i++)
		for(long long j = 1; j <= d + 1; j++)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
}


vector <long long> get_coef(long long adaug) {
	vector <long long> v;
	for(long long i = 1; i <= d + 1; i++) {
		// dbg(powMod(adaug, d - i + 1));
		v.push_back((comb[d][i] * powMod(adaug, d - i + 1)) % p);
	}
	return v;
}

void createSquare(long long init_pos, long long final_pos) {
	// dbg(t[TMP]);
	multiply(ONE, ONE, 1);

	for(long long i = 0; i <= d - 2; i++) {
		if(i > 0) 
			multiply(ONE, TMP_REG, i);
		else 
			add(ZERO, ZERO, TMP_REG);
		add(init_pos, TMP_REG, TMP + i);
		// dbg(t[TMP + i]);
		// dbg(t[MUL_OFFSET + i - 1]);
		pow_d(TMP + i, TMP + i);
		// dbg(t[TMP + i]);
		v[TMP + i] = get_coef(i); 
	}

	// dbg_v((a + MUL_OFFSET - 1), 10);
	// dbg(get_coef(4));
	// dbg(init_pos, t[init_pos]);
	// dbg(t[TMP]);

	// assert(t[TMP] == powMod(t[init_pos], d));
	// assert(t[TMP + 1] == powMod(t[init_pos] + 1, d));
	// assert(t[TMP + 2] == powMod(t[init_pos] + 2, d));
	Gauss(init_pos, final_pos);
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> d >> p;

	for(int i = 1; i < N ; i++) t[i] = 1;
	t[X] = 5;
	t[Y] = 4;

	pre();
	make_zero();

	add(X, Y, X_Y);

	createSquare(X, X2);
	assert(t[X2] == (t[X] * t[X]) % p);
	createSquare(Y, Y2);
	assert(t[Y2] == (t[Y] * t[Y]) % p);
	
	createSquare(X_Y, X_Y2);
	
	multiply(X2, X2, p - 1);
	multiply(Y2, Y2, p - 1);
	add(X2, X_Y2, X_Y2);
	add(Y2, X_Y2, X_Y2);

	multiply(X_Y2, X_Y2, invMod(2));
	cout << "f " << X_Y2 << endl;
	dbg(nrop);
}