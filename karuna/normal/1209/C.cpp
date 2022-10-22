#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n, x;
string s;
vector<int> arr[10];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i=0; i<n; i++)
			arr[s[i]-'0'].push_back(i);

		int cur = -1, idx = 10;
		for (int i=0; i<=9; i++) {
			if (arr[i].empty()) continue;
			if (cur > arr[i].front()) {
				idx = i; break;
			}
			cur = arr[i].back();
		}

		if (idx == 10) {
			for (int i=0; i<n; i++) cout << '1';
			cout << '\n';
		}
		else {
			int x = lower_bound(arr[idx].begin(), arr[idx].end(), cur) - arr[idx].begin();

			bool flag = true;
			cur = arr[idx][x-1];

			for (int i=idx+1; i<=9; i++) {
				if (arr[i].empty()) continue;
				if (cur > arr[i].front()) {
					flag = false; break;
				}
				cur = arr[i].back();
			}

			if (!flag) cout << '-' << '\n';
			else {
				vector<int> ans(n);

				for (int i=0; i<idx; i++) {
					for (auto x : arr[i]) ans[x] = 1;
				}
				for (int i=x; i<arr[idx].size(); i++)
					ans[arr[idx][i]] = 1;

				for (auto x : ans)
					cout << (x==1 ? '1' : '2');
				cout << '\n';
			}
		}

		for (int i=0; i<=9; i++) {
			arr[i].resize(0);
		}
	}
}