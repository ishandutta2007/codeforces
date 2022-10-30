// Hydro submission #6184f53d34fa933f029da06d@1639371814272
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],l[N*30],r[N*30],tr[N*30][2],tot=1;
void add(int x,int id){
    int now=1;
    if(!l[now])l[now]=id;
    r[now]=id;
    for(int i=30;i>=0;i--){
        int y=(x>>i)&1;
        if(!tr[now][y])tr[now][y]=++tot;
        now=tr[now][y];
        if(!l[now])l[now]=id;
        r[now]=id;
    }
}
int ask(int x,int now,int dep){
    int ans=0;
    for(int i=dep;i>=0;i--){
        int y=(x>>i)&1;
        if(tr[now][y])now=tr[now][y];
        else now=tr[now][y^1],ans+=(1<<i);
    }
    return ans;
}
ll dfs(int now,int dep){
    if(dep<0)return 0;
    //cout<<tr[now][0]<<' '<<tr[now][1]<<endl;
    if(tr[now][0]&&tr[now][1]){
        int L=tr[now][0],R=tr[now][1];
        int ans=1e9;
        if(r[L]-l[L]<r[R]-l[R]) for(int i=l[L];i<=r[L];i++)ans=min(ans,ask(a[i],R,dep-1)+(1<<dep));
        else for(int i=l[R];i<=r[R];i++)ans=min(ans,ask(a[i],L,dep-1)+(1<<dep));
        return dfs(L,dep-1)+dfs(R,dep-1)+ans;
    }
    if(tr[now][0])return dfs(tr[now][0],dep-1);
    if(tr[now][1])return dfs(tr[now][1],dep-1);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)add(a[i],i);
    printf("%lld",dfs(1,30));
    return 0;
}