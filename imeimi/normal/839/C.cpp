#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int n;
vector<int> edge[100001];

double dfs(int x, int p) {
	int t = 0; double pro = 0.0;
	for (int i : edge[x]) {
		if (i == p) continue;
		t += 1;
		pro += dfs(i, x);
	}
	if (t) return pro / t + 1.0;
	return 0.0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	printf("%.12lf\n", dfs(1, 0));
	return 0;
}