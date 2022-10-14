#include<bits/stdc++.h>
#define int ll
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	n = min(n, 30ll);
	m &= (1<<n)-1;
	cout << m << '\n';
}