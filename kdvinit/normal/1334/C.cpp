/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    long long int a[n+1],b[n+1],sum=0,mn;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
    {
        int x=(i%n)+1;
        sum+=a[i];
        b[i]=min(a[x],b[i]);
    }

    mn=b[1];
    for(int i=1;i<=n;i++)
    {
        sum-=b[i];
        mn=min(mn,b[i]);
    }
    sum+=mn;

    cout<<sum<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}