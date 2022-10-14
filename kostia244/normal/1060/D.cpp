#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119 * (1 << 23) + 1);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi l, r;
	cin >> n;
	l.resize(n);
	r.resize(n);
	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	sort(all(l));
	sort(all(r));
	ll ans = n;
	for(int i = 0; i <n ; i++) ans += max(l[i], r[i]);
	cout << ans;
}