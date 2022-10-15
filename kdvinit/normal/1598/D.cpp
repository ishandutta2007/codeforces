/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int solve()
{
    int n; cin>>n;
    map<int, int> fa, fb;
    int a[n+1], b[n+1];

    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        fa[a[i]]++;
        fb[b[i]]++;
    }

    int ans = (n*(n-1)*(n-2))/6;
    for(int i=1; i<=n; i++) ans -= (fa[a[i]]-1)*(fb[b[i]]-1);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}