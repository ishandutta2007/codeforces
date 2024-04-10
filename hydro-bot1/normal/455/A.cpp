// Hydro submission #62a705715cb5d3a7f56bceb8@1655113073595
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define maxn 100005
int n;
int cnt[maxn], f[maxn];
int mmin = 1e9, mmax = -1e9;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x, cnt[x]++;
		mmin = min(mmin, x), mmax = max(mmax, x);
	}	
	f[mmin] = cnt[mmin] * mmin;
	for(int i = mmin; i <= mmax; i++) 
		f[i] = max(f[i - 1], f[i - 2] + cnt[i] * i);
	cout << f[mmax];
	return 0;
}