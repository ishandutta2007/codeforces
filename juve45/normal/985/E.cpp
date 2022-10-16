#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 500100;
int n, k, a[N], d, dp[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> d;

	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int nr = 0;
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		int l = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
		l--;
		int r = i - k;
		dp[i] = dp[i - 1];
		if(l > r)
			continue;
	
		if(l == 0 || dp[r] > dp[l - 1])
			dp[i]++;
		
	}
	
	cout << (dp[n] - dp[n - 1] ? "YES\n" : "NO\n");

}