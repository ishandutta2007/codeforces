#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,tot,mx,q;
int a[N*2];
pair<int,int>b[N];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        mx=max(mx,a[i]);
    for(;a[tot+1]!=mx;){
        ++tot;
        b[tot]={a[tot],a[tot+1]};
        a[n+tot]=min(a[tot],a[tot+1]);
        a[tot+1]=max(a[tot],a[tot+1]);
    }
    for(;q--;){
        long long m;
        scanf("%I64d",&m);
        if(m<=tot)
            printf("%d %d\n",b[m].first,b[m].second);
        else
            printf("%d %d\n",mx,a[tot+2+(m-tot-1)%(n-1)]);
    }
    return 0;
}