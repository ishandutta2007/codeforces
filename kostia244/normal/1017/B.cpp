#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<21, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int x = 0, y = 0;
	map<int, int> cnt;
	for(int i = 0; i < n; i++) cnt[(a[i]-'0') + 2*(b[i]-'0')]++;
	ll ans = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			int x = (i>0) + 2*(j>0);
			if((i&1)^(j&1)) i ^= 1, j ^= 1;
			int y = (i>0) + 2*(j>0);
			if(x != y) ans += cnt[i]*1ll*cnt[j] * (i <= j);
		}
	}
	cout << ans;
}