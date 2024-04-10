#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[200005], sz, mx, cc;
int cnt[200005], used[200005], vis[200005];
vector<int> cg[200005];

void dfs (int cur) {
    if(vis[cur]) return;
    sz++;
    if(used[a[cur]] != cc) {
        used[a[cur]] = cc;
        cnt[a[cur]] = 0;
    }
    if(++cnt[a[cur]] > mx) mx = cnt[a[cur]];
    vis[cur] = true;
    for(int i=0;i<cg[cur].size();i++) {
        dfs(cg[cur][i]);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) {
        int A, B;
        scanf("%d%d",&A,&B);
        cg[A].push_back(B);
        cg[B].push_back(A);
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        cc++; dfs(i);
        ans += sz - mx;
        sz = 0; mx = 0;
    }
    printf("%d",ans);
}