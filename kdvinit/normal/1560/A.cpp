/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> ans;

void solve()
{
    int n;
    cin>>n;
    cout<<ans[n-1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int cnt=0, x=0;
    while(cnt!=1000)
    {
        x++;
        if(x%3==0 || x%10==3) continue;
        ans.push_back(x);
        cnt++;
    }

    int t; cin>>t;
    while(t--) solve();
    return 0;
}