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
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int tot=0;
        for(int i=0;i<s.size();++i)
            tot+=s[i]=='1';
        if(tot==0) cout<<0<<'\n';
        else if(tot==1)
        {
            int ans=11;
            for(int i=0;i<s.size();++i)
                if(s[i]=='1')
                {
                    if(i<=k) ans=10;
                    if(s.size()-1-i<=k) ans=1;
                }
            cout<<ans<<'\n';
        }
        else
        {
            int ans=11*tot;
            int x=0,y=0;
            for(int i=0;i<s.size();++i)
                if(s[i]=='1')
                {
                    x=i;break;
                }
            for(int i=s.size()-1;i>=0;--i)
                if(s[i]=='1')
                {
                    y=s.size()-1-i;
                    break;
                }
            if(x+y<=k) ans-=11;
            else if(y<=k) ans-=10;
            else if(x<=k) ans-=1;
            cout<<ans<<'\n';
        }
    }
}