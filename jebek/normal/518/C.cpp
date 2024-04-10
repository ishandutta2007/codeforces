#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,k,a[200000],p[200000],ans,z;

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    ans=m;
    for(int i=0;i<m;i++)
    {
        long long x;
        cin>>x;
        long long y=p[x];
        ans+=y/k;
        if(y==0)
            continue;
        z=a[y-1];
        p[x]=y-1;
        p[z]=y;
        a[y-1]=x;
        a[y]=z;
    }
    cout<<ans<<endl;
}