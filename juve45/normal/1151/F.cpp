#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) {for(auto e : v) out << e << ' '; out << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <int> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

const int MOD = 1e9 + 7;
const int N = 100;
int n, k, m, a[N], b[N], zero, st;

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
				ans.v[i][j] = (1LL * m.v[i][j] * v[i][j]) % MOD;
		return ans;
	}
	
	Matrix operator*(Matrix &m) {
		Matrix ans(n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				for(long long k = 0; k < n; k++)
					ans.v[i][j] += (1LL * m.v[i][k] * v[k][j]) % MOD,
					ans.v[i][j] %= MOD;
		return ans;
	}

	vector <T> operator*(vector <T> v) {
		vector <T> res(n, 0);
		assert(v.size() >= n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				res[i] += (1LL * v[j] * this->v[j][i]) % MOD,
				res[i] %= MOD;
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


int powMod(int base, int exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;

	int tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (1LL * tmp * base) % MOD;
	return tmp;
}

int invMod(int p) {
	return powMod(p, MOD - 2);
}

int get_prob(int p, int q) {
	return p * invMod(q);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		zero += (a[i] == 0);
	} 

	for(int i = 1; i <= zero; i++)
		st += (a[i] == 0);

	vector <int> init(zero + 1);
	init[st] = 1;

	Matrix<int> tranz(zero + 1);
	int nn = (1LL * n * (n - 1) / 2) % MOD;
	nn = invMod(nn);
	int low = max(2 * zero - n, 0);
	for(int i = low; i <= zero; i++) {
		tranz.v[i][i] += (1LL * zero * (zero - 1) / 2) % MOD;
		tranz.v[i][i] %= MOD;
		tranz.v[i][i] += (1LL * (n - zero) * (n - zero - 1) / 2) % MOD;
		tranz.v[i][i] %= MOD;
		tranz.v[i][i] += (1LL * i * (zero - i)) % MOD;
		tranz.v[i][i] %= MOD;
		tranz.v[i][i] += (1LL * (zero - i) * (n - zero - zero + i)) % MOD;
		tranz.v[i][i] %= MOD;
		tranz.v[i][i] = (1LL * tranz.v[i][i] * nn) % MOD;

		if(i < zero)
			tranz.v[i][i + 1] = (1LL * nn * (zero - i) * (zero - i)) % MOD;
		if(i > low)
			tranz.v[i][i - 1] = (1LL * nn * i * (n - zero - zero + i)) % MOD;
	}

	// dbg(tranz.v);
	// dbg((tranz ^ k).v);

	vector <int> rez = (tranz ^ k) * init;
	cout << rez[zero] << '\n';
}