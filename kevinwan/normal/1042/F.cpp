#pragma GCC optimize "O3"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,mmx,popcnt,tune=native"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e6+10;
int n,k,ans;
vector<int>g[mn];
int mo[mn];
void dfs(int x,int p){
    vector<int>v;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        v.push_back(y);
    }
    sort(v.begin(),v.end(),[](int a,int b){return mo[a]<mo[b];});
    int re=-1;
    if(v.size()&&mo[v[0]]+1<=k)re=0;
    for(int i=1;i<v.size();i++)if(mo[v[i]]+mo[v[i-1]]+2<=k)re=i;
    for(int i=re+1;i<v.size();i++)ans++;
    if(g[x].size()>1)mo[x]=0xc0c0c0c0;
    else mo[x]=0;
    for(int i=0;i<=re;i++)mo[x]=max(mo[x],mo[v[i]]+1);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int r=-1;
    for(int i=1;i<=n;i++)if(g[i].size()>1){
        r=i;
    }
    dfs(r,0);
    ans+=(mo[r]>=0);
    printf("%d",ans);
}