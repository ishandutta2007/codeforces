#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
   long long a,d;
   cin >> a >> d;
   long long ans=a;
   //int z=1;
   for(long long m=10;m<=a;m*=10) {
      long long b=(a+1)/m*m-1;
      if(b<=0||a-b>d) break;
      //opt=max(opt,z);
      ans=b;
      if(m>a/10) break;
      //z++;
   }
   cout << ans << endl;
   return 0;
}