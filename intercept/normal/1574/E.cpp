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
const int M=1e6+9;
int n,m,q;
int c[3][2],b[2],y[M][2],x[M][2];
map<int,int>mp[M];
void change(int u,int v,int w,int d){
    b[w^((u+v)&1)]+=d;
    c[2-(bool)y[v][0]-(bool)y[v][1]][0]--;
    y[v][(w^u)&1]+=d;
    c[2-(bool)y[v][0]-(bool)y[v][1]][0]++;
    c[2-(bool)x[u][0]-(bool)x[u][1]][1]--;
    x[u][(w^v)&1]+=d;
    c[2-(bool)x[u][0]-(bool)x[u][1]][1]++;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    c[2][0]=m;
    c[2][1]=n;
    for(int i=1;i<=q;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w==-1){
            if(mp[u].count(v)&&mp[u][v]!=-1){
                w=mp[u][v];
                change(u,v,w,-1);
                mp[u][v]=-1;
            }
            
        }
        else{
            if(mp[u].count(v)&&mp[u][v]!=-1){
                int k=mp[u][v];
                change(u,v,k,-1);
            }
            mp[u][v]=w;
            change(u,v,w,1);
        }
        int ans=(kpow(2,c[2][0])*(!c[0][0])+kpow(2,c[2][1])*(!c[0][1]))%mod;
        ans=(ans+mod-(!b[0])-(!b[1]))%mod;
        printf("%d\n",ans);
    }
    return 0;
}
/*

0 0 1 1 2 3
*/