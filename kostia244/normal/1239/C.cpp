//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 69;
ll n, p, m[100100], ans[100100];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p;
	map<ll, vector<pi>> ev;
	for(int i = 1; i <= n; i++) cin >> m[i], ev[m[i]].pb(pi{0, i});
	set<int> q, w;
	ll qt = 0;
	for(auto i : ev) {
		for(auto j : i.second) {
			if(!j.first) {
				w.insert(j.second);
			} else {
				q.erase(j.second);
			}
		}
//		cout << qt << "\n";
//		cout << i.first << "q: ";for(auto i : q) cout << i << " ";cout << "\n";
//		cout << i.first << "w: ";for(auto i : w) cout << i << " ";cout << "\n";
		if(!w.empty()) {
			if(q.empty()) {
				int t = *w.begin();
				ans[t] = max(i.first,qt)+p;
				qt = ans[t];
				ev[ans[t]].pb(pi{1, t});
				q.insert(t);
				w.erase(t);
//				cout << t << " " << ans[t]<< "t\n";
			} else if((*w.begin()) < (*q.begin())) {
				int t = *w.begin();
				ans[t] = max(i.first, qt)+p;
				qt = ans[t];
				ev[ans[t]].pb(pi{1, t});
				q.insert(t);
				w.erase(t);
//				cout << t << "\n";
			}
		}
//		cout << i.first << "q: ";for(auto i : q) cout << i << " ";cout << "\n";
//		cout << i.first << "w: ";for(auto i : w) cout << i << " ";cout << "\n";
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}