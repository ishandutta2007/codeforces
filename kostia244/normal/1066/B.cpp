#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;
ll n, r, ans = 0;
vi a;

void on(int i) {
	for(int j = max(0ll, i-r+1); j < min(n, i+r); j++)
		a[j] += 2;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> r;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(int i = 0; i < n; i++) {
		if(a[i] > 1) continue;
		int j = min(n-1, i+r-1);
		while(j > max(0ll, i-r) && (a[j]!=1&&a[j]!=3)) j--;
		if(j < 0 || j <= i-r || (a[j]!=1&&a[j]!=3)) return cout << -1, 0;
		ans++, on(j);
	}
	cout << ans;
}