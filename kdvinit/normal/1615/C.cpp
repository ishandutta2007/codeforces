/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    string a, b;
    cin>>a>>b;

    int cnt[5]={0};
    for(int i=0; i<n; i++)
    {
        if(a[i]=='1' && b[i]=='1') cnt[1]++;
        if(a[i]=='0' && b[i]=='1') cnt[2]++;
        if(a[i]=='1' && b[i]=='0') cnt[3]++;
        if(a[i]=='0' && b[i]=='0') cnt[4]++;
    }

    int ans=-1;
    if(cnt[2]==cnt[3])
    {
        ans = (2*cnt[2]);
    }

    if(cnt[1]==cnt[4]+1)
    {
        int tmp = cnt[1]+cnt[4];
        if(ans==-1) ans=tmp;
        ans = min(ans, tmp);
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