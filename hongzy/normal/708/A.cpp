#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n;
char s[N];
int main() {
   scanf("%s", s + 1);
   n = strlen(s + 1);
   bool t = 0;
   rep(i, 1, n) if(s[i] != 'a') {
      int r = i;
      while(r < n && s[r + 1] != 'a') r ++;
      rep(j, i, r) s[j] --;
      t = 1;
      break ;
   }
   if(!t) {
      s[n] = 'z';
   }
   puts(s + 1);
   return 0;
}