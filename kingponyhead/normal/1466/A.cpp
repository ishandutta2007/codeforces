// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 3000 + 77;
int n , a[N];
inline void Test() {
   scanf("%d" , & n);
   for(int i = 1;i <= n;++ i)
      scanf("%d" , a + i);
   set < int > S;
   for(int i = 1;i <= n;++ i)
      for(int j = i + 1;j <= n;++ j)
         S.insert(a[j] - a[i]);
   printf("%d\n" , (int) S.size());
}
int main() {
   int te;
   scanf("%d"  ,& te);
   while(te --)
      Test();
   return 0;
}