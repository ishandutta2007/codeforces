/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    int r[n+1]={0},c[m+1]={0},row=0,col=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            if(x==1) { r[i]=1; c[j]=1; }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(r[i]==0) row++;
    }

    for(int i=1;i<=m;i++)
    {
        if(c[i]==0) col++;
    }

    if(min(row,col)%2==1) cout<<"Ashish"<<endl;
    else cout<<"Vivek"<<endl;

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