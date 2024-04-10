#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
#define inf 0x3f3f3f3f
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;vector<int>a(n);
        int x=0;
        for(int i=0;i<n;++i) cin>>a[i],x+=a[i]<0;
        for(int i=0;i<x;++i)
            if(a[i]>0) a[i]*=-1;
        for(int i=x;i<n;++i) if(a[i]<0) a[i]*=-1;
        if(is_sorted(a.begin(),a.end())) cout<<"YES\n";
        else cout<<"NO\n";
    }
}