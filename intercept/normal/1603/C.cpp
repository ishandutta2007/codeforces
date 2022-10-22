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
const int M=100009;
int n;
int a[M];
vector<pii>g[2];
void work(){
    ll ans=0;
    g[0].clear();
    g[1].clear();
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=n;i>=1;--i){
        int p=i&1;
        g[p].eb(a[i],1);
        reverse(g[p^1].begin(),g[p^1].end());
        for(auto o:g[p^1]){
            ans=(ans+1ll*(a[i]-1)/o.fi*i%mod*o.se%mod)%mod;
            int x=a[i]/((a[i]-1)/o.fi+1);
            if((*g[p].rbegin()).fi!=x){
                g[p].eb(x,o.se);
            }
            else {
                (*g[p].rbegin()).se=((*g[p].rbegin()).se+o.se)%mod;
            }
        }
        g[p^1].clear();
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}