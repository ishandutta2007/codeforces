/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n;
    cin>>n;

    long long int a[n+1],b[n+1],mna=1e9,mnb=1e9,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mna=min(mna,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        mnb=min(mnb,b[i]);
    }

    for(int i=1;i<=n;i++)
    {
        ans+=max(a[i]-mna,b[i]-mnb);
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