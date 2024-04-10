#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e4 + 10, MAX = 1e5 + 5;

stack<pair<int, lf> > S[MAX];

int a[MAX];

lf sve[MAXN];
lf dummyy[MAXN];
lf dummy[MAXN / 2][MAXN];
int cookie = 0;

lf* Merge(vector<lf*> &v) {
   lf* ret = dummy[cookie++];
   REP(i, v.size()) {
      FOR(j, 1, MAXN - 2) {
         v[i][j] = v[i][j] + v[i][j - 1];
      }
   }
   REP(i, MAXN - 2) {
      sve[i] = 1;
      REP(j, v.size())
         sve[i] *= v[j][i];
      ret[i] = sve[i];
      if(i)
         ret[i] -= sve[i - 1];
   }
   return ret;
}

lf* samp(int x) {
   memset(dummyy, 0, sizeof dummyy);
   lf* ret = dummyy;
   ret[x] = 1;
   return ret;
}

void povecaj(lf* &arr, lf x) {
   for(int i = MAXN - 2; i >= 0; --i) {
      if(i) {
         arr[i] = arr[i] * ((lf) 1 - x) + x * arr[i - 1];
      }
      else {
         arr[i] = arr[i] * ((lf) 1 - x);
      }
   }
}

lf* f(int l, int r) {

   vector<lf*> v;

   bool ima = false; int mx = 0;
   for(int i = l; i < r; ++i) {
      if(!S[i].size()) {
         ima = true;
         mx = max(mx, a[i]);
      }
      else {
         vector<lf> zap;
         int R = S[i].top().first;
         while(S[i].size() && S[i].top().first == R) {
            zap.push_back(S[i].top().second);
            S[i].pop();
         }
         lf* ubaci = f(i, R + 1);
         for(lf x : zap)
            povecaj(ubaci, x);
         v.push_back(ubaci);
         i = R;
      }
   }
   if(ima) {
      v.push_back(samp(mx));
   }

   lf* ret = Merge(v);
   return ret;
}

vector<pair<int, lf> > vek[MAX];
vector<lf> fin;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
   int n, q; cin >> n >> q;

   int mx = 0;
   REP(i, n) {
      cin >> a[i];
      mx = max(mx, a[i]);
   }
   mx = max(0, mx - 5000 - 5);
   REP(i, n) {
      a[i] = max(0, a[i] - mx);
   }

   REP(i, q) {
      int l, r; lf x;
      cin >> l >> r >> x;
      if(l == 1 && r == n) {
         fin.push_back(x);
         continue;
      }
      vek[l - 1].emplace_back(r - 1, x);
   }

   REP(i, n) {
      if(!vek[i].size()) continue;
      sort(vek[i].begin(), vek[i].end());
      REP(j, vek[i].size()) {
         S[i].push(vek[i][j]);
      }
   }

   lf* sol = f(0, n);
   lf ispis = mx;
   for(auto x : fin)
      povecaj(sol, x);
   FOR(i, 1, MAXN - 2) {
      ispis += sol[i] * i;
   }
   cout << fixed << setprecision(7) << ispis;
}