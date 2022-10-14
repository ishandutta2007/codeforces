// #pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 3e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, a[maxn][8], cnt[1<<8], fl = 0;
int aa = 1, bb = 1;
bool can(int x) {
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++) {
		int ms = 0;
		for(int j = 0; j < m; j++) {
			if(a[i][j]>=x) ms|=1<<j;
		}
		cnt[ms]=i+1;
		for(int j = 0; j < 1<<m; j++)
			if(fl==(ms|j)&&cnt[j])
				return aa = cnt[j], bb = i+1, true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	fl = 1<<m, fl--;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	int ans = 0;
	for(int i = 1<<30; i>>=1;)
		if(can(ans+i)) ans+=i;
	cout << aa << " " << bb;
}