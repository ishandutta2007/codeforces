#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long int n, sx, sy, ans;
   cin>>n>>sx>>sy;
   int a[4]={0}, p;
   while(n>0)
   {
       long int x,y;
       cin>>x>>y;
       if(x>sx) a[0]++;
       if(y>sy) a[1]++;
       if(x<sx) a[2]++;
       if(y<sy) a[3]++;
       n--;
   }
   ans = a[0];
   p=0;
   for(int i=1;i<4;i++)
   {
       if(a[i]>ans)
       {
           ans=a[i];
           p=i;
       }
   }
   cout<<ans<<endl;
   if(p==0) cout<<sx+1 <<" " <<sy<<endl;
   if(p==1) cout<<sx <<" " <<sy+1<<endl;
   if(p==2) cout<<sx-1 <<" " <<sy<<endl;
   if(p==3) cout<<sx <<" " <<sy-1<<endl;
   return 0;
}