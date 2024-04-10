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

    for(int i=2;i<n;i++)
    {
        if(a[i-1]<a[i] && a[i]>a[i+1]) { cout<<"YES"<<endl<<i-1<<" "<<i<<" "<<i+1<<endl; return; }
    }

    cout<<"NO"<<endl;
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