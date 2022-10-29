#include <iostream>

using namespace std;

int main()
{
    int i,a[200001],n,f=1;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>a[i];
    if(a[i]>2)
  {  if(a[i]%2==0)a[i]=2;
     else a[i]%=2;}
  }
   a[n]=0;
    for(i=0;i<n;++i)
    {if(a[i]==1)
      a[i+1]--;
      else if(a[i]!=2 && a[i]!=0)f=0;
    }
    if(f==0 || a[n]<0) cout<<"NO";
    else cout<<"YES";
    return 0;
}