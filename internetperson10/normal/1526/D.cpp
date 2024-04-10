#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> vec;

struct FTree {
	vector<ll> v;
	int size = 1;
	void init(int n) {
		vector<ll>().swap(v);
		size = 1;
		while(size < n) size *= 2;
		v.resize(size+1);
	}
	void set(int n) {
		while(n <= size) {
			v[n]++;
			n += (n & (-n));
		}
	}
	ll get(int n) {
		ll ans = 0;
		while(n > 0) {
			// cout << n << ' ';
			ans += v[n];
			n -= (n & (-n));
		}
		return ans;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	FTree ft;
	while(t--) {
		vec.resize(4);
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++) {
			if(s.at(i) == 'A') vec[0].push_back(i);
			else if(s.at(i) == 'N') vec[1].push_back(i);
			else if(s.at(i) == 'O') vec[2].push_back(i);
			else vec[3].push_back(i);
		}
		vector<int> v = {0, 1, 2, 3}, v2;
		ll best = -1;
		string s2 = "ANOT";
		do {
			ll ans = 0;
			int x, y;
			x = y = -1;
			ft.init(s.size());
			for(int i = 0; i < 4; i++) {
				// x = y;
				// y = x + vec[v[i]].size();
				for(int j = 0; j < vec[v[i]].size(); j++) {
					ans += vec[v[i]][j] - ft.get(vec[v[i]][j]+1);
					ft.set(vec[v[i]][j]+1);
				}
			}
			// for(int i = 0; i < 4; i++) {
			// 	for(int j = 0; j < vec[v[i]].size(); j++) cout << s2.at(v[i]);
			// }
			// cout << ' ' << ans << '\n';
			if(ans > best) {
				v2 = v;
				best = ans;
			}
		} while(next_permutation(v.begin(), v.end()));
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < vec[v2[i]].size(); j++) cout << s2.at(v2[i]);
		}
		cout << '\n';
		vector<vector<int>>().swap(vec);
	}
}