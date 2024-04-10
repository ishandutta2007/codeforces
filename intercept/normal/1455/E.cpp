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
struct P{
    int x,y;
}p[4];
ll ans;
int b[4];
bool vis[4];
void dfs(int t){
    if(t==4){
        ll sum=0;
        sum+=abs(p[b[0]].y-p[b[1]].y);
        sum+=abs(p[b[0]].x-p[b[2]].x);
        sum+=abs(p[b[2]].y-p[b[3]].y);
        sum+=abs(p[b[1]].x-p[b[3]].x);
        int miy,mix,mx,my;
        miy=min({abs(p[b[0]].y-p[b[2]].y),abs(p[b[0]].y-p[b[3]].y),abs(p[b[1]].y-p[b[2]].y),abs(p[b[1]].y-p[b[3]].y)});
        mix=min({abs(p[b[0]].x-p[b[1]].x),abs(p[b[0]].x-p[b[3]].x),abs(p[b[2]].x-p[b[1]].x),abs(p[b[2]].x-p[b[3]].x)});
        my =max({abs(p[b[0]].y-p[b[2]].y),abs(p[b[0]].y-p[b[3]].y),abs(p[b[1]].y-p[b[2]].y),abs(p[b[1]].y-p[b[3]].y)});
        mx =max({abs(p[b[0]].x-p[b[1]].x),abs(p[b[0]].x-p[b[3]].x),abs(p[b[2]].x-p[b[1]].x),abs(p[b[2]].x-p[b[3]].x)});
        sum+=2ll*max(0,miy-mx)+2ll*max(0,mix-my);
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<4;++i){
        if(!vis[i]){
            vis[i]=1;
            b[t]=i;
            dfs(t+1);
            vis[i]=0;
        }
    }
}

void work(){
    ans=1e18;
    for(int i=0;i<4;++i)cin>>p[i].x>>p[i].y;
    dfs(0);
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*

1
1 0
2 0
4 0
6 0
*/