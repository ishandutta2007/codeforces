#include <iostream>

using namespace std;

int main()
{
    long long n,a[200005]={0},p[200005]={0},i,x,m=0,s=0,j,ans=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        a[x]++;
        m=max(m,x);
    }
    for(i=1;i<=m;++i)
    p[i]=a[i]+p[i-1];
    for(i=1;i<=m;++i)
    {
        s=0;
        if(a[i]>0)
        {
            for(j=i;j<=m-i;j+=i)
            s+=(p[j+i-1]-p[j-1])*j;
            s+=j*(p[m]-p[j-1]);
        }
    ans=max(s,ans);
    }
    cout<<ans;
    return 0;
}