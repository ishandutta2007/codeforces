#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
multiset<ll> s;


bool rec(ll a) {
	if(s.empty() || s.upper_bound(a) == s.begin()) {
		return false;
	}
	auto it = s.find(a);
	if(it != s.end()) {
		s.erase(it);
		return true;
	}
	if(!rec(a / 2)) return false;
	return rec(a - a / 2);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		s.clear();
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			s.insert(a);
			sum += a;
		}
		if(rec(sum)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}