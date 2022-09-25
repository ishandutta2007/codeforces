#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;

struct Friend {
	int l, r, f, p;

	bool operator< (const Friend &fr) const {
		return f < fr.f;
	}
};

int n, v, m, a[maxn];//, l[maxn], r[maxn], f[maxn];
int d[maxn][maxn];
Friend b[maxn];
vector<Friend> e[maxn];
pair<int, int> p[maxn][maxn];

void rec(int n, int x) {
	if (!n) return;
	int i = p[n][x].first, j = p[n][x].second;
	rec(i, j);
	cout << d[n][x] - d[i][j] << " ";
	for (int k = 0; k < d[n][x] - d[i][j]; k++)
		cout << e[i][k].p << " \n"[k == d[n][x] - d[i][j] - 1];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n >> v;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i].l >> b[i].r >> b[i].f; b[i].p = i + 1;
		for (int j = b[i].l; j <= b[i].r; j++)
			e[j - 1].push_back(b[i]);
	}

	for (int i = 0; i < n; i++)
		sort(e[i].begin(), e[i].end());

	memset(d, 255, sizeof(d));
	d[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < maxn; j++) if (d[i][j] != -1) {
			if (j + a[i] < v) continue;
			int cj = j;
			j -= min(j, v);
			int cur = a[i];
			if (j == 0) cur -= v - cj;
			for (int k = 0; k <= e[i].size(); k++) {
				if (cur >= 0) {
					if (d[i + 1][cur] < d[i][cj] + k) {
						d[i + 1][cur] = d[i][cj] + k;
						p[i + 1][cur] = make_pair(i, cj);
					}
				}
				if (k == e[i].size()) continue;
				int o = j;
				j -= min(j, e[i][k].f);
				if (j == 0)
					cur -= e[i][k].f - o;
			}



			j = cj;
		}
	}

	int ans = 0;
	for (int i = 0; i < maxn; i++)
		if (d[n][i] > d[n][ans])
			ans = i;

	cout << d[n][ans] << endl;
	rec(n, ans);

	return 0;
}