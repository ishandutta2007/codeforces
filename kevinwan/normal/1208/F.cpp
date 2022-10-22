#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=1<<21;
int a[mn];
pii bes[mn];
inline pii mrg(pii a,pii b){
    if(b.first>a.first){
        a.second=a.first,a.first=b.first;
        if(b.second>a.second)a.second=b.second;
    }
    else if(b.first>a.second)a.second=b.first;
    return a;
}
int main() {
    int n,i,j;
    scanf("%d",&n);
    memset(bes,0xc0,sizeof(bes));
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[i]=x;
        bes[x]=mrg(bes[x],{i,0xc0c0c0c0});
    }
    for(i=0;i<21;i++)for(j=0;j<mn;j++){
        if(!((j>>i)&1))bes[j]=mrg(bes[j],bes[j+(1<<i)]);
    }
    int ans=-1;
    for(i=0;i<n-2;i++){
        int cur=a[i],u=0;
        for(j=20;j>=0;j--){
            if((cur>>j)&1)continue;
            if(bes[u+(1<<j)].second>i)u+=1<<j,cur+=1<<j;
        }
        ans=max(ans,cur);
    }
    printf("%d",ans);
}