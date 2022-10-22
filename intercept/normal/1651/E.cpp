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
const int M=3009;

int n;
vector<int>g[M],p;
bool vis[M];
ll ans=0;
void dfs(int u){
    p.eb(u);
    vis[u]=1;
    for(auto v:g[u]){
        if(!vis[v])dfs(v);
    }
}
void solve(){
    int l=1e9,r=0,L=1e9,R=0;
    int m=p.size();
    for(int i=0;i<m;++i)p.eb(p[i]);
    for(int i=0;i<m;++i){
        int x=p[i];
        if(x<=n){
            l=min(l,x);
            r=max(r,x);
        }
        else{
            L=min(L,x);
            R=max(R,x);
        }
    }
    ans+=1ll*(m/2)*(n-r+1)*(l)*(n*2-R+1)*(L-n);
    for(int i=1;i<=m;++i){
        l=1e9,r=0,L=1e9,R=0;
        for(int j=i;j<i+m;++j){
            int x=p[j];
            if(x<=n){
                l=min(l,x);
                r=max(r,x);
            }
            else{
                L=min(L,x);
                R=max(R,x);
            }
            int y=p[i-1],z=p[j+1];
            ll v=(j-i+1)/2;
            int lx=0,rx=n,ly=n,ry=n*2;
            if(y<=n){
                if(y>=l&&y<=r)continue;
                if(y<l)lx=max(lx,y);
                else rx=min(rx,y-1);
            }
            else{
                if(y>=L&&y<=R)continue;
                if(y<L)ly=max(ly,y);
                else ry=min(ry,y-1);
            }
            if(z<=n){
                if(z>=l&&z<=r)continue;
                if(z<l)lx=max(lx,z);
                else rx=min(rx,z-1);
            }
            else{
                if(z>=L&&z<=R)continue;
                if(z<L)ly=max(ly,z);
                else ry=min(ry,z-1);
            }
            ans+=v*(rx-r+1)*(l-lx)*(ry-R+1)*(L-ly);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n*2;++i){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            p.clear();
            dfs(i);
            solve();
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
3 3
WWW
WBB
WBW
*/