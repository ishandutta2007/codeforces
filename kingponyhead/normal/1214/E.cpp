// KingPonyHead
# include<bits/stdc++.h>

using namespace std;

const int N = 200000 + 77;
int n , a[N] , P[N];
deque < int > V;
int main() {
   scanf("%d" , & n);
   for(int i = 1;i <= n;++ i) scanf("%d" , a + i) , P[i] = i;
   sort(P + 1 , P + 1 + n , [&] (int x , int y) { return a[x] < a[y]; } );
   for(int i = 1;i < n;++ i) printf("%d %d\n" , P[i] * 2 - 1 , P[i + 1] * 2 - 1);
   for(int i = 1;i <= n;++ i) V.push_back(P[i] * 2 - 1);
   for(int i = n;i > 0;-- i) {
      int who = P[i];
      int len = a[who];
      int sz = (int) V.size();
      int bef = sz - (n - i);
      assert(bef >= len);
      int pos = bef - len;
      printf("%d %d\n" , who * 2 , V[pos]);
      if(pos == 0) V.push_front(who * 2);
   }

   return 0;
}