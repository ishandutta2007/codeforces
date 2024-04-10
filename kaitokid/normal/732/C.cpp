#include <iostream>

using namespace std;

int main()
{
   unsigned long long a,b,c,res=0;
   cin>>a>>b>>c;
   unsigned long long g=max(a,b);
   g=max(g,c);
   g--;
   if (g>a){res+=g-a;}
   if (g>b){res+=g-b;}
   if (g>c){res+=g-c;}
   cout<<res;
    return 0;
}