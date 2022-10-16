#include <iostream>
#define NMAX 100005
using namespace std;
int n,m,a[NMAX],b[NMAX],dif[NMAX];
void rezolva(int diff[],int m)
{
   int poz,cntr=0;
   bool ok=true;
   for(int i=1;i<=m && ok;i++)
   {
       if(dif[i]>0)
          ok=false;
       if(dif[i]<0)
       {
        poz=i+1;
        while(poz<=m && dif[i]==dif[poz])
            poz++;
        if(poz<=m)
            {
               for(int j=poz;j<=m && ok;j++)
                 if(dif[j])
                    ok=false;
            }
        break;
       }
   }
   if(ok)
     cout<<"YES"<<'\n';
   else
     cout<<"NO"<<'\n';
}
int main()
{
     cin>>n;
     for(int i=1;i<=n;i++)
     {
       cin>>m;
       for(int j=1;j<=m;j++)
        cin>>a[j];
       for(int j=1;j<=m;j++)
       {
        cin>>b[j];
        dif[j]=a[j]-b[j];
       }
       rezolva(dif,m);
     }

    return 0;
}