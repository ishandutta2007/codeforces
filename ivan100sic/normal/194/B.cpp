#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b){
   if (b!=0) return gcd(b,a%b); else return a;
}

long long solve(int x){
   long long xx = x;
   //if (xx==1) return 3;
   //if (xx==3) return 4;
   if (xx%4==3) return xx+1;
   if (xx%2==1) return 2*x + 1;
   return 4*x + 1;
}

int main(){
   long long x,t;
   scanf("%I64d",&t);
   while (t>0){
      t--;
      scanf("%I64d",&x);
      printf("%I64d\n",(4*x / gcd(4*x, x+1)) + 1);
   }
   return 0;
}