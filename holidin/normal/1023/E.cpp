#ifndef LOCAL
#pragma GCC optimize ("O3")
#endif

#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(x...) " [" #x ": " << (x) << "] "

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename A, typename B>
using unordered_map2 = __gnu_pbds::gp_hash_table<A, B>;
using namespace __gnu_pbds;
template <typename T> using ordered_set =
  __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,
                   __gnu_pbds::tree_order_statistics_node_update>;
// ordered_set<int> s; s.insert(1); s.insert(2);
 // s.order_of_key(1);   // Out: 0.
// *s.find_by_order(1);  // Out: 2.

using ld = long double;
using ll = long long;

constexpr int mod = 1000 * 1000 * 1000 + 7;
constexpr int odw2 = (mod + 1) / 2;

void OdejmijOd(int& a, int b) { a -= b; if (a < 0) a += mod; }
int Odejmij(int a, int b) { OdejmijOd(a, b); return a; }
void DodajDo(int& a, int b) { a += b; if (a >= mod) a -= mod; }
int Dodaj(int a, int b) { DodajDo(a, b); return a; }
int Mnoz(int a, int b) { return (ll) a * b % mod; }
void MnozDo(int& a, int b) { a = Mnoz(a, b); }
int Pot(int a, int b) { int res = 1; while (b) { if (b % 2 == 1) MnozDo(res, a); a = Mnoz(a, a); b /= 2; } return res; }
int Odw(int a) { return Pot(a, mod - 2); }
void PodzielDo(int& a, int b) { MnozDo(a, Odw(b)); }
int Podziel(int a, int b) { return Mnoz(a, Odw(b)); }
int Moduluj(ll x) { x %= mod; if (x < 0) x += mod; return x; }

template <typename T> T Maxi(T& a, T b) { return a = max(a, b); }
template <typename T> T Mini(T& a, T b) { return a = min(a, b); }

int n;

bool Ok(int r1, int c1, int r2, int c2) {
  assert(1 <= r1 and r1 <= r2 and r2 <= n);
  assert(1 <= c1 and c1 <= c2 and c2 <= n);
  assert((r2 - r1) + (c2 - c1) >= n - 1);
  cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  string res;
  cin >> res;
  assert(!res.empty());
  if (res[0] == 'Y') return true;
  assert(res[0] == 'N');
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string result;
  int r = 1, c = 1;
  for (int i = 0; i < n - 1; i++) {
    if (Ok(r + 1, c, n, n)) {
      result.push_back('D');
      r++;
    } else {
      result.push_back('R');
      c++;
    }
  }
  string res2;
  int r2 = n, c2 = n;
  for (int i = 0; i < n - 1; i++) {
    if (Ok(1, 1, r2, c2 - 1)) {
      res2.push_back('R');
      c2--;
    } else {
      res2.push_back('D');
      r2--;
    }
  }
  reverse(res2.begin(), res2.end());
  assert(r == r2 and c == c2);
  cout << "! " << result << res2 << endl;
  return 0;
}