#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;

char c;
int v, h, n, t, i;
set<int> r[2];
multiset<int, greater<int>> p[2];
vi ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> h >> n;
	r[0] ={0, v};
	r[1] ={0, h};
	p[0].insert(v);
	p[1].insert(h);
	while(n--) {
		cin >> c >> t;
		i = (c == 'H');
		auto L = r[i].insert(t).first;
		auto R = L;
		L--, R++;
		p[i].erase(p[i].find(*R-*L));
		p[i].insert(t-*L);
		p[i].insert(*R-t);
		cout << fixed << (*p[0].begin() * 1ll * *p[1].begin()) << "\n";
	}
}