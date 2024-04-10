#include <iostream>

using namespace std;

int n, m, k, a,b,d, l[5005], c[5005], xc[5005], xl[5005];

int main()
{
cin>>n>>m>>k;

for(int i=1;i<=k;i++)
{
    cin>>a>>b>>d;
    if(a==1)
    {
        l[b]=d;
        xl[b]=i;
    }
    if(a==2)
    {
        c[b]=d;
        xc[b]=i;
    }
}

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
    if(xc[j]>xl[i])
    {
        cout<<c[j]<<' ';
    }else{
        cout<<l[i]<<' ';
    }
    }
    cout<<'\n';
}

    return 0;
}