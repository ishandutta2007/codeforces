#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

const int inf = 1e9 + 5, MAXN = 2e5 + 5;

int f1[MAXN], f2[MAXN];

void upd(int x, int v) {
   ++x;
   for(; x < MAXN; x += x & -x) f1[x] = max(f1[x], v);
}
int get(int x) {
   ++x;
   int ret = 0;
   for(; x; x -= x & -x) ret = max(f1[x], ret);
   return ret;
}
void umn(int x, int v) {
   ++x;
   for(; x < MAXN; x += x & -x) f2[x] = min(f2[x], v);
}
int gmn(int x) {
   ++x;
   int ret = 2 *inf;
   for(; x; x -= x & -x) ret = min(f2[x], ret);
   return ret;
}

int a[MAXN], b[MAXN];

long long sol;
int lo, hi, mx, mn;

bool check(int x) {
   return gmn(x) == get(x);
}

void solve() {
   int n; cin >> n;
   rep(i, n) {
      cin >> a[i];
      a[i] += inf;
   }
   rep(i, n) {
      cin >> b[i];
      b[i] += inf;
   }
   for(int j = n - 1; j >= 0; --j) {
      upd(j, a[j]);
      umn(j, b[j]);
      lo = j; hi = n - 1;
      while(lo < hi) {
         int mid = (lo + hi + 1) >> 1;
         mx = get(mid);
         mn = gmn(mid);
         if(mx > mn)
            hi = mid - 1;
         else
            lo = mid;
      }
      int r = lo;
      lo = j; hi = n - 1;
      while(lo < hi) {
         int mid = (lo + hi) >> 1;
         mx = get(mid);
         mn = gmn(mid);
         if(mx < mn)
            lo = mid + 1;
         else
            hi = mid;
      }
      int l = lo;
      if(check(l) && check(r)) sol += r - l + 1;
   }
   cout << sol;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   rep(i, MAXN) f2[i] = 2 * inf;
   solve();
}