// Hydro submission #62c673e1c3a9fda5622ac2af@1657172961685
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 1;

int n, k;
vector<int> s, t;
vector<int> cnts(MAX);

bool can(int cnt) {
	t.clear();
	for (int i = 0; i < MAX; ++i) {
		int need = min(cnts[i] / cnt, k - int(t.size()));
		for (int j = 0; j < need; ++j) {
			t.push_back(i);
		}
	}
	return int(t.size()) == k;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k;
	s = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (auto c : s) {
		++cnts[c];
	}
	
	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (can(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (!can(r)) can(l);
	for (auto it : t) cout << it << " ";
	//cout << endl;
	
	return 0;
}