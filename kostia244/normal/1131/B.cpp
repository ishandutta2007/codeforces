#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a, b, c = 0, d = 0, m;
vector<pi> l;
vi v;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> m;
	l.resize(m);
	for(auto& i : l) cin >> i.first >> i.second;
	ll ans = min(l[0].first, l[0].second) + 1;
	for(int i = 1; i < m; i++) {
		if((l[i - 1].first == l[i].first && l[i].second == l[i - 1].second)) continue;
		ans +=  max((min(l[i].first, l[i].second) - max(l[i - 1].first, l[i - 1].second)) + 1 - (l[i - 1].second == l[i - 1].first), 0);
	}
	cout << ans;
}