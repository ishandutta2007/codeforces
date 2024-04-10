#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define fs first
#define sc second
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 3e5 + 20;
int n, k;
pii a[N];
vector<pii> add[N];
struct Node {
   int l, r, v;
   bool operator < (const Node &b) const {
      return l < b.l;
   }
};
set<Node> S;
typedef set<Node>::iterator odt;
odt split(int x) { // [l, x-1] & [x, r]
   odt it = -- S.upper_bound({x, 0, 0});
   if(it->l == x) return it;
   Node z = *it; S.erase(it);
   S.insert({z.l, x - 1, z.v});
   return S.insert({x, z.r, z.v}).fs;
}
void init() {
   S.insert({1, (int) 1e9 + 7, 0});
   rep(i, 1, n) {
      odt epos = split(a[i].sc + 1), st = split(a[i].fs);
      for(odt it = st; it != epos; it ++) {
         add[i].pb(mp(it->v + 1, it->r - it->l + 1));
      }
      S.erase(st, epos);
      S.insert({a[i].fs, a[i].sc, i});
   }
}
pair<ll, ll> check(int mid) {
   static ll arr[N];
   fill(arr, arr + n + 1, 0);
   ll sum = 0, cnt = 0, sum2 = 0;
   int l = 0, w = 0;
   rep(i, 1, n) {
      for(auto &v : add[i]) {
         arr[max(v.fs, l + 1)] += v.sc;
         arr[i + 1] -= v.sc;
         if(v.fs <= l) sum += v.sc * (l - v.fs + 1ll);
      }
      while(l < i && w + arr[l + 1] >= mid) {
         w += arr[++ l];
         sum += w;
      }
      cnt += l;
      sum2 += sum;
   }
   return mp(cnt, sum2);
}
int main() {
   scanf("%d%d", &n, &k);
   rep(i, 1, n) scanf("%d%d", &a[i].fs, &a[i].sc), a[i].sc --;
   init();
   int l = 0, r = 1e9, mid;
   ll low = 0, cnt = 0, sum = 0;
   while(l <= r) {
      mid = (l + r) >> 1;
      auto res = check(mid);
      if(res.fs >= k) {
         l = (low = mid) + 1;
         sum = res.sc;
         cnt = res.fs;
      } else r = mid - 1;
   }
   printf("%lld\n", sum - (cnt - k) * low);
   return 0;
}