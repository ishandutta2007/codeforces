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
const int mn=300+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll a[9][mn][mn],d[mn][mn],e[mn][mn];
ll t[mn][mn];
void mult(ll c[mn][mn],ll a[mn][mn],ll b[mn][mn]){
    memset(t,0x3f,sizeof(t));
    for(int i=1;i<mn;i++)for(int j=1;j<mn;j++)for(int k=1;k<mn;k++)t[i][k]=min(t[i][k],a[i][j]+b[j][k]);
    memcpy(c,t,sizeof(t));
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m;
    cin>>n>>m;
    memset(a[0],0x3f,sizeof(a));
    for(int i=0;i<m;i++){
        ll b,c,d,e;
        cin>>b>>c>>d>>e;
        a[0][b][c]=-d;
        a[0][c][b]=-e;
    }
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++)a[0][i][i]=d[i][i]=0;
    for(int i=1;i<9;i++)mult(a[i],a[i-1],a[i-1]);
    int ans=0;
    for(int i=8;i>=0;i--){
        mult(e,d,a[i]);
        bool g=0;
        for(int j=1;j<=n;j++)if(e[j][j]<0)g=1;
        if(!g){
            ans+=1<<i;
            memcpy(d,e,sizeof(d));
        }
    }
    ans++;
    if(ans>n)printf("0");
    else printf("%d",ans);
}