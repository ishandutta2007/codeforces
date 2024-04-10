// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 77;
int n , a[N];
map < int , bool > M;
inline void Test() {
   scanf("%d" , & n);
   for(int i = 1;i <= n;++ i)
      scanf("%d"  ,a + i);
   sort(a + 1 , a + 1 + n);
   for(int i = 1;i <= n;++ i) {
      if(M[a[i]])
         ++ a[i];
      M[a[i]] = 1;
   }
   printf("%d\n" , M.size());
   M.clear();
}
int main() {
   int te;
   scanf("%d"  ,& te);
   while(te --)
      Test();
   return 0;
}