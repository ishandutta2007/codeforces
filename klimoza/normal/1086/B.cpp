#pragma optimise('O3');
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;


int main() {
	cout.precision(15);
	int n;
	double s;
	cin >> n >> s;
	vector<vector<int>> edge(n);
	edge.resize(n);
	int t1, t2;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2;
		t1--; t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (edge[i].size() == 1) {
			cnt++;
		}
	}
	cout << (2 * s) / cnt << endl;
	//system("pause");
	return 0;
}