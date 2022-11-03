#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 200001;
int c[MAXN];
vector<int> g[MAXN];
bool mkd[MAXN];
map<int, int> colors;
vector<int> v;
int cnt;
int cnt2;

void dfs(int v){
    cnt++;
    colors[c[v]]++;
    if(colors[c[v]] > cnt2){
        cnt2 = colors[c[v]];
    }
    mkd[v] = true;
    for(auto u: g[v]){
        if(!mkd[u]){
            dfs(u);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);

    int ans = 0;
    int n, m, k;
    int l, r;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
        c[i]--;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", &l, &r);
        l--;
        r--;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    for(int i = 0; i < n; i++){
        if(mkd[i]){
            continue;
        }
        cnt2 = 0;
        colors.clear();
        v.clear();
        cnt = 0;
        dfs(i);
        ans += cnt - cnt2;
    }
    printf("%d", ans);
    return 0;
}