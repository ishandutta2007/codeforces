#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> p;
vector<bool> used;

void dfs(int v) {
	used[v] = 1;
	if (!used[p[v]])
		dfs(p[v]);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	p.resize(n);
	used.resize(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	int sum = 1;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum += b[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			ans++;
		}
	}
	if (ans == 1)
		ans = 0;
	cout << ans + (sum % 2);
	return 0;
}