#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 210;

vector<vector<int > > g;
char marked[nmax];
int parent[nmax];

void dfs(int v, int p)
{
    parent[v] = p;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int height[nmax];
char used[nmax];

void dfs_solve(int v, int p)
{
    parent[v] = p;
    height[v] = 0;
    used[v] = true;
    for (int to : g[v]) {
        if (to != p && !marked[to]) {
            dfs_solve(to, v);
            height[v] = max(height[v], 1 + height[to]);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            int len = 0;
            memset(parent, 0, nmax * sizeof(int));
            dfs(i, i);
            memset(marked, 0, nmax * sizeof(char));
            int curr = j;
            do {
                ++len;
                marked[curr] = true;
                curr = parent[curr];
            } while (curr != i);
            marked[i] = true;
            memset(height, 0, nmax * sizeof(int));
            memset(used, 0, nmax * sizeof(char));
            for (int k = 0; k < n; ++k) {
                if (!used[k] && !marked[k]) {
                    dfs_solve(k, k);
                }
            }
            int len2 = 0;
            for (int k = 0; k < n; ++k) {
                if (!marked[k]) {
                    len2 = max(len2, height[k]);
                    vector<int> h;
                    int to_max1 = -1;
                    for (int to : g[k]) {
                        if (!marked[to] && to != parent[k]) {
                            if (to_max1 == -1 || height[to] > height[to_max1]) {
                                to_max1 = to;
                            }
                        }
                    }
                    int to_max2 = -1;
                    for (int to : g[k]) {
                        if (!marked[to] && to != parent[k]) {
                            if ((to_max2 == -1 || height[to] > height[to_max2]) && to != to_max1) {
                                to_max2 = to;
                            }
                        }
                    }
                    if (to_max2 != -1) {
                        len2 = max(len2, height[to_max1] + height[to_max2] + 2);
                    }
                }
             }
             ans = max(ans, len * len2);
        }
    }

    cout << ans << "\n";

}