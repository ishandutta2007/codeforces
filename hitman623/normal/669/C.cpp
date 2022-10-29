#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,m,a[101][101]={0},i,j,q,t,x,y,z,temp;
    vector < long > d;
    cin>>n>>m>>q;
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x;
            d.pb(x);
            temp=a[x-1][0];
            for(i=1;i<m;++i)
            a[x-1][i-1]=a[x-1][i];
            a[x-1][i-1]=temp;
        }
        if(t==2)
        {
            cin>>x;
            d.pb(-x);
            temp=a[0][x-1];
            for(i=1;i<n;++i)
            a[i-1][x-1]=a[i][x-1];
            a[i-1][x-1]=temp;
        }
        if(t==3)
        {
            cin>>x>>y>>z;
            a[x-1][y-1]=z;
        }
    }
    for(i=d.size()-1;i>=0;--i)
    {
        if(d[i]<0)
        {
            temp=a[n-1][-d[i]-1];
            for(j=n-1;j>0;--j)
            a[j][-d[i]-1]=a[j-1][-d[i]-1];
            a[j][-d[i]-1]=temp;
        }
        else
        {
            temp=a[d[i]-1][m-1];
            for(j=m-1;j>0;--j)
            a[d[i]-1][j]=a[d[i]-1][j-1];
            a[d[i]-1][j]=temp;
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}