#include <iostream>
#include<algorithm>

using namespace std;

int f(char cc)
{
    if(cc=='W')
        return 1;
    else
        return -1;
}

long long n,m,ans,a[200][200];
char c[200][200];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int i=n-1;i>-1;i--)
        for(int j=m-1;j>-1;j--)
        {
            //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            if(a[i][j]!=f(c[i][j]))
            {
                ans++;
                for(int x=0;x<=i;x++)
                    for(int y=0;y<=j;y++)
                        a[x][y]+=f(c[i][j])-a[i][j];
            }
        }
    cout<<ans<<endl;
}