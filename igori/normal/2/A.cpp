#include <iostream>
#include <cmath>
#include <cstdio>
#include<iomanip>
using namespace std;

int now[1000]={0};

int main()
{
   int n;
   cin>>n;
   string s;
   string a[1000];
   int izm[1000];
   int itog[1000];

   string pz[1000];
   int la=0;
   int tap=0;
   int maxi=0;
   for(int i=0; i<n; i++)
   {
       cin>>a[i]>>izm[i];
       tap=0;
       for(int j=0; j<la; j++)
       {
           if(a[i]==pz[j])
           {
               tap=1;
               now[j]=now[j]+izm[i];


           }
       }
       if(tap==0)
       {
           now[la]=izm[i];
           pz[la]=a[i];



           la++;
       }

   }

   for(int i=0; i<la; i++)
   {
       if(now[i]>maxi)
         maxi=now[i];
    itog[i]=now[i];
       now[i]=0;

   }
   la=0;

   for(int i=0; i<n; i++)
   {
       tap=0;
       for(int j=0; j<la; j++)
       {
           if(a[i]==pz[j])
           {
               tap=1;
               now[j]=now[j]+izm[i];
               if((now[j]>=maxi)&&(itog[j]==maxi))
               {
                   cout<<pz[j];
                   return 0;
               }

           }
       }
       if(tap==0)
       {
           now[la]=izm[i];
           pz[la]=a[i];

           if((now[la]>=maxi)&&(itog[la]==maxi))
            {
                   cout<<pz[la];
                   return 0;
               }

           la++;
       }
   }

}