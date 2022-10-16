#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
using namespace __gnu_pbds;
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
//mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
//struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
//gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

ostream &operator<<(ostream &out, string str)
{
    for (char c : str)
        out << c;
    return out;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> p)
{
    return out << "(" << p.st << ", " << p.nd << ")";
}
template <class T>
auto operator<<(ostream &out, T a) -> decltype(a.begin(), out)
{
    out << '{';
    for (auto it = a.begin(); it != a.end(); it = next(it))
        out << (it != a.begin() ? ", " : "") << *it;
    return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts>
void dump(T a, Ts... x)
{
    cerr << a << ", ";
    dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

int n, q;
int licznik = 0;
const int inf = 1e9;

int32_t main()
{
    _upgrade;
    cin >> n >> q;
    vector<int> A(n + 1, -1);
    indexed_set S;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a == i)
        {
            S.insert({-i, licznik++});
            A[i] = i;
        }
        if (a < i)
        {
            int x = i - a - 1;
            if ((int)S.size() > x)
            {
                int res = -S.find_by_order(x)->st;
                S.insert({-res, licznik++});
                A[i] = res;
            }
        }
    }

    vector<vector<pii>> Q(n + 2);
    vector<int> ans(q + 1, 0);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        Q[x].emplace_back(+i, x);
        Q[n - y].emplace_back(-i, x);
    }

    S = indexed_set();
    for (int i = n; i >= 0; i--)
    {

        for (auto p : Q[i])
            ans[abs(p.st)] += (S.size() - S.order_of_key({p.nd, inf})) * (p.st > 0 ? 1 : -1);

        S.insert({A[i], licznik++});
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
    cout << endl;
}