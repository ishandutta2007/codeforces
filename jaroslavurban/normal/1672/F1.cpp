#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	map<int, vector<int>> pos;
	int tmp = 0;
	for (int& v : a) { cin >> v; pos[v].push_back(tmp++); }
	while (pos.size()) {
		auto it = pos.begin();
		int curpos = it->second.back();
		int ognum = it->first;
		it->second.pop_back();
		if (it->second.empty()) it = pos.erase(it);
		else ++it;
		for (; it != pos.end();) {
			auto& [x, v] = *it;
			b[curpos] = x;
			curpos = v.back();
			v.pop_back();
			if (v.empty()) it = pos.erase(it);
			else ++it;
		}
		b[curpos] = ognum;
	}
	for (int v : b) cout << v << " "; cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}