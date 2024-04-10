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
int a[M],b[M],c[M];
vector<int>g[M];
void work(){
    cin>>n;
    int ma=0;
    for(int i=1;i<=n;++i)b[i]=0,g[i].clear();
    for(int i=1;i<=n;++i)cin>>a[i],b[a[i]]++;
    for(int i=1;i<=n;++i)cin>>c[i],g[c[i]].emplace_back(i);
    for(int i=1;i<=n;++i){
        if(b[ma]<b[i])ma=i;
    }
    b[ma]=0;
    queue<int>q;
    q.push(ma);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto o:g[u]){
            if(a[o]==c[o])continue;
            b[a[o]]--;
            if(b[a[o]]==0)q.push(a[o]);
        }
    }
    bool bol=0;
    for(int i=1;i<=n;++i)bol|=(b[i]>0);
    puts(bol?"WA":"AC");
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