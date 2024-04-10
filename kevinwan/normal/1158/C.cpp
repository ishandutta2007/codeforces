#include <bits/stdc++.h>
using namespace std;
const int mn=5e5+10;
int nxt[mn],v[mn];
pair<int,int> idk[mn];
void solve(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",nxt+i);
        if(nxt[i]==-1)nxt[i]=i+1;
    }
    stack<int>s;
    s.push(n+1);
    for(i=1;i<=n;i++){
        while(s.top()==i)s.pop();
        if(s.top()<nxt[i]){
            printf("-1\n");
            return;
        }
        s.push(nxt[i]);
    }
    for(i=1;i<=n;i++)idk[i]={-nxt[i],i};
    sort(idk+1,idk+1+n);
    for(i=1;i<=n;i++)idk[i].first*=-1;
    int cur=n;
    v[n+1]=n+1;
    for(i=1;i<=n;i++)v[i]=0;
    for(i=1;i<=n;i++){
        if(!v[idk[i].second])v[idk[i].second]=cur--;
        if(!v[idk[i].first])v[idk[i].first]=cur--;
    }
    for(i=1;i<=n;i++)printf("%d ",v[i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}