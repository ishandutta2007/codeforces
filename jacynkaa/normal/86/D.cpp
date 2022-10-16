#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) // cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

const int S = 400;
const int ZAKRES = 1e6 + 99;

int tab[ZAKRES];
long long ile[ZAKRES];
int odp[ZAKRES];
long long res = 0;

struct Query {
   int l, r, idx;
   bool operator<(Query other) const {
      if (l / S != (other.l) / S)
         return l < other.l;
      return ((l / S) & 2) ? r < other.r : r > other.r;
   }
};

void add(int x) {
   res += (2 * ile[tab[x]] + 1) * tab[x];
   ile[tab[x]]++;
}

void remove(int x) {
   res -= (2ll * ile[tab[x]] - 1) * tab[x];
   ile[tab[x]]--;
}

void solve(vector<Query> V) {
   sort(all(V));
   int cur_l = 0;
   int cur_r = -1;
   for (auto [l, r, idx] : V) {
      while (cur_l > l)
         add(--cur_l);
      while (cur_r < r)
         add(++cur_r);
      while (cur_l < l)
         remove(cur_l++);
      while (cur_r > r)
         remove(cur_r--);

      odp[idx] = res;
   }
}

main() {
   _upgrade;
   int n, t;
   cin >> n >> t;
   rep(i, n) cin >> tab[i + 1];
   vector<Query> V(t);
   rep(i, t) {
      cin >> V[i].l >> V[i].r;
      V[i].idx = i;
   }
   solve(V);
   rep(i, t) cout << odp[i] << " " << endl;
}