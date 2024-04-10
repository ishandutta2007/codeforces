#include <iostream>
#include<algorithm>

using namespace std;

int n;
char c[200][200],ans[200][200];

bool check(int x,int y)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(c[i][j]=='o' && x+i>-1 && x+i<n && y+j>-1 && y+j<n && c[i+x][y+j]=='.')
                return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>c[i][j];
    for(int i=0;i<2*n-1;i++)
        for(int j=0;j<2*n-1;j++)
            ans[i][j]='.';
    ans[n-1][n-1]='o';
    for(int i=-n+1;i<n;i++)
        for(int j=-n+1;j<n;j++)
            if((i!=0 || j!=0) && check(i,j))
                ans[i+n-1][j+n-1]='x';
    for(int x=-n+1;x<n;x++)
        for(int y=-n+1;y<n;y++)
            if(ans[x+n-1][y+n-1]=='x')
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        if(c[i][j]=='o' && x+i>-1 && x+i<n && y+j>-1 && y+j<n && c[i+x][y+j]=='x')
                            c[i+x][y+j]='.';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(c[i][j]=='x')
            {
                cout<<"NO"<<endl;
                return 0;
            }
    cout<<"YES"<<endl;
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
            cout<<ans[i][j];
        cout<<endl;
    }
}