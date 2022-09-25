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


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, k;
string s[maxn];
bool vis[maxn][maxn];

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j) {
    if (!ok(i, j) || s[i][j] == '#' || vis[i][j]) return;
    vis[i][j] = 1;
    for (int l = 0; l < 4; l++) {
        dfs(i + dx[l], j + dy[l]);
    }
    if (k) {
        s[i][j] = 'X';
        k--;
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> m >> k) {
        for (int i = 0; i < n; i++) cin >> s[i];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] != '#' && !vis[i][j]) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << s[i] << endl;
        }
    }

	return 0;
}