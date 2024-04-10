#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 998244353;

vector<int> p;
vector<int> sz;

void make_set(int n) {
	p.resize(n);
	sz.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int get_par(int n) {
	if (n == p[n]) return n;
	return p[n] = get_par(p[n]);
}

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	make_set(n);
	for (int i = 0; i < m; i++) {
		int k, last, t;
		cin >> k;
		if (!k) continue;
		cin >> last;
		k--; last--;
		while (k--) {
			cin >> t; t--;
			merge(last, t);
			last = t;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sz[get_par(i)] << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}