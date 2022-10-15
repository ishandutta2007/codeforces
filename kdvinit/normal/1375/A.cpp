/*
K.D. Vinit
*/
#include <iostream>
#include <cmath>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long int a[n+1];

    for(int i=1;i<=n;i++)
    {
        long long int x;
        cin>>x;
        x=abs(x);
        if(i%2==1) a[i]=x;
        else a[i]=-x;
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
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