#include <iostream>

using namespace std;
bool a[10][10];
int main()
{
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    a[x][y]=true;
    a[y][x]=true;
}
if(n<7){cout<<m;return 0;}
int d=1000;
for(int i=1;i<7;i++)
{
    for(int j=i+1;j<=7;j++)
    {int u=0;
        for(int q=1;q<=7;q++)if(a[i][q]&&a[j][q])u++;
    d=min(d,u);
    }
}
cout<<m-d;
    return 0;
}