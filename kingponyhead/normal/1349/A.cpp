# include<bits/stdc++.h>

using namespace std;

const int N = 200000 + 77;
int n , P[N];
long long A = 1;
vector < int > D[N] , V[N];
int main() {
   for(int i = 2;i < N;++ i) {
      if(P[i])
         continue ;
      for(int j = i;j < N;j += i)
         D[j].push_back(i);
   }
   scanf("%d" , & n);
   for(int x , i = 1;i <= n;++ i) {
      scanf("%d" , & x);
      int t = x;
      for(int p : D[x]) {
         int cnt = 0;
         while(t % p == 0)
            t /= p , ++ cnt;
         V[p].push_back(cnt);
      }
   }
   for(int i = 2;i < N;++ i) {
      int sz = V[i].size();
      if(sz <= n - 2)
         continue ;
      int idx = 1;
      if(sz == n - 1)
         idx = 0;
      sort(V[i].begin() , V[i].end());
      int c = V[i][idx];
      while(c --)
         A *= i;
   }
   printf("%lld\n" , A);
   return 0;
}