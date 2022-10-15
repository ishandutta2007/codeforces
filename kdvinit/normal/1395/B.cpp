/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,m,x,y;
    cin>>n>>m>>x>>y;

    cout<<x<<" "<<y<<endl;
    cout<<1<<" "<<y<<endl;
    cout<<1<<" "<<1<<endl;

    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1 && j==1) continue;
                if(i==1 && j==y) continue;
                if(i==x && j==y) continue;
                cout<<i<<" "<<j<<endl;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(i==1 && j==1) continue;
                if(i==1 && j==y) continue;
                if(i==x && j==y) continue;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--) solve();
	return 0;
}