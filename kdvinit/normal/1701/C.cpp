/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;
int f[N];
int n, m;

bool check(int x)
{
    int tsks=0;
    int cando=0;

    for(int i=1; i<=n; i++)
    {
        if(f[i]>x) tsks+=(f[i]-x);
        else cando+=((x-f[i])/2);
    }

    return (tsks<=cando);
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++) f[i]=0;
    for(int i=1; i<=m; i++) { int x; cin>>x; f[x]++; }

    int l=0;
    int r=m;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}