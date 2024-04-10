#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e3+10,mv=1e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
double a[mn][mn];
int aa[mn][mn];
double dis[mn],p[mn];
bool vis[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>aa[i][j];
            a[i][j]=aa[i][j]*.01;
        }
        dis[i]=1;
    }
    p[n]=1,dis[n]=0;
    for(int i=1;i<=n;i++){
        int b=0;
        for(int j=1;j<=n;j++)if(!vis[j]){
            if(!b)b=j;
            else if(p[j]&&dis[j]*p[b]<dis[b]*p[j])b=j;
        }
        vis[b]=1;
        for(int j=1;j<=n;j++)if(!vis[j]){
            double dp=(1-p[j])*a[j][b];
            if(p[b])dis[j]+=dp*dis[b]/p[b];
            p[j]+=dp;
        }
    }
    printf("%.20lf",dis[1]/p[1]);
}