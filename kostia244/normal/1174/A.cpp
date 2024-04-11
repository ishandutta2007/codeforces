#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 7 * 17 * (1 << 23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vi a;
	a.resize(2*n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	if(a[0]==a.back()) {
		cout << -1;
	}else
		for(auto i: a) cout << i << " ";
	return 0;
}