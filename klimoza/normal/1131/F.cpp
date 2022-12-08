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
ll mod = 998244353;

vector<int> p;
vector<int> sz;
vector<pair<int, int>>bd;
vector<pair<int, int>> f;

void make_par(int n) {
	p.resize(n);
	sz.resize(n);
	bd.resize(n);
	f.resize(n);
	for (int i = 0; i < n;i++) {
		p[i] = i;
		sz[i] = 1;
		bd[i] = { i, i };
		f[i] = { -1, -1 };
	}
}

int get_par(int v) {
	if (v == p[v]) return v;
	return p[v] = get_par(p[v]);
}

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	if (f[bd[b].second].second == -1 && f[bd[a].first].first == -1) {
		f[bd[b].second].second = bd[a].first;
		f[bd[a].first].first = bd[b].second;
		bd[a].first = bd[b].first;
		bd[b].second = bd[a].second;
	}
	else {
		swap(a, b);
		f[bd[b].second].second = bd[a].first;
		f[bd[a].first].first = bd[b].second;
		bd[a].first = bd[b].first;
		bd[b].second = bd[a].second;
	}
}



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	make_par(n);
	int t1, t2;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2; t1--; t2--;
		merge(t1, t2);
	}
	int ind = 0;
	while (f[ind].first != -1) ind = f[ind].first;
	while (ind != -1) {
		cout << ind + 1<< " ";
		ind = f[ind].second;
	}
	cout << endl;
	//system("pause");
	return 0;
}