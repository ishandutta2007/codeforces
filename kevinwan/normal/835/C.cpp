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
const int mn=1e3+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll h[11][110][110];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,q,c;
    cin>>n>>q>>c;
    for(int i=0;i<n;i++){
        int x,y,s;
        cin>>x>>y>>s;
        h[s][x][y]++;
    }
    for(int i=1;i<110;i++)for(int j=1;j<110;j++){
        for(int k=0;k<=c;k++)h[k][i][j]+=h[k][i-1][j]+h[k][i][j-1]-h[k][i-1][j-1];
    }
    while(q--){
        int t,a,b,aa,bb;
        cin>>t>>a>>b>>aa>>bb;
        ll ans=0;
        for(int i=0;i<=c;i++){
            int ii=(i+t)%(c+1);
            ans+=ii*(h[i][aa][bb]-h[i][a-1][bb]-h[i][aa][b-1]+h[i][a-1][b-1]);
        }
        printf("%lld\n",ans);
    }
}