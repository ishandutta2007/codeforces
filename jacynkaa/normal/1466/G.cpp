#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
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
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())

#ifdef LOCAL
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
#else
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   {}
#endif

#define int long long
typedef long long ll;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 2e6;
const int alpha = 40;

long long fas_pow(long long podstawa, long long wykladnik) {
   if (wykladnik == 0)
      return 1;
   if ((wykladnik & 1) == 0) {
      long long x = fas_pow(podstawa, wykladnik / 2);
      return (x * x) % MOD;
   }
   return (podstawa * fas_pow(podstawa, wykladnik - 1)) % MOD;
}

struct H {
   typedef uint64_t ull;
   ull x;
   H(ull x = 0) : x(x) {}
#define OP(O, A, B)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    \
   H operator O(H o) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 \
      ull r = x;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       \
      asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
      return r;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
   }
   OP(+, , "d"(o.x)) OP(*, "mul %1\n", "r"(o.x) : "rdx") H operator-(H o) { return *this + ~o.x; }
   ull get() const { return x + !~x; }
   bool operator==(H o) const { return get() == o.get(); }
   bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11 + 3; // (order ~ 3e9; random also ok)

struct HashInterval {
   vector<H> ha, pw;
   HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
      pw[0] = 1;
      fwd(i, 0, sz(str)) ha[i + 1] = ha[i] * C + str[i], pw[i + 1] = pw[i] * C;
   }
   H hashInterval(int a, int b) { // hash [a, b)
      return ha[b] - ha[a] * pw[b - a];
   }
};

vector<H> getHashes(string &str, int length) {
   if (sz(str) < length)
      return {};
   H h = 0, pw = 1;
   fwd(i, 0, length) h = h * C + str[i], pw = pw * C;
   vector<H> ret = {h};
   fwd(i, length, sz(str)) { ret.push_back(h = h * C + str[i] - pw * str[i - length]); }
   return ret;
}

H hashString(string &s) {
   H h{};
   trav(c, s) h = h * C + c;
   return h;
}

int POW[MAXN];
string tab[MAXN];
vector<int> MM[MAXN];

void pre() {
   rep(i, MAXN) { POW[i] = i == 0 ? 1 : (2 * POW[i - 1]) % MOD; }
}

pair<int, vector<int>> get(string w, string S) {

   int l = 0;
   auto hh = getHashes(S, sz(w));
   auto h = hashString(w);

   for (auto th : hh)
      if (th == h)
         l++;

   // auto Sp = S;
   // reverse(all(Sp));
   vector<int> M(alpha);

   HashInterval W = HashInterval(w);
   HashInterval H = HashInterval(S);
   // HashInterval H2 = HashInterval(Sp);
   debug(w, S);

   rep(i, sz(w)) {
      debug(i, sz(w));
      debug(W.hashInterval(0, i).get());
      debug(H.hashInterval(sz(S) - i, sz(S)).get());
      debug(W.hashInterval(i + 1, sz(w)).get());
      debug(H.hashInterval(0, sz(w) - i - 1).get());
      if (W.hashInterval(0, i) == H.hashInterval(sz(S) - i, sz(S)) && W.hashInterval(i + 1, sz(w)) == H.hashInterval(0, sz(w) - i - 1))
         M[w[i] - 'a']++;
   }
   return {l, M};
}

int32_t main() {
   _upgrade;
   pre();

   int n, q;
   cin >> n >> q;

   string S, T;
   cin >> S >> T;
   debug(S, T);
   tab[0] = S;

   MM[n + 1] = vector<int>(alpha);
   for (int i = n; i > 0; i--) {
      MM[i] = MM[i + 1];
      MM[i][T[i - 1] - 'a'] += POW[n - i];
      MM[i][T[i - 1] - 'a'] %= MOD;
      debug(i, MM[i]);
   }

   for (int i = 1; i <= n; i++) {
      tab[i] = tab[i - 1] + string(1, T[i - 1]) + tab[i - 1];
      if (sz(tab[i]) > 1e6 + 99)
         break;
   }

   rep(j, q) {
      int k;
      cin >> k;
      string w;
      cin >> w;
      int l = 0;
      for (; l < k; l++)
         if (sz(tab[l]) > sz(w))
            break;
      debug(l, tab[l], w);
      if (sz(tab[l]) < sz(w)) {
         cout << 0 << endl;
         continue;
      }

      debug(l, k, tab[l], w);
      auto P = get(w, tab[l]);
      debug(P);

      int res = (P.st * POW[k - l]) % MOD;
      int odw = fas_pow(POW[n - k], MOD - 2);
      rep(i, alpha) {
         auto t = P.nd[i];
         int r1 = ((MM[l + 1][i] - MM[k + 1][i] + 2 * MOD) * t) % MOD;
         r1 *= odw;
         r1 %= MOD;
         debug(r1);
         res = (res + r1) % MOD;
      }
      cout << res << endl;
   }
}