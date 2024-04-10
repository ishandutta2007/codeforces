#include <iostream>

using namespace std;

int main()
{
    int n,m,a[100],l,r,v[100],i,s=0;
    cin>>n>>m;
    for(i=0;i<n;++i)
        {cin>>a[i];if(i!=0)a[i]+=a[i-1];}
    for(i=0;i<m;++i)
        {cin>>l>>r;
        if(l>=2)
          v[i]=a[r-1]-a[l-2];
         else v[i]=a[r-1];
        }
    for(i=0;i<m;++i)
      if(v[i]>0) s+=v[i];
    cout<<s;
    return 0;
}