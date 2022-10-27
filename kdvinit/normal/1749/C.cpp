/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool check(int a[], int n, int k)
{
    if(n<(2*k-1)) return false;

    for(int i=1; i<=k; i++)
    {
        if(a[i+k-1]>i) return false;
    }

    return true;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int c1=0;
    for(int i=1; i<=n; i++) if(a[i]==1) c1++;

    if(c1<=1) { cout<<c1<<endl; return; }

    int l=1, r=n+1;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(a, n, mid)) l=mid;
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