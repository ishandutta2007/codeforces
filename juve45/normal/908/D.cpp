#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1001
#define NMAX 
#define MMAX 
#define MOD 1000000007

using namespace std;

long long n, k, x, pa, pb, dp[DMAX][DMAX];
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long pw(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;
	long long tmp = pw(base, exp / 2);
	tmp *= tmp;
	tmp %= MOD;
	if(exp % 2) return (tmp * base) % MOD;
	return tmp; 
}

long long inv(long long k) {
	return pw(k, MOD - 2);
}

long long getDP(long long i, long long j) {
	if(i + j >= k) return (((i + j) + (pa * inv(pb))) % MOD) % MOD;
	if(dp[i][j] != -1) 
		return dp[i][j];
	dp[i][j] = (((getDP(i + 1, j) * pa) % MOD + (getDP(i, i + j) * pb) % MOD) * inv(pa + pb) ) % MOD;
	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> k >> pa >> pb;
	long long g = __gcd(pa, pb);
	pa /= g;
	pb /= g;
	memset(dp, -1, sizeof dp);
	cout << getDP(1, 0);



}