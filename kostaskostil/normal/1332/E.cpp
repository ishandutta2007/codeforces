#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long
using namespace std;

const int nmax=200500;

int mod=998244353;
map<pair<int, bool>, int> mp;
int f(int x, bool p)
{
    if (mp.find({x, p})!=mp.end())
        return mp[{x, p}];
    int x1=(f(x/2, 0)*f(x-x/2, p))%mod;
    int x2=(f(x/2, 1)*f(x-x/2, p^1))%mod;
    return mp[{x, p}]=(x1+x2)%mod;
}

int bpow(int a, int b)
{
    int res=1;
    while (b>0)
    {
        if (b%2==1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, l, r;
    cin>>n>>m>>l>>r;
    int x=(n*m/2);
    int y=(n*m/2)+(n*m)%2;
    mp[{1, 0}]=(r/2-(l-1)/2)%mod;
    mp[{1, 1}]=((r+1)/2-l/2)%mod;
    if ((n*m)%2==1)
        cout<<bpow(r-l+1, n*m)<<"\n";
    else
        cout<<(f(x, 0)*f(y, 0)+f(x, 1)*f(y, 1))%mod<<"\n";
}