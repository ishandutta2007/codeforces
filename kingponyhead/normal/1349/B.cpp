# include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 77;
int n , k , a[N] , ps[N] , Mn[N] , L[N];
inline void Test() {
   scanf("%d %d" , & n , & k);
   vector < int > P;
   for(int i = 1;i <= n;++ i) {
      scanf("%d" , a + i);
      if(a[i] == k)
         P.push_back(i);
      if(a[i] == k)
         ps[i] = ps[i - 1] + 1 , L[i] = i;
      if(a[i] < k)
         ps[i] = ps[i - 1] - 1 , L[i] = L[i - 1];
      if(a[i] > k)
         ps[i] = ps[i - 1] + 1 , L[i] = L[i - 1];
      Mn[i] = min(Mn[i - 1] , ps[i]);
   }
   int sz = P.size();
   if(sz == 0) { printf("No\n"); return ; }
   if(sz == n) { printf("Yes\n"); return ; }
   for(int i = 2;i <= n;++ i) {
      if(Mn[i - 2] < ps[i])
         { printf("Yes\n"); return ; }
   }
   printf("No\n");
}

int main() {
   int T;
   scanf("%d" , & T);
   while(T --)
      Test();
   return 0;
}