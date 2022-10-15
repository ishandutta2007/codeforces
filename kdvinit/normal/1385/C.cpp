/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int i,cntr=0;
    for(i=n-1;i>0;i--)
    {
        if(a[i]<a[i+1]) cntr++;
        if(a[i]>a[i+1] && cntr!=0) break;
    }

    cout<<i<<endl;
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