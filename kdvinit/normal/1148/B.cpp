/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m, ta, tb, k;
    cin>>n>>m>>ta>>tb>>k;

    int a[n+1], b[m+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; a[i]+=ta; }
    for(int i=1; i<=m; i++) cin>>b[i];
    
    if(k>=n) { cout<<-1<<endl; return; }
    if(k>=m) { cout<<-1<<endl; return; }

    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    int j=1;
    int ans = -1;

    for(int i=1; i<=k+1; i++)
    {
        if(i>n) break;

        int lft = k-(i-1);
        while(j<=m && b[j]<a[i]) j++;

        if(j+lft>m) { cout<<-1<<endl; return; }

        int jj = j+lft;
        int cur = b[jj]+tb;
        ans = max(ans, cur);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}