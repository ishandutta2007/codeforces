#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
int ans = 1;
int pre[1<<18];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	pre[0] = 1;
	for(int i = 1; i < n; i++) {
		pre[i] = 1 + (a[i]>a[i-1])*pre[i-1];
		ans = max(ans, pre[i]);
	}
	int c = 1;
	for(int j = n-1; j-->1;) {
		if(a[j-1]<a[j+1])
		ans = max(ans, c+(j?pre[j-1]:0));//, cout << j << " " << c << " " << pre[j-1] << "\n";
		if(j+1==n||a[j+1]>a[j]) c++;
		else c = 1;
	}
	cout << ans;
}