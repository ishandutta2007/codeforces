#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

#define int long long
#define s second
#define f first
#define push_back emplace_back

int d[600][600];
int lol[600][600];


int kek[600][600];

int d1[600][600];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 1000000000000000LL;
			lol[i][j] = -1;
		}
		d[i][i] = 0;
	}
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		d[a][b] = w;
		d[b][a] = w;
		d1[a][b] = w;
		d1[b][a] = w;
		edges.push_back(make_pair(a, b));
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		lol[a][b] = w;
		lol[b][a] = w;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] < 1000000000000000LL && d[k][j] < 1000000000000000LL) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			kek[i][j] = -2;
			for (int k = 0; k < n; k++) {
				kek[i][j] = max(kek[i][j], lol[j][k] - d[i][k]);
			}
			if (kek[i][j] != -2) {
				//cout << i << " " << j << " " << kek[i][j] << endl;
			}
		}
	}

	int ans = 0;
	for (auto p: edges) {
		int a = p.first;
		int b = p.second;
		int w = d1[a][b];
		bool was = false;
		for (int i = 0; i < n; i++) {
			int now = d[i][a] + w;
			//cout << a << " " << b << " " << i << endl;
			//cout << now << " " << d[i][a] << " " << kek[b][i] << endl;
			if (kek[b][i] >= now) {
				was = true;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			int now = d[i][b] + w;
			if (kek[a][i] >= now) {
				was = true;
				break;
			}
		}
		//cout << a << " " << b << " " << was << endl;
		ans += was;
	}
	cout << ans;
}