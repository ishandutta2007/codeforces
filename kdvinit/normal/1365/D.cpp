/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n+2][m+2];
    int b[n+2][m+2],G=0,B=0,e[n+2][m+2];

    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            a[i][j]='0';
            b[i][j]=0;
            e[i][j]=0;
            //if(i==0 || i==n+1 || j==0 || j==m+1) e[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='G') G++;
            if(a[i][j]=='#') b[i][j]=1;
        }
    }

    if(G==0) { cout<<"Yes"<<endl; return; }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='B')
            {
                if(a[i+1][j]=='G' || a[i][j+1]=='G' || a[i-1][j]=='G' || a[i][j-1]=='G') { cout<<"No"<<endl; return; }
                b[i][j]=1;
                b[i+1][j]=1;
                b[i][j+1]=1;
                b[i-1][j]=1;
                b[i][j-1]=1;
            }
        }
    }

    if(b[n][m]==1) { cout<<"No"<<endl; return; }
    e[n][m]=1;

    while(1)
    {
        int cntr=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(e[i][j]==1 || b[i][j]==1) continue;
                if(e[i+1][j]==1 || e[i][j+1]==1 || e[i-1][j]==1 || e[i][j-1]==1)
                {
                    e[i][j]=1;
                    cntr++;
                }
            }
        }
        if(cntr==0) break;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='G' && e[i][j]==0) { cout<<"No"<<endl; return; }
        }
    }

    cout<<"Yes"<<endl;
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