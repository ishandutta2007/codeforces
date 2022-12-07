#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acos(-1.);

const int N = 32222;
const int M = 333;
const int K = M*M*2;
int f[N];
int a[N];

vector<int> g[M];
int go[2][M];
bool was[M];
 
bool dfs(int x, int level) {
    if (was[x]) {  
        return false;
    }
    was[x] = true;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (level == 1 && go[0][y] == x) continue;

        if (go[level][y] == -1 || dfs(go[level][y], level)) {
            go[level][y] = x;
            return true;
        }
    }
    return false;
}

int nxt[N];
int used[N];
 
int main() {
    for (int i = 2; i < N; ++i)
        if (!f[i]) {
            for (int j = i + i; j < N; j += i)
                f[j] = 1;
        }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector< pair<int, int> > A, B;
    for (int i = 0; i < n; ++i)
        if (a[i] & 1) {
            B.push_back(make_pair(a[i], i)); 
        } else {
            A.push_back(make_pair(a[i], i)); 
        }
    if (A.size() != B.size()) {
        cout << "Impossible" << endl;
        return 0;
    }

    int m = n / 2;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (!f[A[i].first + B[j].first]) g[i].push_back(j);
    
    memset(go, -1, sizeof(go));
    for (int i = 0; i < m; ++i) {
        memset(was, 0, sizeof(was));
        dfs(i, 0);
    }
    for (int i = 0; i < m; ++i) {
        memset(was, 0, sizeof(was));
        dfs(i, 1);
    }
    for (int i = 0; i < m; ++i) {
        if (go[0][i] == -1 || go[1][i] == -1) {
            cout << "Impossible" << endl;
            return 0;
        }
        nxt[ B[i].second ] = A[ go[0][i] ].second;
        nxt[ A[ go[1][i] ].second ] = B[i].second;
    }

    vector< vector<int> > ans; 
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            vector<int> add;
            int x = i;
            while (!used[x]) {
                used[x] = true;
                add.push_back(x + 1);
                x = nxt[x];
            }
            ans.push_back(add);
        }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); ++j)
            cout << " " << ans[i][j];
        cout << endl;
    }

    return 0;
}