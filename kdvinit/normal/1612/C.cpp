/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int k, mx;

int sum_till(int x)
{
    int ans = (x*(x+1))/2;
    return ans;
}

int cnt_line(int x)
{
    if(x<=k) return sum_till(x);
    else
    {
        int l = (2*k-1)-x;
        int ans = sum_till(k) + sum_till(k-1) - sum_till(l);
        return ans;
    }
}

bool check(int x)
{
    int ans = cnt_line(x);
    if(ans>=mx) return false;
    else return true;
}

void solve()
{
    cin>>k>>mx;

    int l=0, r=(2*k-1);

    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
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