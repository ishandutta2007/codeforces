/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int GCD(int x, int y)
{
   if(y==0) return x;
   else return GCD(y, x%y);
}

int LCM(int x, int y)
{
    int z = GCD(x, y);
    int ans = (x/z);
    ans*=y;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int lft=n, ans=0, l=1;
    for(int i=2; 1; i++)
    {
        l = LCM(l, i);
        int x = (n/l);
        int tmp = (i)*(lft-x);
        ans += (tmp%mod);   ans%=mod;
        lft = x;
        if(lft==0) break;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}