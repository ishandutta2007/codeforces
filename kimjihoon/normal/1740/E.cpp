#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int d[100009], h[100009];
vector<int> v[100009];

void dfs(int n)
{
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		dfs(tn);
		h[n] = max(h[n], h[tn] + 1);
		d[n] += d[tn];
	}
	d[n] = max(d[n], h[n] + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		v[p].push_back(i);
	}
	dfs(1);
	cout << d[1] << '\n';
	return 0;
}