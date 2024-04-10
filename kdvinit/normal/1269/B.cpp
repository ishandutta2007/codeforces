#include <iostream>
#include <algorithm>
using namespace std;

bool CheckEql(long int a[],long int b[],int n,int x,int y)
{
    for(int j=0;j<n;j++)
    {
        if(a[(x+j)%n]!=b[(y+j)%n]) return false;
    }
    return true;
}

int main()
{
    long int n,m;
    cin>>n>>m;
    long int a[n],b[n],da[n],db[n],ans=m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        da[i]=(a[(i+1)%n]-a[i]+m)%m;
        db[i]=(b[(i+1)%n]-b[i]+m)%m;
    }
    for(int i=0;i<n;i++)
    {
        if(CheckEql(da,db,n,i,0))
        {
            long int x = (m+b[0]-a[i])%m;
            ans = min(ans,x);
        }
    }
    cout<<ans<<endl;
    return 0;
}