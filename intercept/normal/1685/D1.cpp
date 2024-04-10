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
const int M=209;
int n,m;
int p[M],b[M],vis[M],ans[M];
int f[M];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    if(find(x)==find(y))return;
    f[find(x)]=find(y);
}
void solve(){
    for(int i=1;i<=n;++i)vis[i]=0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            int x=i;
            vis[x]=1;
            x=p[x];
            while(x!=i){
                merge(x,i);
                vis[x]=1;
                x=p[x];
            }
        }
    }
}
void insert(int x,int y){
    for(int i=n;i>y;--i)ans[i]=ans[i-1];
    ans[y]=x;
}
void change(int x,int y){
    insert(x,y);
    int z=b[x];
    while(z!=x){
        y++;
        insert(z,y);
        z=b[z];
    }
}
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&p[i]);
        b[p[i]]=i;
        f[i]=i;
    }
    solve();
    change(1,1);
    for(int i=1;i<=n;++i){
        if(ans[i]!=n&&find(ans[i])!=find(ans[i]+1)){
            merge(ans[i],ans[i]+1);
            change(b[ans[i]+1],i+1);
        }
    }
    for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*

1
5
5 4 3 2 1

*/