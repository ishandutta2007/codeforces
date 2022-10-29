#include <iostream>

using namespace std;

int main()
{
   
   long int a;
   cin>>a;
   if(a!=0)
   {if(a%4==0) cout<<6;
   else if(a%4==1) cout<<8;
   else if(a%4==2) cout<<4;
   else if(a%4==3) cout<<2;
   }
   else cout<<1;
   return 0;
}