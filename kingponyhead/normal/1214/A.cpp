// KingPonyHead
# include<bits/stdc++.h>

using namespace std;

const int N = 1000000 + 77 , L = 40000000;
int n , d , e , A;
int main() {
   scanf("%d %d %d" , & n , & d , & e);
   A = n;
   e *= 5;
   for(int i = 0;i <= L;++ i) {
      long long rem = n;
      rem -= d * 1ll * i;
      if(rem < 0) continue ;
      A = min(A * 1ll , rem % e);
   }
   printf("%d\n" , A);
   return 0;
}