#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int f = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            f += i - cnt;
            cnt++;
        }
	}
	vector<vector<int>> ans(k);
	unordered_set<int> pos;
	for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            pos.insert(i);
        }
	}
	for (int j = 0; j < k; j++) {
        if (f == 0 || (k - j) > f) {
            cout << -1;
            return 0;
        }
        vector<int> c;
        int p = max(0ll, f - (k - j) + 1);
        for (auto i : pos) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                c.push_back(i);
            }
            if (c.size() == p) break;
        }
        for (int i = 0; i < c.size(); i++) {
            ans[j].push_back(c[i] + 1);
            swap(s[c[i]], s[c[i] + 1]);
            pos.erase(c[i]);
            f--;
        }
        for (int i = 0; i < c.size(); i++) {
            int x = c[i];
            if (x > 0 && s[x - 1] == 'R' && s[x] == 'L') {
                pos.insert(x - 1);
            }
            if (x < n - 2 && s[x + 1] == 'R' && s[x + 2] == 'L') {
                pos.insert(x + 1);
            }
        }
	}
	if (f != 0) {
        cout << -1;
        return 0;
	}
	for (int i = 0; i < k; i++) {
        cout << (int) ans[i].size() << " ";
        for (auto x : ans[i]) cout << x << " ";
        cout << '\n';
	}
}