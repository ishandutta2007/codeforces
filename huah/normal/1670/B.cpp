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
        int n;cin>>n;
        string s;cin>>s;
        int k;cin>>k;
        vector<bool>vis(26);
        for(int i=0;i<k;++i)
        {
            char c;cin>>c;
            vis[c-'a']=true;
        }
        while(!s.empty()&&!vis[s.back()-'a']) s.pop_back();
        if(s.size()<=1) cout<<0<<'\n';
        else
        {
            n=s.size();
            vector<int>del(n);
            for(int i=n-2;i>=0;--i)
            {
                if(vis[s[i+1]-'a']) del[i]=1;
                else del[i]=del[i+1]+1;
            }
            cout<<*max_element(del.begin(),del.end())<<'\n';
        }
    }
}