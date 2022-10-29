#include <iostream>

using namespace std;

int main()
{
    long long l1,r1,l2,r2,k,q=0,a,b;
    cin>>l1>>r1>>l2>>r2>>k;
      if(l2>l1) a=l2;
      else a=l1;
      if(r2>r1) b=r1;
      else b=r2;
      if(b-a>=0) q+=b-a+1;
      if(k>=a && k<=b) q--;
  
   cout<<q;
    return 0;
}