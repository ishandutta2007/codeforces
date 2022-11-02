#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n, p[200005], indeg[200005], cc, ans;

vector<int> cyc[200005];
queue<int> q;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        indeg[p[i]]++;
    }
    for(int i=1;i<=n;i++) {
        if(!indeg[i]) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(--indeg[p[cur]] == 0) q.push(p[cur]);
    }
    for(int i=1;i<=n;i++) {
        if(indeg[i]) {
            for(int j=i;indeg[j];j=p[j]) {
                indeg[j] = 0;
                cyc[cc].push_back(j);
            }
            cc++;
        }
    }
    int mv = inf, midx = -1;
    for(int i=0;i<cc;i++) {
        if(cyc[i].size()<mv) {
            mv = cyc[i].size();
            midx = i;
        }
    }
    if(mv != 1) {
        p[cyc[midx][0]] = cyc[midx][0];
        ans++;
    }
    for(int i=0;i<cc;i++) {
        if(i == midx) continue;
        p[cyc[i][0]] = cyc[midx][0];
        ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
}