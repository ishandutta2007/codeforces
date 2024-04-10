/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod;

void Adjust(int &x)
{
    if(x>=mod) x-=mod;
}

void solve()
{
    int n; cin>>n>>mod;
    if(n<=2) { cout<<0<<endl; return; }

    map<int, int> dp;
    dp[0]=2;
    dp[1]=8;
    dp[2]=4;
    dp[3]=1;

    int cnt=6;
    for(int i=4; i<=n; i++)
    {
        map<int, int> tp;
        for(int j=1; j<i; j++)
        {
            tp[j]+=((i-j)*(cnt));   tp[j]%=mod;
        }

        for(auto x: dp)
        {
            int d1 = x.first;
            int c1 = x.second;
            tp[d1] += (c1*i);   tp[d1]%=mod;

            for(int j=1; j<i; j++)
            {
                int d2 = j+d1;
                int d3 = j-d1;
                int c2 = (c1*(i-j));    c2%=mod;
                tp[d2]+=c2;     Adjust(tp[d2]);
                tp[d3]+=c2;     Adjust(tp[d3]);
            }
        }
        dp=tp;
        cnt*=i;     cnt%=mod;
    }

    int ans=0;
    for(auto x: dp)
    {
        int dif = x.first;
        int cnt = x.second;
        if(dif<0) ans+=cnt, Adjust(ans);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}