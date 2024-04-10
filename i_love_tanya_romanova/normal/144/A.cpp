
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
long n,q,ar[200000],m,ans,p;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)cin>>ar[i];
    q=0;
    for (int i=1;i<=n;i++)
    {if (ar[i]>q){q=ar[i];p=i;}
    }
    ans=p-1;
    for (int i=p;i>1;i--)
        ar[i]=ar[i-1];
    ar[1]=q;

    for (int i=1;i<=n;i++)
    {if (ar[i]<=q){q=ar[i];p=i;}
    }
    ans+=n-p;
    cout<<ans<<endl;
    return 0;
}