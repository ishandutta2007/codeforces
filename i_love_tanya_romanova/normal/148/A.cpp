
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
long ar[200000],n,fl,ans;
int main()
{
    for (int i=1;i<=4;i++)
        cin>>ar[i];
    cin>>n;
    for (int i=1;i<=n;i++)
    {fl=0;
     for (int j=1;j<=4;j++)if (i%ar[j]==0)fl++;
    if (fl)ans++;}
    cout<<ans<<endl;

    return 0;
}