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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
//mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
//struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
//gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

int odp[1000000];
int tab[1000000];

vector<pii> liczby;
int n, m;
vector<pair<pii, int>> Z;
indexed_set S;

void solve()
{
    int cur = -1;
    for (auto z : Z)
    {
        while (cur < z.st.st)
        {
            cur++;
            S.insert(abs(liczby[cur].nd));
        }
        odp[z.nd] = tab[*S.find_by_order(z.st.nd)]; //UWAGA
    }
    rep(i, m) cout << odp[i] << endl;
}

void pre()
{
    cin >> n;
    rep(i, n)
    {
        cin >> tab[i];
        liczby.push_back({tab[i], -i});
    }
    cin >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;

        Z.push_back({{--a, --b}, i});
    }
    sort(all(Z));
    sort(all(liczby), greater<pii>());
}

main()
{
    _upgrade;
    pre();
    solve();
}