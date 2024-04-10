#include <iostream>
#define DMAX 550
using namespace std;

int a[DMAX][DMAX], Right[DMAX][DMAX], Down[DMAX][DMAX];

int n, m, q;

int asd(int x1, int y1, int x2, int y2)
{
    x1--;
    y1--;
    int ans1 = Right[x2][y2-1]+Right[x1][y1]-Right[x1][y2-1]-Right[x2][y1];
    int ans2 = Down[x2-1][y2]+Down[x1][y1]-Down[x1][y2]-Down[x2-1][y1];
    return ans1+ans2;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        char c;
        cin>>c;
        a[i][j]=0;
        if(c=='#')
            a[i][j]=1;
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            if(a[i][j]==0&&a[i][j+1]==0)
            Right[i][j]=1;
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==0&&a[i+1][j]==0)
            Down[i][j]=1;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            Right[i][j]+=-Right[i-1][j-1]+Right[i][j-1]+Right[i-1][j],
            Down[i][j]+=-Down[i-1][j-1]+Down[i][j-1]+Down[i-1][j];

int x1, x2, y1,y2;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<asd(x1, y1, x2, y2)<<'\n';
    }

    return 0;
}