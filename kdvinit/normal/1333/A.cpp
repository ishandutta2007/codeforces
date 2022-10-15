/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((i+j)%2==0) a[i][j]='B';
            else a[i][j]='W';
        }
    }

    if(n%2==0 || m%2==0) a[1][2]='B';

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<a[i][j];
        cout<<endl;
    }

    return;
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