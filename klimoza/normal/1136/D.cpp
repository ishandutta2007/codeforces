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
long double eps = 1e-8;

vector<int> p;
vector<int> pmax;
vector<vector<int>> edge;

bool cmp(int x, int y) {
	return p[x] < p[y];
}

bool cmp2(int x, int y) {
	return pmax[x] > pmax[y];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	p.resize(n);
	edge.resize(n);
	pmax.resize(n);
	int t;
	vector<int> h(n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> t; t--;
		p[t] = i + 1;
		pmax[t] = i + 1;
		h[i] = t;
		if (i ==( n - 1)) c = t;
	}
	int t1, t2;
	set<int> f;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
		if (t2 == c) f.insert(t1);
	}
	int cur = n;
	int cnt = 1;
	for (int i = n - 2; i >= 0; i--) {
		int t = h[i];
		sort(edge[t].begin(), edge[t].end(), cmp);
		for (int j : edge[t]) {
			if (p[j] < p[t]) continue;
			if (p[j] <= (pmax[t] + cnt)) pmax[t]++;
		}
		if (f.find(t) != f.end() && pmax[t] >= (cur - 1)) {
			cnt++;
			cur--;
		}
	}
	//for (int i = 0; i < n; i++) {
	//	cout << pmax[i] << endl;
	//}
	cout << n - cur << endl;
	//system("pause");
	return 0;
}