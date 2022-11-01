#include <iostream>

using namespace std;
const int INF=1000000;
int main()
{
   int n,a[1005],ans=0,x=0;
   bool g=0;
   cin>>n;

   for (int i=0;i<n;i++) cin>>a[i];

   while (x!=n)
   {
       if (g==0){
        for (int i=0;i<n;i++)

           if (a[i]<=x)
           {
               x++;
               a[i]=INF;
           }
           g=1;
       } else
    {
        for (int i=n-1;i>=0;i--)

           if (a[i]<=x)
           {
               x++;
               a[i]=INF;
           }
           g=0;
       }

       if (x!=n)
       ans++;


   }

   cout<<ans;
    return 0;
}