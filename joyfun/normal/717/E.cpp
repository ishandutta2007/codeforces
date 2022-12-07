#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 2e5 + 7;
int n, a[N];
bool flag[N];
vector<int> e[N];
void dfs(int u, int p) {
    flag[u] = a[u] == -1;
    rep(i, 0, sz(e[u])) {
        int v = e[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        flag[u] |= flag[v];
    }
}
vector<int> ans;
void DFS(int u, int p) {
    ans.pb(u);
    a[u] = -a[u];
    rep(i, 0, sz(e[u])) {
        int v = e[u][i];
        if (v == p)
            continue;
        DFS(v, u);
        ans.pb(u), a[u] = -a[u];
    }
    rep(i, 0, sz(e[u])) {
        int v = e[u][i];
        if (v == p)
            continue;
        if (a[v] == -1) {
            ans.pb(v);
            ans.pb(u), a[u] = -a[u];
        }
    }
}
int main() {
    scanf("%d", &n);
    rep(i, 1, n + 1)
       scanf("%d", &a[i]);
    rep(i, 1, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].pb(v), e[v].pb(u);
    }
    a[1] = -a[1];
    DFS(1, -1);
    if (a[1] == -1)
        ans.pop_back();
    rep(i, 0, sz(ans)) {
         if (i)
             putchar(' ');
         printf("%d", ans[i]);
    }
    return 0;
}