#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[100005];

int main() {
   int N, M; scanf("%d%d", &N, &M);
   for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
   sort(A + 1, A + N + 1);
   ll s = 0; for(int i = 1; i <= N; i++) s += A[i];

   int h = 0;
   ll ans = 0;
   for(int i = 1; i <= N; i++) {
      ans++;
      if(h < A[i]) h++;
   }
   for(; h <= A[N] - 1; h++) {
      ans++;
   }
   printf("%lld\n", s - ans);

   return 0;
}