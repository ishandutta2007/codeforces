#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 2e3 + 55, mod = 1e9 + 7;
void solve() {
	vi a;
	vi b;
	int n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	sort(all(a));
	sort(all(b));
	for(auto i : a) cout << i << " "; cout << "\n";
	for(auto i : b) cout << i << " "; cout << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}