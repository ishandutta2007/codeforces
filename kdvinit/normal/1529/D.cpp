/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

void solve()
{
    int n;
    cin>>n;

    int num_fac[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i) num_fac[j]++;
    }

    int sum=0, cur;
    for(int i=1; i<=n; i++)
    {
        cur = sum + num_fac[i]; cur%=mod;
        sum+=cur; sum%=mod;
    }
    cout<<cur<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}