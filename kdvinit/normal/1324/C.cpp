/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;
    int n=s.size();

    int ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') { ans=max(ans,cnt); cnt=0; }
        else cnt++;
    }
    ans=max(ans,cnt);

    ans++;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}