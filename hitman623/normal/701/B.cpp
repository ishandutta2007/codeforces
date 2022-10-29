#include <bits/stdc++.h>

using namespace std;
    long long n,m,x[100000],y[100000],i,r[100000]={0},c[100000]={0},s=0,f,g,co=0,nn;
int main()
{

    cin>>n>>m;
    for(i=0;i<m;++i)
        cin>>x[i]>>y[i];
        s=n*n;nn=n;
    for(i=0;i<m;++i)
    {
        if(r[x[i]-1]==0)
        {
            s-=n;
            r[x[i]-1]=1;nn--;
        }
        if(c[y[i]-1]==0)
        {
            s-=nn;
            c[y[i]-1]=1;n--;
        }
        cout<<s<<" ";
    }
    return 0;
}