#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <long long> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 100;
const long long MOD1 = 1e9 + 6;
const long long MOD2 = 1e9 + 7;
long long n, k, m, a, b;

template<class T>
class Matrix {
public:
	long long n;
	vector <vector<T>> v;

	Matrix(long long _n) {
		n = _n;
		v = vector <vector <T> > (n, vector <T>(n, 0));
	}

	Matrix() {Matrix(5);}

	Matrix Id() {
		Matrix ans(n);
		for(long long i = 0; i < n; i++)
			ans.v[i][i] = 1;
		return ans;
	}

	Matrix operator+(Matrix &m) {
		Matrix ans(n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				ans.v[i][j] = (m.v[i][j] * v[i][j]) % MOD1;
		return ans;
	}
	
	Matrix operator*(Matrix &m) {
		Matrix ans(n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				for(long long k = 0; k < n; k++) {
					ans.v[i][j] += (m.v[i][k] * v[k][j]) % MOD1;
					ans.v[i][j] %= MOD1;
				}
		return ans;
	}

	vector <T> operator*(vector <T> v) {
		vector <T> res(n, 0);
		assert(v.size() >= n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++) {
				res[i] += (v[j] * this->v[j][i]) % MOD1;
				res[i] %= MOD1;
			}
		return res;
	}


	Matrix operator^(long long exp) {
		if(exp == 0) return Id();
		if(exp == 1) return (*this);

		Matrix ans = (*this) ^ (exp / 2);
		ans = ans * ans;
		if(exp % 2) 
			ans = ans * (*this);

		return ans;
	}
};

long long powMul(long long b, long long e) {
	b %= MOD2;
	if(e == 0) return 1;
	long long tmp = powMul(b, e / 2);
	tmp = (1LL * tmp * tmp) % MOD2;
	if(e % 2) tmp = (1LL * tmp * b) % MOD2;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);

	long long n, c, f1, f2, f3;
	cin >> n >> f1 >> f2 >> f3 >> c;

	Matrix <long long> base(3), mul(3);
	base = base.Id();
	mul.v = {
		{0, 0, 1},
		{1, 0, 1},
		{0, 1, 1}
	};
	mul = mul ^ (n - 3);


	vector<long long> v = {1, 3, 0, 0, 0};
	Matrix<long long> mm(5);
	mm.v = {
		{1, 1, 0, 0, MOD1 - 4},
		{0, 1, 0, 0, 2},
		{0, 0, 0, 0, 1},
		{0, 0, 1, 0, 1},
		{0, 0, 0, 1, 1}
	};
	v = (mm ^ (n - 3)) * v;
	long long expc = v.back();
	long long ans = powMul(c, expc);
	dbg(ans);
	ans %= MOD2;
	ans *= powMul(f1, mul.v[0][2]);
	dbg(ans);
	ans %= MOD2;
	ans *= powMul(f2, mul.v[1][2]);
	ans %= MOD2;
	ans *= powMul(f3, mul.v[2][2]);
	ans %= MOD2;
	dbg(mul.v);
	cout << ans << '\n';
}