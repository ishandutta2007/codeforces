/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 10;
int a[N], b[N], n;

bool check(int k)
{
    int cur=0;
    for(int i=1; i<=n; i++)
    {
        int ls = cur;
        int mr = (k-1-cur);
        if(ls<=b[i] && mr<=a[i]) cur++;
        if(cur==k) break;
    }
    return (cur==k);
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i];

    int l=1, r=n+1;
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