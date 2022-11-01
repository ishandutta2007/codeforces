#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxn=2e5+1;
int a[maxn];
int main()
{
    int n;//ios_base::sync_with_stdio(0);
   //  cin.tie(NULL);
   // scanf("%d",&n);
   cin>>n;
    for (int i=0;i<n;i++)
       // scanf("%d",&a[i]);
       cin>>a[i];
    long long ans=0,cur=0;

    for (int i=0;i<n;i++)
    {
        long long ch=abs(a[i]-cur);
        if (a[i]>cur)
        {
            cur+=ch;
        }
        else
        {
            cur-=ch;
        }
        ans+=ch;
    }

  //  printf("%I64d",ans);
  cout<<ans;
    return 0;
}