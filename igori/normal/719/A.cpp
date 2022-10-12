#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int m[100];
   for(int i=0; i<n; i++)
   {
       cin>>m[i];
   }
   if(n==1)
   {
       if(m[0]==0)
          cout<<"UP";
       else
       if(m[0]==15)
          cout<<"DOWN";
        else
            cout<<-1;
        return 0;
   }
   int a=m[n-2],b=m[n-1];
   if(b==15)
   {
       cout<<"DOWN"; return 0;
   }
   if(b==0)
   {
       cout<<"UP"; return 0;
   }
   if(a<b)
    cout<<"UP";
   if(a>b)
    cout<<"DOWN";






}