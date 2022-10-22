#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=2e5+10;
bool uni[mn];
int num[mn],dep[mn],ex[mn];
vector<int> g[mn];
ll ans,tot;
void setup(int x,int p){
    num[x]=uni[x];
    tot+=uni[x]*dep[x];
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        setup(y,x);
        num[x]+=num[y];
    }
}
void dfs(int x,int p){
    for(int y:g[x]){
        if(y==p)continue;
        if(num[y]-ex[x]>num[x]-num[y]){
            ans+=2LL*(num[x]-num[y])*dep[x];
            ex[y]=num[x]-num[y]+ex[x];
            dfs(y,x);
            return;
        }
    }
    ans+=1LL*(num[x]-ex[x])*dep[x];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k,x,i,a,b;
    cin>>n>>k;
    for(i=0;i<k<<1;i++){
        cin>>x;
        uni[x]=1;
    }
    for(i=0;i<n-1;i++)cin>>a>>b,g[a].push_back(b),g[b].push_back(a);
    setup(1,0);
    dfs(1,0);
    printf("%lld",tot-ans);
}