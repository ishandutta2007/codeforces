/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int root2(int n)
{
    int ans=1;
    while(n!=1)
    {
        n/=2;
        ans++;
    }
    return ans;
}

int pow2(int n)
{
    int ans=1;
    while(n!=1)
    {
        n--;
        ans*=2;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int r2 = root2(n);
    int g2 = pow2(r2);

    int vlst = n-g2+1;
    int tmp=1;
    int ans=1;
    for(int i=1; i<r2; i++)
    {
        ans*=(tmp+1);
        ans%=m;

        tmp*=2;
        tmp%=m;
    }

    ans*=(vlst+1);
    ans%=m;
    ans--;
    ans = (ans+m)%m;

    //cout<<g2<<endl;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}