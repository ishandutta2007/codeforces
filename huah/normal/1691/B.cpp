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
        for(int i=1;i<=n;++i) cin>>a[i];
        bool flag=true;
        for(int i=1;i<=n;++i)
        {
            int j=i;
            while(j+1<=n&&a[j+1]==a[i]) ++j;
            if(i==j) flag=false;
            i=j; 
        }
        if(flag==false) {cout<<-1<<'\n';continue;}
        for(int i=1;i<=n;++i)
        {
            int j=i;
            while(j+1<=n&&a[j+1]==a[i]) ++j;
            for(int k=i+1;k<=j;++k) cout<<k<<' ';
            cout<<i<<' ';
            i=j;
        }
        cout<<'\n';
    }
}