#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 1010

int d[NMAX];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, n, x, y, ans;
	
	cin >> n;
	for(i = 1; i < n; ++i) {
		cin >> x >> y;
		++d[x];
		++d[y];
	}
	
	for(ans = 0, i = 1; i <= n; ++i)
		if(d[i] == 1) ++ans;
	
	cout << ans << '\n';
	
	return 0;
}