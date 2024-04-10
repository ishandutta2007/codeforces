#include <iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

long long n,l,r,wl,wr,a[100100],f,ans,k;

int main()
{
    cin>>n>>l>>r>>wl>>wr;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        f+=a[i]*r;
        k+=a[i]*l;
       // cout<<f<<" ";
    }
    ans=min(f+(n-1)*wr,k+(n-1)*wl);
  //  cout<<ans<<" "<<f<<endl;
    for(int i=1;i<n;i++)
    {
        f-=a[i-1]*r;
        f+=a[i-1]*l;
        int x=n-2*i,y=wr;
        if(x<0)
        {
            y=wl;
            x=-x;
        }
        if(x!=0)
            x=x-1;
        ans=min(ans,f+x*y);
     //   cout<<ans<<" "<<i<<" "<<f<<" "<<x<<" "<<y<<endl;
    }
    cout<<ans<<endl;
}