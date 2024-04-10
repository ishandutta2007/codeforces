#include <iostream>

using namespace std;

int main()
{
   long long k2,k3,k5,k6,a=0,b=0;
   cin>>k2>>k3>>k5>>k6;
   b=k2;
   if(k5<b) b=k5;
   if(k6<b) b=k6;
   k2-=b;
   a=k2;
   if(a>k3) a=k3;
   cout<<(a*32+b*256);
    return 0;
}