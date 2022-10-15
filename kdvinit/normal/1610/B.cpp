/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool check(int a[], int l, int r, int ign)
{
    if(l>=r) return true;
    if(a[l]==a[r]) return check(a, l+1, r-1, ign);
    if(ign==-1)
    {
        return (check(a, l+1, r, a[l]) || check(a, l, r-1, a[r]));
    }
    else
    {
        if(a[l]==ign) return check(a, l+1, r, ign);
        if(a[r]==ign) return check(a, l, r-1, ign);
        return false;
    }
}

bool solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    return check(a, 1, n, -1);
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