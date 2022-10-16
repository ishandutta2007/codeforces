#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
#ifdef LOCAL
ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class L, class R, class S> ostream &operator<<(ostream &out, tuple<L, R, S> p) {
   auto &[a, b, c] = p;
   return out << "(" << a << ", " << b << ", " << c << ")";
}
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
#else
#define debug(...) 42
#endif

// pu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xto
//                                  pology nonstop_tsc cpuid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid dca sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand
//                                   lahf_lm abm 3dnowprefetch cpuid_fault epb cat_l3 cdp_l3 invpcid_single pti intel_ppin ssbd mba ibrs ibpb stibp tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms
//                                   invpcid rtm cqm mpx rdt_a avx512f avx512dq rdseed adx smap clflushopt clwb intel_pt avx512cd avx512bw avx512vl xsaveopt xsavec xgetbv1 xsaves cqm_llc cqm_occup_llc cqm_mbm_total cqm_mbm_local dtherm ida a
//                                  rat pln pts pku ospke md_clear flush_l1d

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,avx2,tune=native")

#define int long long
const int MAXN = 1e5 + 99;

int tab1[MAXN];
int tab2[MAXN];

int n, m, q;

void deb() {
   rep(i, n + 1) debug(i, tab1[i]);
   rep(i, m + 1) debug(i, tab2[i]);
}

int32_t main() {
   _upgrade;
   n = 100;
   m = q = 1e5;

   cin >> n >> m >> q;
   int last = 0;

   rep(i, n) {
      int a;
      a = last + i;

      cin >> a;
      tab1[i] = a - last;
      last = a;
   }

   last = 0;
   int S = 0;
   rep(i, m) {
      int a;
      a = last + i;

      cin >> a;
      tab2[i] = a - last;
      S += a;
      last = a;
   }

   // deb();

   debug("WTF");

   while (q--) {
      int t, k, d;
      t = 2;
      k = m;
      d = 100;
      cin >> t >> k >> d;
      if (t == 1) {
         for (int i = n - 1; i >= n - k; i--)
            tab1[i] += d;
      } else {
         S += d * k * (k + 1) / 2;
         for (int i = m - 1; i >= m - k; i--)
            tab2[i] += d;
      }

      //   deb();

      vector<int> I = {0};
      vector<int> V;

      int res = S;
      // debug(S);
      int val = 0;

      rep(i, n - 1) {
         val += tab1[i];
         V.push_back(val);
         // assert(is_sorted(tab2 + 1, tab2 + m));
         auto idx = upper_bound(tab2 + 1, tab2 + m, tab1[i + 1]) - tab2 - 1;
         I.push_back(idx);
      }
      // debug("AL", n);
      val += tab1[n - 1];
      V.push_back(val);
      I.push_back(m - 1);

      // debug(S, I, V);

      rep(i, n) res += V[i] * (I[i + 1] - I[i] + 1);

      // debug(res);

      // debug(I);

      int cur = tab2[0];

      rep(i, n - 1) {
         int a = I[i];
         int b = I[i + 1];
         for (int l = a + 1; l <= b; l++)
            cur += tab2[l];
         // debug(cur);
         res += cur;
      }
      cout << res << "\n";
   }
   //  cout << accumulate(tab2, tab2 + MAXN, 0ll) << endl;
}