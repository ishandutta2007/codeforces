#include<bits/stdc++.h>
using namespace std;
int choose[110];
int g[110][3];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int j=0;j<3;j++)
            for(int i=0;i<n;i++)
                cin>>g[i][j];
        for(int i=0;i<n;i++)
            choose[i]=-1;
        for(int i=0;i<n;i++)
        {
            int Left=(i-1+n)%n;
            int Right=(i+1)%n;
            for(int j=0;j<3;j++)
                if(g[i][j]!=choose[Left]&&g[i][j]!=choose[Right])
                {
                    cout<<g[i][j]<<" ";
                    choose[i]=g[i][j];
                    break;
                }
        }
        puts("");
    }
    return 0;
}