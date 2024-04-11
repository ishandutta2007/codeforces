//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 100003;
using ld = long double;
int n, k, cnt[110];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		cnt[t%k]++;
	}
	cnt[0]/=2;
	for(int i = 1; i <= k-i; i++) {
		if(i==k-i) {
			cnt[0] += cnt[i]/2;
		} else
			cnt[0] += min(cnt[i], cnt[k-i]);
	}
	cout << 2*cnt[0];
}