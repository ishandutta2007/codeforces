#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
int a[mn],b[mn],s[mn],c[mn];
int n;
ll tot;
vector<int>g[mn];
void dfs(int x,int p){
    ll k=0;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]+=s[y];
        c[x]+=c[y];
    }
    if(b[x]){
        for(int y:g[x]){
            if(y==p)continue;
            k+=c[y]*(c[x]-c[y])+(s[y]-c[y])*((s[x]-c[x])-(s[y]-c[y]));
        }
        k/=2;
        k+=s[x]-c[x];
    }
    else{
        for(int y:g[x]){
            if(y==p)continue;
            k+=c[y]*((s[x]-c[x])-(s[y]-c[y]));
        }
        k+=c[x];
    }
    s[x]++;
    if(b[x])c[x]=s[x]-c[x];
    tot+=k;
}
ll solve(){
    memset(s,0,sizeof(s));
    memset(c,0,sizeof(c));
    tot=0;
    dfs(1,0);
    return tot;
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(i=0;i<n-1;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        g[c].push_back(d);
        g[d].push_back(c);
    }
    ll ans=0;
    for(i=0;i<20;i++){
        for(j=1;j<=n;j++)b[j]=(a[j]>>i)&1;
        ans+=solve()<<i;
    }
    for(i=1;i<=n;i++)ans+=a[i];
    printf("%lld",ans);
}