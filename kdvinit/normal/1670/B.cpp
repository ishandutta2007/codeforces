/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    map<char, int> mp;
    int k; cin>>k;
    for(int i=1; i<=k; i++) { char c; cin>>c; mp[c]=1; }

    int lst=-1;
    int ans=-1;

    for(int i=0; i<n; i++)
    {
        if(mp[s[i]]==0) continue;
        int len = i-lst-1;
        lst = i;

        if(ans==-1)
        {
            ans=len;
            continue;
        }

        if(len<ans) continue;

        if(len==ans) ans++;
        else ans=len+1;
    }
    if(ans<0) ans=0;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}