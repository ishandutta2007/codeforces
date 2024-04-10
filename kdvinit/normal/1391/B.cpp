/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }

    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(a[i][m]=='R') ans++;
    }
    for(int i=1;i<m;i++)
    {
        if(a[n][i]=='D') ans++;
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}