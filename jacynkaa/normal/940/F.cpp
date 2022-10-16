#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace std;
using namespace __gnu_pbds;

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
#define value r
#define position l
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

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

const int MAXN = 1e5 + 5;
const int MAXZ = 5e5;
const int S23 = 2200;
const int MAXQ = MAXN;

struct Query {
   int typ;
   int l, r;
   pii kubel;
};

int n, q;
int mex[MAXZ];
int ile[MAXZ];
int res[MAXN];
Query Q[MAXQ];
set<pii> AV;

vector<int> pre() {

   cin >> n >> q;

   vector<int> A(n);
   indexed_set S;

   rep(i, n) {
      cin >> A[i];
      S.insert(--A[i]);
   }

   rep(i, q) {
      cin >> Q[i].typ >> Q[i].l >> Q[i].r;
      Q[i].l--;
      Q[i].r--;
      pii kubel = {Q[i].l / S23, Q[i].r / S23};
      Q[i].kubel = kubel;

      if (Q[i].typ == 1)
         AV.insert(kubel);
      else
         S.insert(Q[i].value);
   }
   rep(i, n) A[i] = S.order_of_key(A[i]);
   rep(i, q) if (Q[i].typ == 2) Q[i].value = S.order_of_key(Q[i].value);

   return A;
}

void add(int x) {
   mex[ile[x]]--;
   mex[++ile[x]]++;
}

void remove(int x) {
   mex[ile[x]]--;
   mex[--ile[x]]++;
}

int get() {
   for (int i = 1;; i++)
      if (mex[i] == 0)
         return i;
}

void solve(vector<int> A, pii kubel) {
   int cur_l = 0;
   int cur_r = -1;
   rep(i, q) {
      if (Q[i].typ == 2) {
         int p = Q[i].position;
         if (p >= cur_l && p <= cur_r) {
            remove(A[p]);
            add(Q[i].value);
         }
         A[p] = Q[i].value;
      } else if (Q[i].kubel == kubel) {
         while (cur_l > Q[i].l)
            add(A[--cur_l]);
         while (cur_r < Q[i].r)
            add(A[++cur_r]);
         while (cur_l < Q[i].l)
            remove(A[cur_l++]);
         while (cur_r > Q[i].r)
            remove(A[cur_r--]);
         res[i] = get();
      }
   }

   // CLEAN
   while (cur_l > 0)
      add(A[--cur_l]);
   while (cur_r > -1)
      remove(A[cur_r--]);
}

int32_t main() {
   _upgrade;
   auto A = pre();
   for (auto kubel : AV)
      solve(A, kubel);
   rep(i, q) if (Q[i].typ == 1) cout << res[i] << endl;
}