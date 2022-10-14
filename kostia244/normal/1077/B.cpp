#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	int ans = 0;
	for(int i = 1; i+1 < n; i++) {
		if(!a[i]&&a[i-1]&&a[i+1])a[i+1]=0, ans++;
	}
	cout << ans;
}