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
     
    #define int long long
    const int MAXN = 404;
     
    int M;
    int dp[MAXN][MAXN];
    int fact[MAXN];
    int inv[MAXN];
    int bin[MAXN][MAXN];
     
    ull mod_mul(ull a, ull b, ull M) {
       ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
       return ret + M * (ret < 0) - M * (ret >= (ll)M);
    }
     
    ull mod_pow(ull b, ull e, ull mod) {
       ull ans = 1;
       for (; e; b = mod_mul(b, b, mod), e /= 2)
          if (e & 1)
             ans = mod_mul(ans, b, mod);
       return ans;
    }
     
    int32_t main() {
       _upgrade;
       int n;
       cin >> n >> M;
     
       fact[0] = 1;
     
       for (int i = 1; i < MAXN; i++)
          fact[i] = (fact[i - 1] * i) % M;
     
       rep(i, MAXN) inv[i] = mod_pow(fact[i], M - 2, M);
     
       rep(i, MAXN) rep(j, MAXN) if (i >= j) bin[i][j] = (((inv[j] * inv[i - j]) % M) * fact[i]) % M;
     
       dp[1][1] = 1;
     
       for (int x = 2; x <= n; x++) {
     
          for (int k = 1; k <= x; k++)
             dp[x][k] = 2 * (dp[x - 1][k - 1] + dp[x - 2][k - 1]);
     
          for (int i = 1; i <= (x - 1) / 2; i++) {
             int A = i;
             int B = x - i - 1;
     
             int mnoznik = (i == ((x - 1) / 2) && (x & 1)) ? 1 : 2;
     
             if (A > 0 && B > 0)
                for (int l = A / 2; l <= A; l++)
                   for (int r = B / 2; r <= B; r++) {
                      int val = (dp[A][l] + dp[A - 1][l]) * (dp[B][r] + dp[B - 1][r]) - (dp[A][l]) * (dp[B][r]);
                      val *= mnoznik;
                      val %= M;
                      val *= bin[l + r][l];
                      dp[x][l + r + 1] = (val + dp[x][l + r + 1]) % M;
                   }
          }
          rep(i, MAXN) dp[x][i] = (dp[x][i] % M + M) % M;
       }
     
       int res = 0;
       rep(i, MAXN) res += dp[n][i];
       cout << res % M << endl;
    }