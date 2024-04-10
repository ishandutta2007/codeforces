#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, mod = 1e9 + 7;

ll dub(ll x) {
   ll ret = 0;
   while(x) {
      x /= 2;
      ret ++;
   }
   return ret;
}

unordered_map<ll, ll> rd;

void inc(ll x, ll y, ll w) {
   if(dub(x) < dub(y)) swap(x, y);
   while(dub(x) != dub(y)) {
      rd[x] += w;
      x /= 2;
   }
   while(x != y) {
      rd[x] += w;
      rd[y] += w;
      x /= 2;
      y /= 2;
   }
}

ll query(ll x, ll y) {
   ll ret = 0;
   if(dub(x) < dub(y)) swap(x, y);
   while(dub(x) != dub(y)) {
      ret += rd[x];
      x /= 2;
   }
   while(x != y) {
      ret += rd[x] + rd[y];
      x /= 2;
      y /= 2;
   }
   return ret;
}

void load() {
   int n; cin >> n;
   rep(i, n) {
      int tip; cin >> tip;
      if(tip == 1) {
         ll x, y, w; cin >> x >> y >> w;
         inc(x, y, w);
      }else {
         ll x, y; cin >> x >> y;
         cout << query(x, y) << endl;
      }
   }
}

void solve() {

}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   load();
   solve();
}