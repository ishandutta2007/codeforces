#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



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
		int n, x;
		cin >> n >> x;
		multiset<ll> s;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			s.insert(a);
		}
		int ans = 0;
		while(!s.empty()) {
			ll v = *(s.begin());
			s.erase(s.begin());
			auto it = s.find(v * x);
			if(it == s.end()) {
				++ans;
			} else {
				s.erase(it);
			}
		}
		cout << ans << '\n';
	}
}