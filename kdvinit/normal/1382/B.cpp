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

    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=1) break;
    }

    if(i==n+1) i=n;

    if(i%2==1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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