#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 5;
int col[400], dist[400], a[maxn], n, k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	memset(col, -1, sizeof col);
	for(int i = 0; i < n; i++) {
		if(col[a[i]]>-1) {
			a[i] = col[a[i]];
			continue;
		}
		int t = a[i], z = k-1;
		while(z--&&t>0&&col[t]==-1) t--;
		if(col[t]!=-1&&dist[t]+a[i]-t>=k) t++;
		if(col[t] == -1) col[t] = t, dist[t] = 0;
		for(int j = t+1; j <= a[i]; j++) {
			dist[j] = dist[j-1]+1;
			col[j] = col[j-1];
		}
	}
	for(int i = 0; i < n; i++) cout << col[a[i]] << " ";
}