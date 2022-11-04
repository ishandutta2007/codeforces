#include<bits/stdc++.h>
#define prev prev1
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
		int n;
		cin >> n;
		vi a(n);
		vvi pos(n);
		vi ind(n, 0);
		set<pair<int, int>> s;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
			pos[a[i]].push_back(i);
		}
		for(int i = 0; i < n; i++) {
			if(!pos[i].empty()) {
				s.insert({pos[i].size(), i});
			}
		}
		vi now;
		int prev = -1;
		for(int i = 0; i < n; i++) {
			auto it = s.end();
			--it;
			if(it != s.begin() && it->second == prev) --it;
			if(it->first == 0) ++it;
			int amount = it->first;
			now.push_back(it->second);
			prev = it->second;
			s.erase(it);
			s.insert({amount - 1, prev});
		}
		vi res(n);
		for(int i = 0; i < n; i++) {
			int col = now[(i + 1) % n];
			res[pos[col][ind[col]]] = now[i];
			ind[col]++;
		}
		for(int i = 0; i < n; i++) {
			cout << res[i] + 1 << ' ';
		}
		cout << '\n';
	}
}