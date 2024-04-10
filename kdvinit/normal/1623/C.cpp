/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 10;
int h[N], n;

bool check(int x)
{
    int a[n+1];
    for(int i=1; i<=n; i++) a[i]=h[i];

    for(int i=n; i>=1; i--)
    {
        if(a[i]<x) return false;

        int d1 = (a[i]-x)/3;
        int d2 = (h[i]/3);

        int d = min(d1, d2);

        if(i>2)
        {
            a[i-1]+=d;
            a[i-2]+=(2*d);
        }
    }

    return true;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>h[i];

    int l=0, r=1e9+1;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<l<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}