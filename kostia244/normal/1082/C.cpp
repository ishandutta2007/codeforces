#include <bits/stdc++.h>

using namespace std;

int sumup(vector<int>& a, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, s, r, maxsize = 0;
	cin >> n >> m;
	vector<vector<int>> a(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> s >> r;
		a[s].push_back(r);
	}
	for (int i = 1; i <= m; i++) {
		sort(a[i].begin(), a[i].end(), greater<int>());
		maxsize = max(maxsize, (int)a[i].size());
	}
	sort(a.begin(), a.end(), [](const vector<int>& a, const vector<int>& b) {
		return a.size() > b.size();
	});

	int maxsum = 0;
	for(int i = maxsize; i > 0; i--) {
		int sum = 0, t;
		for(int j = 0; j < m && a[j].size() >= i; j++) {
			t = sumup(a[j], i);
			if(t > 0)
				sum += t;
		}
		maxsum = max(maxsum, sum);
	}
	cout << max(maxsum, 0);
}