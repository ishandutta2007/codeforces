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

    int freq[n+1]={0},mx=0,y=0;
    for(int i=1;i<=n;i++) { int x; cin>>x; freq[x]++;}
    for(int i=1;i<=n;i++) mx=max(mx,freq[i]);
    for(int i=1;i<=n;i++) { if(freq[i]==mx) y++; }

    int ans=(n-mx*y);
    ans/=(mx-1);
    ans+=y-1;

    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}