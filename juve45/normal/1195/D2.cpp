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

const long long MOD = 998244353;
const long long N = 100100;
long long n, a[N], f[15];

vector <long long> compute(long long nr1, long long nr2) {
	long long n10 = 1;
	vector <long long>v;
	while(nr1 && nr2) {
		n10 *= 10;
		v.push_back(n10);
		n10 *= 10;
		n10 %= MOD;
		nr1--;
		nr2--;
	} 

	while(nr1) {
		v.push_back(n10);
		n10 *= 10;
		n10 %= MOD;
		nr1--;
	}
	return v;
}


vector <long long> compute_rev(long long nr1, long long nr2) {
	long long n10 = 1;
	vector <long long>v;
	while(nr1 && nr2) {
		v.push_back(n10 % MOD);
		n10 *= 10;
		n10 *= 10;
		n10 %= MOD;
		nr1--;
		nr2--;
	} 

	while(nr1) {
		v.push_back(n10 % MOD);
		n10 *= 10;
		n10 %= MOD;
		nr1--;
	}
	return v;
}

long long nrc(long long k) {
	long long nr = 0;
	while(k) {
		nr++;
		k /= 10;
	}
	return max(nr, 1LL);
}

long long fft(long long val, vector <long long> mul) {
	long long ret = 0;
	for(long long i : mul) {
		ret += (i * (val % 10)) % MOD;
		ret %= MOD;
		val /= 10;
	}
	return ret;
}

vector <long long> vv[11][11], vr[12][12];


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		f[nrc(a[i])]++;
	}

	for(int i = 1; i <= 10; i++)
		for(int j = 1; j <= 10; j++)
			vv[i][j] = compute(i, j),
			vr[i][j] = compute_rev(i, j);

	long long ans = 0;
	for(long long i = 1; i <= n; i++) {
		for(long long j = 1; j <= 10; j++) {
			long long k = nrc(a[i]);
			assert(k <= 10);
			ans += (f[j] * fft(a[i], vv[k][j])) % MOD;
			ans += (f[j] * fft(a[i], vr[k][j])) % MOD;
			ans %= MOD;
		}
	}

	cout << ans << '\n';
}