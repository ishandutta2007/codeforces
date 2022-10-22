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
const int M=4e5+9;
int n;
int a[M],b[M],d[M];
int c[M<<1],num=0;
vector<int>g[M];
vector<int>ans;
int tot=1,cur[M],head[M],vis[M];
struct E{
    int to,ne;
}e[M<<1];
void add(int u,int v){
    e[++tot]=E{v,head[u]};head[u]=tot;
    e[++tot]=E{u,head[v]};head[v]=tot;
}
void dfs(int u){
    for(int&i=cur[u];i;i=e[i].ne){
        if(vis[i])continue;
        vis[i]=vis[i^1]=1;
        int v=e[i].to;
        dfs(v);
    }
    ans.eb(u);
}
int main(){
    cin>>n;
    n--;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        c[++num]=a[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
        c[++num]=b[i];
    }
    for(int i=1;i<=n;++i){
        if(a[i]>b[i]){
            puts("-1");
            return 0;
        }
    }
    sort(c+1,c+num+1);
    num=unique(c+1,c+num+1)-c-1;
    for(int i=1;i<=n;++i)a[i]=lower_bound(c+1,c+num+1,a[i])-c;
    for(int i=1;i<=n;++i)b[i]=lower_bound(c+1,c+num+1,b[i])-c;
    for(int i=1;i<=n;++i){
        d[a[i]]++;
        d[b[i]]++;
        add(a[i],b[i]);
    }
    int x=1,y=0;
    for(int i=1;i<=n;++i){
        if(d[i]&1)x=i,y++;
    }
    if(y>2){
        puts("-1");
        return 0;
    }
    memcpy(cur,head,sizeof(head));
    dfs(x);
    if(ans.size()<n+1){
        puts("-1");
        return 0;
    }
    reverse(ans.begin(),ans.end());
    for(auto o:ans){
        cout<<c[o]<<" ";
    }
    return 0;
}