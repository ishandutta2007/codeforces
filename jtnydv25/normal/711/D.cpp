#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int con[maxn];
int pos[maxn];
bool done[maxn];
int incoming[maxn];

#define ll long long

ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
const ll mod = 1e9+7;
int main()
{
    int n;
    cin>>n;
    memset(done,0,sizeof done);
    ll ans = 1;
    for(int i = 1;i<=n;i++)
        scanf("%d",&con[i]),incoming[con[i]]++;
    vector<int> cycles;
    for(int i = 1;i<=n;i++)
    {
        if(!done[i])
        {
            int v = i;
            int  j = 1;
            map<int,int> ind;
            while(1)
            {
                if(ind[v])
                {
                    cycles.push_back(v);
                    break;
                }
                if(done[v])
                    break;
                ind[v] = j++;
                done[v] = 1;
                v = con[v];
            }
        }
    }
    int len = n;
    for(int v:cycles)
    {
        int clen = 1;
        int u = con[v];
        while(u!=v)
            u = con[u],clen++;
        ans = (ans*(powr(2,clen,mod)-2))%mod;
        len -= clen;
    }
    ans = (ans*powr(2,len,mod))%mod;
    if(!ans)
        ans+=mod;
    cout<<ans;
}