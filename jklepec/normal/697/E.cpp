#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;

int add(int x, int y) {
   x += y;
   if(x >= mod) return x - mod;
   return x;
}
int sub(int x, int y) {
   x -= y;
   if(x < 0) return x + mod;
   return x;
}
int mul(int x, int y) {
   return (ll) x * y % mod;
}
int exp(int x, ll y) {
   int ret = x;
   y --;
   while(y) {
      if(y % (ll) 2) ret = mul(ret, x);
      x = mul(x, x);
      y /= 2;
   }
   return ret;
}
int inv(int x) {
   return exp(x, mod - 2);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n; cin >> n;

   int a, b = 2;

   bool paran = false, all_ones = true;

   rep(i, n) {
      ll x; cin >> x;
      b = exp(b, x);

      if(x != 1) all_ones = false;
      if(x % (ll) 2 == 0) paran = true;
   }

   if(all_ones) {
      cout << "0/1";
      return 0;
   }

   b = mul(b, inv(2));

   a = sub(b, 1);
   if(paran) {
      a = add(b, 1);
   }

   a = mul(a, inv(3));

   cout << a << '/' << b;
}