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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
   out << '{';
   for (auto it = a.begin(); it != a.end(); it = next(it))
      out << (it != a.begin() ? ", " : "") << *it;
   return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts> void dump(T a, Ts... x) {
   cerr << a << ", ";
   dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

const int MAXN = 2e5 + 99;
const int MAXS = MAXN / 600;

bool tab[1000][MAXN];
vector<int> idx[MAXN];
int numer[MAXN];
int r;
int cnt = 0;

struct zbior {
   vector<int> X;
   int nr = -1;
   int id;

   zbior(const vector<int> &X, int id) : X(move(X)), id(id) {
      if (X.size() >= MAXS) {
         nr = cnt++;
         for (int x : X)
            tab[nr][x] = true;
      }
   }

   bool is_big() { return nr != -1; }

   int get(vector<int> &X) {
      int k = 0;
      for (int i = 0; i < sz(X); i++)
         k += tab[nr][X[i]];
      return k;
   }
};

pii solve_small(vector<zbior> &small) {
   rep(i, sz(small)) for (int x : small[i].X) idx[x].push_back(i);

   pii res = {-1, -1};

   rep(i, r + 2) {

      for (int j : idx[i]) {
         int l = upper_bound(all(small[j].X), i) - small[j].X.begin();
         for (; l < sz(small[j].X); l++) {
            int k = small[j].X[l];
            if (numer[k] != 0)
               res = {numer[k], small[j].id};
            else
               numer[k] = small[j].id;
         }
      }

      for (int j : idx[i]) {
         int l = upper_bound(all(small[j].X), i) - small[j].X.begin();
         for (; l < sz(small[j].X); l++) {
            int k = small[j].X[l];
            numer[k] = 0;
         }
      }

      idx[i].clear();
   }
   return res;
}

pii solve_big(vector<zbior> &big, vector<zbior> &small) {
   pii res = {-1, -1};

   rep(i, sz(big)) {
      rep(j, sz(small)) if (big[i].get(small[j].X) > 1) res = {big[i].id, small[j].id};

      for (int j = i + 1; j < sz(big); j++)
         if (big[i].get(big[j].X) > 1)
            res = {big[i].id, big[j].id};
   }

   return res;
}

int32_t main() {
   int Z;
   cin >> Z;
   while (Z--) {
      int n;
      cin >> n;
      vector<vector<int>> W(n);

      vector<int> R;
      rep(i, n) {
         int k;
         cin >> k;
         W[i].resize(k);
         rep(j, k) {
            cin >> W[i][j];
            R.push_back(W[i][j]);
         }
      }
      sort(all(R));
      R.erase(unique(all(R)), R.end());
      r = sz(R) + 2;

      vector<zbior> small;
      vector<zbior> big;

      rep(i, n) {
         rep(j, sz(W[i])) { W[i][j] = lower_bound(all(R), W[i][j]) - R.begin() + 1; }
         sort(all(W[i]));
         zbior B(W[i], i + 1);
         if (B.is_big())
            big.push_back(B);
         else
            small.push_back(B);
      }

      auto p1 = solve_small(small);
      if (p1 != mp(-1, -1)) {
         cout << p1.st << " " << p1.nd << endl;
         continue;
      }
      auto p2 = solve_big(big, small);
      if (p2 != mp(-1, -1)) {
         cout << p2.st << " " << p2.nd << endl;
         continue;
      }
      cout << -1 << endl;
   }
}