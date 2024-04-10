#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define INF 2000000010
#define ST_SIZE 1048600
#define QMAX 400010
#define NMAX 300010

int k, n;
int v[NMAX];
bool dp[NMAX];

bool ok(int d)
{
	int i, last1;
	
	memset(dp, 0, sizeof dp);
	dp[0] = true;
	
	for(last1 = -1, i = 1; i <= n; ++i)
	{
		if(i - k >= 0 && dp[i - k])
			last1 = i - k;
		
		if(last1 >= 0 && v[i] - v[last1 + 1] <= d)
			dp[i] = true;
	}
	
	return dp[n];
}

int main()
{
	int i, l, r, mid;
	
	cin >> n >> k;
	for(i = 1; i <= n; ++i) cin >> v[i];
	
	sort(v + 1, v + n + 1);
	
	for(l = 0, r = INF; l < r; )
	{
		mid = (l + r) / 2;
		
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l << '\n';
	
	return 0;
}