#include<bits/stdc++.h>
using namespace std;
int odw[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    if(a!=1&&b!=1||(a==1&&b==1&&(n==3||n==2)))
        cout<<"NO";
    else
    {
        cout<<"YES"<<'\n';
        if(a==1&&b==1)
        {
            if(n==1)
                cout<<0;
            else
            {
                for(int x=2;x<n;x++)
                {
                    odw[x][1]=1;
                    odw[1][x]=1;
                }
                odw[2][n]=1;
                odw[n][2]=1;
                for(int x=1;x<=n;x++)
                {
                    for(int y=1;y<=n;y++)
                        cout<<odw[x][y];
                    cout<<'\n';
                }
            }
        }
        else
        {
            int pom=0;
            for(int x=2;x<=n-max(a,b)+1;x++)
            {
                odw[x][1]=1;
                odw[1][x]=1;
            }
            if(a==1)
                pom=1;
            for(int x=1;x<=n;x++)
            {
                for(int y=1;y<=n;y++)
                {
                    if(x!=y)
                        cout<<(odw[x][y]+pom)%2;
                    else
                        cout<<0;
                }

                cout<<'\n';
            }
        }
    }
	return 0;
}