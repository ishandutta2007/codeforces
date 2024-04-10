#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 200100;
long long n, k, dp[N], m, val[N], nxt[N], na[N];
vector <long long> v[N], lst[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

long long dfs(long long node) {

	if(dp[node] != -1)
		return dp[node];

	dp[node] = val[node];
	nxt[node] = 0;

	for(auto i : v[node])
		if(dfs(i) >= dp[nxt[node]])
			nxt[node] = i;

	if(nxt[node] != 0)
		dp[node] += dp[nxt[node]];
	return dp[node];
}
 
void gcd(long long &x, long long &y, long long a, long long b) {  
	if (!b)  
	 	x = 1, y = 0;  
	else {             
		gcd(x, y, b, a % b);
		long long aux = x;
		x = y;
		y = aux - y * (a / b);
	}
}
 
long long mod_inv(long long A, long long N) {
  long long inv = 0, ins;
  gcd(inv, ins, A, N);
  if (inv <= 0)
     inv = N + inv % N;
  return inv;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> k;
		na[k] = 1;
	}

	for(long long i = 0; i < m; i++) {
		if(na[i])
			continue;
		long long gg = __gcd(m, i);
		val[gg]++;
		lst[gg].push_back(i);
	}

	for(long long i = 1; i <= m; i++)
		for(long long j = 2 * i; j <= m; j+=i) {
			if(val[i] && val[j])
				v[i].push_back(j); // din i pot ajunge in j
		}

	memset(dp, -1, sizeof dp);

	long long ans = 0;
	for(long long i = 1; i <= m; i++)
		if(dp[ans] < dfs(i))
			ans = i;
	// dbg_v(val, m + 1);
	// dbg_v(dp, m + 1);
	// dbg_v(na, m + 1);
	cout << dp[ans] << '\n';

	long long last = 1, current = ans;
	while(current) {
		for(auto i : lst[current]) {
			// dbg(last);
			long long gg = __gcd(last, m);
			long long x = mod_inv(last / gg, m / gg);
			// dbg(x);
			// dbg(i);
			long long a = (x * i / gg) % m;
			if( a < 0) a += m;
			cout << a << ' ';
			last = i;
		}
		current = nxt[current];
	}

}