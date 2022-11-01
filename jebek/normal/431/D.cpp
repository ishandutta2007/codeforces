#include <iostream>
#include<algorithm>

using namespace std;

long long a[70],c[70][70],l,r,m,k,t;

long long check(long long n)
{
  //  cout<<"*";
    long long f=n,ans=0;
    for(int i=0;i<64;i++)
    {
        a[i]=f%2;
        f=f/2;
    }
    int x=0;
    for(int i=63;i>-1;i--)
    {
        if(a[i]==0)
            continue;
        if(x>k || x+i+1<k)
            break;
        ans+=c[i][k-x];
        x++;
    }
  //  if(n==3)
  //      cout<<ans<<endl;
  //  if(n==6)
  //      cout<<ans<<endl;
   // if(n==500000000000000000)
      //  cout<<ans<<endl;
    return ans;
}

int main()
{
    cin>>m>>k;
    for(int i=0;i<=64;i++)
    {
        c[i][i]=1;
        c[i][0]=1;
    }
    for(int i=2;i<=64;i++)
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    l=1;r=1000000000000000000;
    while(l<r)
    {
        long long mid=(l+r)/2;
        t=check(2*mid)-check(mid);
        if(t<m)
            l=mid+1;
        else if(t==m)
        {
            cout<<mid<<endl;
            return 0;
        }
        else
            r=mid-1;
    }
    cout<<l<<endl;
}