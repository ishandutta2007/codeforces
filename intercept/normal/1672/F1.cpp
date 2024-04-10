#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
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
const int M=2e5+9;
int n;
int a[M],b[M],id[M],ans[M];
vector<int>g[M];
void work(){
    cin>>n;
    for(int i=1;i<=n;++i)b[i]=0,id[i]=i,g[i].clear();
    for(int i=1;i<=n;++i)cin>>a[i],b[a[i]]++,g[a[i]].emplace_back(i);
    sort(id+1,id+n+1,[&](const int&l,const int&r){return b[l]<b[r];});
    for(int i=1;i<n;++i){
        int x=id[i],y=id[i+1];
        for(int j=0;j<g[x].size();++j){
            swap(g[x][j],g[y][j]);
        }
    }
    for(int i=1;i<=n;++i){
        int x=id[i];
        for(auto o:g[x]){
            ans[o]=x;
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
    cout<<endl;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
6
2
1 2
3
1 1 2
4
1 2 1 2
5
1 1 1 2 2
6
1 1 2 2 2 2
*/