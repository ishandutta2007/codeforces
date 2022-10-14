#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#define dec lol
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 998244353, inv2 = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		for(int i = 0; i < n; i+=2) swap(a[i], a[i+1]), a[i] *= -1;
		for(auto &i : a) cout << i << " "; cout << '\n';
	}
}