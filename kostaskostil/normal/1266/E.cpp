#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

int n;
int a[200500];
int sum=0;
map<pair<int, int>, int> mp;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], sum+=a[i];
    a[0]=-1e9;
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int s, t, u;
        cin>>s>>t>>u;
        int u0=mp[{s, t}];
        sum-=max(a[u0], 0ll);
        a[u0]++;
        sum+=max(a[u0], 0ll);
        sum-=max(a[u], 0ll);
        a[u]--;
        sum+=max(a[u], 0ll);
        mp[{s, t}]=u;
        cout<<sum<<"\n";
    }
}