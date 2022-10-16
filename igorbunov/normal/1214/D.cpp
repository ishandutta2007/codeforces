#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

const int MAXN = 1000000;
vector<int> g[MAXN];
vector<int> tin(MAXN);
vector<int> fup(MAXN);
vector<int> used(MAXN);
int timer = 0;
 
bool ans = 0;
 
int n, m;

void dfs(int v, int p = -1) {
	used[v] = 1;
    tin[v] = timer++;
    fup[v] = tin[v];
    int ch = 0;
    for(int u: g[v]) {
        if(u == p) {
        	continue;
        }
        if(used[u] == 1) {
            fup[v] = min(fup[v], tin[u]);
        } else{
            if (v == (n - 1) * m + m - 1) {
            	break;
            }
            dfs(u,v);
            fup[v] = min(fup[v], fup[u]);
            if( fup[u] >= tin[v] && p != -1) {
                ans = 1;
            }
            ch++;
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> arr(n, vector<bool>(m, 0));
    vector<vector<int>> dp1(n, vector<int>(m, 0));
    vector<vector<int>> dp2(n, vector<int>(m, 0));
    dp2[n - 1][m - 1] = 1;
    dp1[0][0] = 1;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            arr[i][j] = (c == '#');
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

        	if (dp1[i][j] || arr[i][j]) {
        		continue;
        	}

            if (i > 0) {
            	dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
            }

            if (j > 0) {
            	dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            if (dp2[i][j] || arr[i][j]) {
        		continue;
        	}

            if (i != n - 1) {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
            }
            if (j != m - 1) {
                dp2[i][j] = max(dp2[i][j], dp2[i][j + 1]);
            }
            dp2[i][j] *= dp1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n - 1 && dp2[i][j] && dp2[i + 1][j]) {
                g[i * m + j].push_back(i * m + m + j);
                g[i * m + m + j].push_back(i * m + j);
            }

            if (j < m - 1 && dp2[i][j] && dp2[i][j + 1]){
                g[i * m + j].push_back(i * m + 1 + j);
                g[i * m + 1 + j].push_back(i * m + j);
            }
        }
    }
    dfs(0, -1);
    if(dp2[0][0] == 0){
        cout << 0 << endl;
    } else{
        cout << 2 - ans << endl;
    }
}