#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

inline bool islucky(int x) {
   if(x<=0) return 0;
   while(x) {
      int d=x%10;
      if(d!=4&&d!=7) return 0;
      x/=10;
   }
   return 1;
}

inline bool near(long long x) {
   int c=0;
   while(x) {
      int d=x%10;
      if(d==4||d==7) c++;
      x/=10;
   }
   return islucky(c);
}

inline string solve(long long x) {
   return near(x)?"YES":"NO";
}

int main(void)
{
   long long x;
   cin >> x;
   cout << solve(x) << endl;
}