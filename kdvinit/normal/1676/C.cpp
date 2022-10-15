/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int diff(string a, string b)
{
    int n = a.size();
    int ans = 0;

    for(int i=0; i<n; i++) ans+=abs(a[i]-b[i]);
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    string s[n+1];
    for(int i=1; i<=n; i++) cin>>s[i];

    int ans = m*100;

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int tmp = diff(s[i], s[j]);
            ans = min(ans, tmp);
        }
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