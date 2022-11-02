#include<bits/stdc++.h>
using namespace std;
int n,deg[1000005],sum[1000005];
queue<int>q;
vector<pair<int,int> >ans;

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d%d",&deg[i],&sum[i]);
        if(deg[i]==1) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(deg[cur]<1) continue;
        ans.push_back({cur,sum[cur]});
        sum[sum[cur]] ^= cur;
        if(--deg[sum[cur]]==1) q.push(sum[cur]);
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}