#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

vector<vector<int>> edge;
ll cnt1 = 0;
ll cnt2 = 0;

void dfs(int v, int col, int p) {
	if (col) cnt1++;
	else cnt2++;
	for (int u : edge[v]) {
		if (u == p) continue;
		dfs(u, (col + 1) % 2, v);
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int t1, t2;
	edge.resize(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	dfs(0, 0, -1);
	//cout << cnt1 << " " << cnt2 << endl;
	cout << cnt1 * cnt2 - n + 1<< endl;
	//system("pause");
	return 0;
}