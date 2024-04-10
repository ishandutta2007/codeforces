#include <iostream>

using namespace std;
int a, n, m, t[50003][6];
int main()
{
cin>>m>>n;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
        cin>>a;
        t[i][j]=max(t[i-1][j], t[i][j-1])+a;
        }
    for(int i=1;i<=m;i++)
    cout<<t[i][n]<<'\n';

    return 0;
}