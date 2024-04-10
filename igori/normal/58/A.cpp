#include <iostream>
#include <string>

using namespace std;

int main()
{
     string a;
     cin>>a;
     int t=0;
     int pret=0;
     int n=a.size();
     for(int i=0; i<n; i++)
     {
         if(a[i]=='h')
           {
               t=i;
               pret++;
               break;

           }
     }
     for(int i=t; i<n; i++)
     {
         if(a[i]=='e')
           {
               t=i;

               pret++; break;
           }
     }
     for(int i=t+1; i<n; i++)
     {
         if(a[i]=='l')
           {
               t=i;pret++;
               break;

           }
     }
     for(int i=t+1; i<n; i++)
     {
         if(a[i]=='l')
           {
               t=i;pret++;
               break;

           }
     }
     for(int i=t+1; i<n; i++)
     {
         if(a[i]=='o')
           {
               pret++;
               if(pret==5)
               {
                   cout<<"YES";
               }
               if(pret!=5)
               {
                   cout<<"NO";
               }
               return 0;
           }
     }
     cout<<"NO";


}