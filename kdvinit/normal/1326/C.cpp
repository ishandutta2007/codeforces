/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 998244353;

void solve()
{
    int n, k;
    cin>>n>>k;

    int p[n+1];
    for(int i=1;i<=n;i++) cin>>p[i];

    int m=n-k;
    int ans1=0, ans2=0;

    vector<int> pos;
    for(int i=1;i<=n;i++)
    {
        if(p[i]>m)
        {
            ans1+=p[i];
            pos.push_back(i);
        }
    }

    ans2=1;
    for(int i=1;i<pos.size();i++)
    {
        ans2*=(pos[i]-pos[i-1]);
        ans2%=mod;
    }
    cout<<ans1<<" "<<ans2<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}