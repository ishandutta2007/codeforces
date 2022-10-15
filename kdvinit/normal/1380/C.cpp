/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,x;
    cin>>n>>x;
    long long int a[n];

    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    long long int cnt=0,ans=0;
    for(int i=n-1;i>=0;i--)
    {
        cnt++;
        if(a[i]*cnt>=x) { ans++; cnt=0; }
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}