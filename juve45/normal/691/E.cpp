#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long MOD = 1e9 + 7;
long long n;

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

	Matrix operator*(Matrix &m) {
		Matrix ans(n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				for(long long k = 0; k < n; k++) {
					ans.v[i][j] += (m.v[i][k] * v[k][j]) % MOD;
					ans.v[i][j] %= MOD;
				}
		return ans;
	}

	vector <T> operator*(vector <T> v) {
		vector <T> res(n, 0);
		assert(v.size() >= n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				res[i] += v[j] * this->v[j][i];
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

long long k, a[123], ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	for(long long i = 0; i < n; i++)
		cin >> a[i];

	Matrix<long long> mat(n);

	for(long long i = 0; i < n; i++)
		for(long long j = 0; j < n; j++)
			if(__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
				mat.v[i][j] = 1;

	dbg(mat.v);

	mat = mat ^ (k - 1);
	for(long long i = 0; i < n; i++)
		for(long long j = 0; j < n; j++)
			ans += mat.v[i][j];
	ans %= MOD;
	cout << ans << '\n';
}