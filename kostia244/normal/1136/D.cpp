#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define maxn 300005
#define mod 1000000007ll
using namespace std;

int n, m, x, y, ans = 0;
vi p;
set<pi> can;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	p.resize(n);
	for(auto& i : p) cin >> i;
	while(m--)
		cin >> x >> y, can.insert({x, y});
	for(int i = n-2; i >= 0; i--) {
		bool ok = true;
		for(int j = i+1; j < (n-ans); j++) {
			if(can.find({p[j-1], p[j]}) == can.end()) {
				ok = false;
				break;
			}
			swap(p[j-1], p[j]);
		}
		if(ok) ans++;
	}
	cout << ans;
	return 0;
}