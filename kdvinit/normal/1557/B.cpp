/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1], b[n+2];
    for(int i=1; i<=n; i++) cin>>a[i], b[i]=a[i];
    sort(b+1, b+n+1);

    b[n+1] = 1e10;
    map<int, int> nxt;
    for(int i=1; i<=n; i++) nxt[b[i]]=b[i+1];

    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        cnt++;
        int j=i;
        while(j<n && a[j+1] == nxt[a[j]]) j++;
        i=j;
    }

    if(cnt<=k) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}