// Hydro submission #6247ef73993deab656106fa4@1648881523422
#include<bits/stdc++.h>
using namespace std;
char c[50][50];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int u=n,d=0,l=m,r=0;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
        cin>>c[i][j];
        if(c[i][j]=='*')
        {
            if(i<u) u=i;
            if(i>d) d=i;
            if(j<l) l=j;
            if(j>r) r=j;
        }
    }
    for(i=u;i<=d;i++)
    {
        for(j=l;j<=r;j++)
        printf("%c",c[i][j]);
        cout<<endl;
    }
    return 0;
}