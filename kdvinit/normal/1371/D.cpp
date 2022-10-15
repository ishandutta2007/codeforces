/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;

    if(k%n==0) cout<<0<<endl;
    else cout<<2<<endl;

    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) a[i][j]=0;
    }

    int i=0,j=0;
    for(int v=1;v<=k;v++)
    {
        a[i][j]=1;
        i+=1;
        j+=1;
        if(v%n==0) i+=1;
        i%=n;
        j%=n;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j];
        cout<<endl;
    }
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