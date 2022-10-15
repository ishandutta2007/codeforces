/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;
    int a[n+1], mpa[100]={0};
    for(int i=1; i<=n; i++) cin>>a[i], mpa[a[i]]++;
    sort(a+1, a+n+1);

    int m; cin>>m;
    int b[m+1], mpb[100]={0};
    for(int i=1; i<=m; i++) cin>>b[i], mpb[b[i]]++;
    sort(b+1, b+m+1);

    if(a[n]>b[m])
    {
        cout<<"Alice"<<endl;
        cout<<"Alice"<<endl;
        return;
    }

    if(a[n]<b[m])
    {
        cout<<"Bob"<<endl;
        cout<<"Bob"<<endl;
        return;
    }

    cout<<"Alice"<<endl;
    cout<<"Bob"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}