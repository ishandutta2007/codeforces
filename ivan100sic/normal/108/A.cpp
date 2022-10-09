#include <cstdio>
using namespace std;

long Dgt[4];

void nacifre(long x){
   Dgt[0] = x % 10;
   x/=10;
   Dgt[1] = x % 6;
   x/=6;
   Dgt[2] = x % 10;
   Dgt[3] = x / 10;
}

bool palindrom(long t){
   nacifre(t);
   return (Dgt[0]==Dgt[3] && Dgt[1]==Dgt[2]);
}

int main(){
   long t0,hh,mm;
   scanf("%ld:%ld",&hh,&mm);
   t0=(60*hh+mm+1) % 1440;
   while (!palindrom(t0)){
      t0++;
      if (t0==1440) t0=0;
   }
   nacifre(t0);
   printf("%ld%ld:%ld%ld",Dgt[3],Dgt[2],Dgt[1],Dgt[0]);
   return 0;
}