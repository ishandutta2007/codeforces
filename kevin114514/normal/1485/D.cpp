#include<bits/stdc++.h>
using namespace std;
int a[550][550];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if((i+j)%2)
                cout<<720720<<" ";
            else    cout<<720720-a[i][j]*a[i][j]*a[i][j]*a[i][j]<<" ";
        puts("");
    }
    return 0;
}