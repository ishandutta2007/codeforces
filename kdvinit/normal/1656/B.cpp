/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    map<int, int> mp;

    for(int i=1; i<=n; i++) { cin>>a[i]; mp[a[i]]=1; }
    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++)
    {
        if(mp[a[i]+k]) return true;
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}