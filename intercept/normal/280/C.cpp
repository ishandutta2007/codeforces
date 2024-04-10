#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=100009;
int n;
vector<int>g[M];
double ans=0;
void dfs(int u,int fa,int deep){
    ans+=1.0/deep;
    for(auto v:g[u]){
        if(v!=fa)dfs(v,u,deep+1);
    }
}
int main(){
    cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1,0,1);
    cout<<fixed<<setprecision(9)<<ans<<endl;
    return 0;
}
/*
1
4
0 2 1 1073741823
4
1 2
2 3
1 3
3 4
000111111
123456123


------+-++++--++++--



*/