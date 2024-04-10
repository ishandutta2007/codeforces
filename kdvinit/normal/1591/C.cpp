/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int get_val(vector<int>& a, int k)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int strt = n%k;
    if(strt==0) strt=k;

    int ans = 0;
    for(int i=strt-1; i<n; i+=k) ans+=(2*a[i]);

    return ans;
}

void solve()
{
    int n, k, x;
    cin>>n>>k;

    vector<int> a, b;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(x==0) continue;
        if(x<0) a.push_back(abs(x));
        else b.push_back(x);
    }

    int ans = get_val(a, k)+get_val(b, k);

    int mx = 0;
    if(a.size()!=0) mx = max(mx, a.back());
    if(b.size()!=0) mx = max(mx, b.back());
    ans-=mx;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}