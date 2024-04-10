#include <iostream>

using namespace std;

int main()
{
   long n,w,q,v;
   cin>>n;
   w=n/7;
   int r=n%7;
   q=2*w+((r/5>0)?r%5:0);
   v=2*w+((r>=2)?2:r);
   cout<<q<<"  "<<v;
    return 0;
}