#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
//IgorI
//It is true or false
//Is it true or false?

   
int main()
{
     int n;
     int m;
     int k;

     cin>>n>>m>>k;
     int a[1000002]={0};
     
     int v=0,u=0;
     int x=1;
     for(int i=0; i<m; i++)
     {
         cin>>v;
         a[v]++;
         if(v==1)
           {
                cout<<"1"; 
                return 0;
           }
     }

     for(int i=0; i<k; i++)
     {
          cin>>v>>u;
          if(x==v)
              x=u;
          else
          if(x==u)
              x=v;
         // int r=0; l=m-1;
         if(a[x]==1)
           {cout<<x;return 0;}
          
     }
     cout<<x;
     
     
}