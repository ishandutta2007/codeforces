/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2001;
unordered_map<int, int> mp[N], cal[N];

int min_sum(int i, int j, int a[])
{
    if(cal[i][j]==1) return mp[i][j];

    if(i==j) { mp[i][j]=0; cal[i][j]=1; return 0; }
    int ans = min( min_sum(i+1, j, a), min_sum(i, j-1, a) );
    ans+=(a[j]-a[i]);

    mp[i][j]=ans;
    cal[i][j]=1;
    return ans;
}

void solve()
{
    int n; cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    sort(a+1, a+n+1);
    cout<<min_sum(1, n, a)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}