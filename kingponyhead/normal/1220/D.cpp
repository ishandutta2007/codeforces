// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 200000 + 77;
int n , b[N] , T[N];
long long g , a[N];
vector < long long > A;
int main() {
   scanf("%d" , & n);
   for(int i = 1;i <= n;++ i) scanf("%lld" , a + i);
   for(int i = 1;i <= n;++ i) {
      int f = 0;
      long long x = a[i];
      while((x & 1ll) == 0)
         ++ f , x >>= 1;
      b[i] = f;
      ++ T[b[i]];
   }
   int best = 0;
   for(int i = 1;i < N;++ i)
      if(T[i] > T[best])
         best = i;
   for(int i = 1;i <= n;++ i)
      if(b[i] != best)
         A.push_back(a[i]);
   printf("%d\n" , (int) A.size());
   for(long long x : A)
      printf("%lld " , x);
   return 0;
}