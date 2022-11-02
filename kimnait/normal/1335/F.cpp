#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
#include <random>
#include <cassert>

using namespace std;
const int N = 107;
typedef long double type;
typedef long double LDB;
const long double INF = 1000000000;
const long double eps = 1e-9;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		string cc[n], mp[n];
		vector<int> in(n*m, 0), nxt(n*m, 0);
		vector<int> re_edge[n*m];
		for (int i = 0; i < n; i++)
			cin >> cc[i];
		for (int i = 0; i < n; i++)
			cin >> mp[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] == 'D') {
					nxt[i*m+j] = (i+1)*m+j;
					re_edge[(i+1)*m+j].push_back(i*m+j);
					in[(i+1)*m+j]++;
				} else if (mp[i][j] == 'U') {
					nxt[i*m+j] = (i-1)*m+j;
					re_edge[(i-1)*m+j].push_back(i*m+j);
					in[(i-1)*m+j]++;
				} else if (mp[i][j] == 'L') {
					nxt[i*m+j] = i*m+j-1;
					re_edge[i*m+j-1].push_back(i*m+j);
					in[i*m+j-1]++;
				} else if (mp[i][j] == 'R') {
					nxt[i*m+j] = i*m+j+1;
					re_edge[i*m+j+1].push_back(i*m+j);
					in[i*m+j+1]++;
				}
			}
		}
		queue<int> Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (in[i*m+j] == 0) {
					Q.push(i*m+j);
				}
			}
		}
		while (!Q.empty()) {
			int v = Q.front(); Q.pop();
			in[ nxt[v] ]--;
			if (!in[ nxt[v] ]) Q.push(nxt[v]);
		}
		vector<int> ck(n*m, -1);
		int v1 = 0, v2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!in[i*m+j] || ck[i*m+j] != -1) continue ;
				int v = i*m+j, cnt = 0;
				queue<int> buf;
				vector<bool> ok; 
				do {
					v = nxt[v];
					ck[v] = cnt;
					buf.push(v);
					int xx = v / m;
					int yy = v % m;
					if (cc[xx][yy] == '0') ok.push_back(true);
					else ok.push_back(false);
					cnt++;
				} while (v != i*m+j);
				while (!buf.empty()) {
					int v = buf.front(); buf.pop();
					for (int x : re_edge[v]) {
						if (ck[x] != -1) continue ;
						ck[x] = (ck[v] - 1 + cnt) % cnt;
						if (cc[x/m][x%m] == '0') ok[ck[x]] = true;
						buf.push(x);
					}
				}
				v1 += cnt;
				for (bool x : ok)
					if (x == true) v2++;
			}
		}
		cout << v1 << ' ' << v2 << '\n';
	}
	return 0;
}