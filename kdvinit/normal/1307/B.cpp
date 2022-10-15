/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,d;
    cin>>n>>d;

    long long int a[n+1],mx=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        mx=max(mx,a[i]);
        if(a[i]==d) { cout<<1<<endl; return; }
    }

    long long int ans=d/mx;
    if(mx>d) { cout<<2<<endl; return; }
    if(d%mx==0) { cout<<ans<<endl; return; }
    cout<<ans+1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}