// KALAM
# include<bits/stdc++.h>

using namespace std;

const int N = 1000000 + 77;
int T;
int n , a[N] , X , Y , XX , YY;
long long k;
inline long long __lcm(int x , int y) { return x / __gcd(x , y) * 1ll * y; }
inline bool Check(int mid) {
   int aa = mid / XX;
   int bb = mid / YY;
   int aabb = mid / __lcm(XX , YY);
   aa -= aabb;
   bb -= aabb;
   int cur = n;
   long long A = 0;
   while(cur > 0 && (aabb -- > 0)) A += a[cur --] / 100 * (X + Y);
   while(cur > 0 && (bb -- > 0)) A += a[cur --] / 100 * Y;
   while(cur > 0 && (aa -- > 0)) A += a[cur --] / 100 * X;
   return A >= k;
}
inline void Test() {
   scanf("%d" , & n);
   for(int i = 1;i <= n;++ i) scanf("%d" , a + i);
   scanf("%d %d" , & X , & XX);
   scanf("%d %d" , & Y , & YY);
   if(X > Y) swap(X , Y) , swap(XX , YY);
   scanf("%lld" , & k);
   sort(a + 1 , a + 1 + n);
   int le = 0 , ri = n + 1;
   while(ri - le > 1) {
      int mid = ((le + ri) >> 1);
      if(Check(mid)) ri = mid;
      else le = mid;
   }
   if(ri == n + 1) ri = - 1;
   printf("%d\n" , ri);
}
int main() {
   scanf("%d" , & T);
   while(T --) Test();
   return 0;
}