#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

#define st first
#define nd second
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



const long long N = 110;
const long long MOD = 1e9 + 7;
long long n, k, m, a, b, s, dp[N + 1], x, cnt[N];

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
			for(long long j = 0; j < n; j++) {
				ans.v[i][j] = m.v[i][j] + v[i][j];
				ans.v[i][j] %= MOD;
			}
		return ans;
	}
	
	Matrix operator*(Matrix &m) {
		Matrix ans(n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				for(long long k = 0; k < n; k++) {
					ans.v[i][j] += m.v[i][k] * v[k][j];
					ans.v[i][j] %= MOD;
				}
		return ans;
	}

	vector <T> operator*(vector <T> v) {
		vector <T> res(n, 0);
		assert(v.size() >= n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++) {
				res[i] += v[j] * this->v[j][i];
				res[i] %= MOD;
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

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> x;
	for(long long i = 1; i <= n; i++)
		cin >> a, cnt[a]++;

	Matrix<long long> m(101);
	vector <long long> v;

	for(long long i = 0; i < 101; i++)
		for(long long j = 0; j < 99; j++)
			if(i == j + 1) m.v[i][j] = 1;

	for(long long i = 0; i < 100; i++)
		m.v[i][99] = m.v[i][100] = cnt[100 - i];

	m.v[100][100] = 1;

	dp[0] = 1;

	for(long long i = 1; i <= 100; i++) {
		for(long long j = 0; j < i; j++) {
			dp[i] += dp[j] * cnt[i - j];
			dp[i] %= MOD;
		}
		v.push_back(dp[i]);
		s += dp[i];
		s %= MOD;
	}


	v.push_back(s);
	// dbg(v);	

	long long ans = 0;
	if(x <= 100) {
		for(long long i = 1; i <= x; i++)
			ans += dp[i];
	} else {
		auto r = (m ^ (x - 100)) * v;
		ans = r.back();
	}
	cout << (ans + 1) % MOD << '\n';
}