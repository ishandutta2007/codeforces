#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    long a[100000],n,i,j,f=1,b=0,c=0,big=0,small;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
 small=a[0];
    for(i=0;i<n;++i)
       {
           if(a[i]>big) big=a[i];
           if(a[i]<small) small=a[i];
       }
       b=big-small;
    for(i=0;i<n;++i)
    {
        c=fabs(a[0]-a[i]);
        if(c!=b && 2*c!=b && c!=0) f=0;
    }
    if(f==0) cout<<"NO";
    else cout<<"YES";
    return 0;
}