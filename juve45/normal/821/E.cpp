#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; out << '\n'; return out;}
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


const long long N = 105;
const long long MOD = 1e9 + 7;
long long n, k, m, a[N], b[N], c[N];

template<class T>
class Matrix {
public:
	long long n;
	vector <vector<T>> v;

	Matrix(long long _n) {
		n = _n;
		v = vector <vector <long long> > (n, vector <long long>(n, 0));
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

	vector <long long> operator*(vector <long long> v) {
		vector <long long> res(n, 0);
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

int main() {
	ios_base::sync_with_stdio(false);


	cin >> n >> k;
	vector <long long> state = vector <long long> (16, 0);
	state[0] = 1;

	for(long long i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	b[n] = k;

	Matrix<long long> m(16);	

	for(long long i = 1; i <= n; i++) {
		// dbg(i);
		m = Matrix<long long>(16);
		for(long long j = 0; j <= c[i]; j++)
			for(long long k = 0; k <= c[i]; k++)
				if(abs(j - k) <= 1)
					m.v[j][k] = 1;

		// dbg(m.v);
		m = m ^ (b[i] - a[i]);
		// dbg(m.v);
		state = m * state;
	}

	cout << state[0] << '\n';
}