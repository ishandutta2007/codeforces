/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,k,z;
    cin>>n>>k>>z;
    k++;

    long long int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    long long int ans=0;
    for(int i=0;i<=z;i++)
    {
        long long int sum=0,mx=0;
        for(int j=1;j<=k-2*i;j++)
        {
            sum+=a[j];
            mx=max(mx,a[j]+a[j+1]);
        }
        sum+=i*mx;
        ans=max(ans,sum);
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