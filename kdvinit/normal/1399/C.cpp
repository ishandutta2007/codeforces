/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

int val(int sum,int n,int f[])
{
    int ans=0;
    for(int i=1;2*i<sum;i++) ans+=min(f[i],f[sum-i]);

    if(sum%2==0) ans+=(f[sum/2]/2);

    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int f[2*n+1]={0};
    for(int i=1;i<=n;i++) { int x; cin>>x; f[x]++; }

    int ans=0;
    for(int i=2;i<=2*n;i++) ans=max(ans,val(i,n,f));

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}