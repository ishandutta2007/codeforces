#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;

set<pair<int, int>> a;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int ff = 9999999, n, k;
	cin >> n >> k;
	map<int, int> ps;
	for(int t, i = 0; i< n; i++) {
		cin >> t;
		if(ps.count(t)&&ps[t]-ff<=k) {

		} else {
			if(a.size()==k)
				a.erase(*a.rbegin());
			a.insert({ps[t] = ff--, t});
		}
	}
	cout << a.size() << "\n";
	for(auto i : a)
		cout << i.second << " ";
}