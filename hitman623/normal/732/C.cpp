
#include <iostream>

using namespace std;

int main()
{
   long long b,d,s,m=0,maa,f=0;
   char ma='q';
   cin>>b>>d>>s;
   if(b>d && b>s)
   {
    b--;
    m=2*b-d-s;
   }
   else if(d>s && d>b)
   {
     d--;
    m=2*d-b-s;
   }
   else if(s>b && s>d)
   {
       s--;
    m=2*s-d-b;
   }
   else if(b==d && b==s)
   {
     m=0;
   }
   else if(b==d)
   {
    b--;d--;
    m=b-s;
   }
   else if(d==s)
   {
    d--;s--;
    m=d-b;
   }
   else if(b==s)
   {
      m=b-d-1;
   }
   cout<<m;
    return 0;
}