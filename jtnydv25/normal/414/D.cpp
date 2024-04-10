#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &x)
#define pb push_back
const int N = 1e5 + 10;
int cntdepth[N];
vector<int> con[N];
void dfs(int s, int p = 0, int d = 0){
    cntdepth[d]++;
    for(int v : con[s]){
        if(v != p)
            dfs(v, s, d + 1);
    }
}

int depth[N];
long long prefix[N];
int st[N], en[N];
int main(){
    int n, k, p;
    sd(n); sd(k); sd(p);
    for(int i = 1; i < n; i++){
        int u, v;
        sd(u); sd(v);
        con[u].pb(v);
        con[v].pb(u);
    }
    dfs(1);
    int sz = 0;
    for(int i = 1; i <= n; i++){
        st[i] = sz + 1;
        for(int j = 1; j <= cntdepth[i]; j++){
            depth[++sz] = i;
            prefix[sz] = prefix[sz - 1] + i;
        }
        en[i] = sz;
    }
    int ans = 0;
    for(int t = 1; t <= n; t++){
        if(st[t] > en[t])
            continue;
        int r = en[t];
        int lo = max(1, r - k + 1);
        int hi = r;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(t * 1ll * (r - mid + 1) - (prefix[r] - prefix[mid - 1]) <= p){
                hi = mid;
            }
            else lo = mid + 1;
        }
        ans = max(ans, r - lo + 1);
    }
    printf("%d\n", ans);
}