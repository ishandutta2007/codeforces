#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;

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
   return (ll)x * y % mod;
}

const int MAXN = 1e5 + 5;

int n, m;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   cin >> n;
   cout << 2 << endl;
   rep(i, n - 1) {
      cout << (ll)(i + 2) * (ll)(i + 3) * (ll)(i + 3) - (ll)(i + 1) << endl;
   }
}