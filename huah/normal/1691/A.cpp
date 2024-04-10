#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
// const int mod=1e9+7;
// #define inf 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3fll
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const double eps=1e-8;
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>a(n+1);
        int x=0;
        for(int i=1;i<=n;++i) cin>>a[i],x+=a[i]&1;
        cout<<min(x,n-x)<<'\n'; 
    }
}