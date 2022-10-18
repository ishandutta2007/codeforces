#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

vector <int> order;
bool mr[100500];
vector <int> g[100500];

void dfs(int nom) {
	mr[nom] = 1;
	for (int i = 0; i < g[nom].size(); i++) {
		if (mr[g[nom][i]]) {
			continue;
		}
		dfs(g[nom][i]);
	}
	order.push_back(nom);
}

int kurs[100500];
bool zn[100500];

int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> kurs[i];
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		for (int j = 0 ;j < t; j++) {
			int a;
			cin >> a;
			g[i].push_back(a);
		}
	}
	for (int i = 0; i < k; i++) {
		if (!mr[kurs[i]]) {
			dfs(kurs[i]);
		}
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++) {
		zn[order[i]] = 1;
		for (int j = 0 ;j < g[order[i]].size(); j++) {
			if (zn[g[order[i]][j]]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << order.size() << endl;
	reverse(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++) {
		cout << order[i] << " ";
	}
}