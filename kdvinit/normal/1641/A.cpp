/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, x;
    cin>>n>>x;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    map<int, int> mp;
    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        int y = a[i];
        if(y%x==0)
        {
            int z = y/x;
            if(mp[z]!=0) { mp[z]--; cnt--; }
            else { mp[y]++; cnt++; }
        }
        else { mp[y]++; cnt++; }
    }

    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}