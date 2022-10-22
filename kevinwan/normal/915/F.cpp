#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
ll a[mn];
int o[mn],po[mn];
int p[mn],s[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
void u(int a,int b){
    a=f(a),b=f(b);
    if(a==b)return;
    if(s[a]<s[b])swap(a,b);
    s[a]+=s[b];
    p[b]=a;
}
vector<int>g[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    iota(o+1,o+n+1,1);
    sort(o+1,o+n+1,[](int x,int y){return a[x]<a[y];});
    for(int i=1;i<=n;i++)po[o[i]]=i;
    iota(p,p+mn,0);
    fill(s,s+mn,1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll sum=1,ssum=1;
        int x=o[i];
        for(int y:g[x])if(po[y]<po[x])sum+=s[f(y)],ssum+=1LL*s[f(y)]*s[f(y)],u(x,y);
        ans+=(sum*sum-ssum)/2*a[x];
    }
    iota(p,p+mn,0);
    fill(s,s+mn,1);
    for(int i=n;i;i--){
        ll sum=1,ssum=1;
        int x=o[i];
        for(int y:g[x])if(po[y]>po[x])sum+=s[f(y)],ssum+=1LL*s[f(y)]*s[f(y)],u(x,y);
        ans-=(sum*sum-ssum)/2*a[x];
    }
    printf("%lld",ans);
}