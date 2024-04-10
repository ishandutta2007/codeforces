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
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 11;
const int maxk = 1010;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, k, w;
string a[maxk][maxn];
int p[maxk], dist[maxk], vis[maxk];
int d[maxk][maxk];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> m >> k >> w) {
        for (int l = 0; l < k; l++) {
            for (int i = 0; i < n; i++) {
                cin >> a[l][i];
            }
        }
     
        for (int l = 0; l < k; l++) {
            for (int r = l + 1; r < k; r++) {
                d[l][r] = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        d[l][r] += a[l][i][j] != a[r][i][j];
                    }
                }
                d[l][r] *= w;
                d[l][r] = min(d[l][r], n * m);
                d[r][l] = d[l][r];
            }
        }

        vector<pair<int, int> > ans;
        for (int i = 0; i < k; i++) {
            dist[i] = n * m;
            p[i] = 0;
            vis[i] = 0;
        }
        int res = 0;
        for (int it = 0; it < k; it++) {
            int v = -1;
            for (int i = 0; i < k; i++) {
                if (!vis[i] && (v == -1 || dist[v] > dist[i])) {
                    v = i;
                }
            }
            vis[v] = 1;
            res += dist[v];
            ans.push_back(make_pair(v + 1, p[v]));
            for (int i = 0; i < k; i++) {
                if (dist[i] > d[v][i]) {
                    p[i] = v + 1;
                    dist[i] = d[v][i];
                }
            }
        }
        
        cout << res << endl;
        for (int i = 0; i < k; i++) cout << ans[i].first << " " << ans[i].second << endl;
    }
    
	return 0;
}