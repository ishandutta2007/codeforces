const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

void solve()
{
    #define tests

    int n;
    ll d, hp;
    cin >> n >> d >> hp;
    ll g = __gcd(d, hp);
    d /= g;
    hp /= g;

    vector<ll> a(n);
    forn(i, n) cin >> a[i];

    vector<ll> f;
    ll p = d, q = hp;
    while (q)
    {
        f.push_back(p / q);
        ll tmp = p % q;
        p = q;
        q = tmp;
    }

    vector<pair<ll, ll> > convergents;
    convergents.push_back({0, 1});
    convergents.push_back({1, 0});

    pair<ll, ll> X = {d, hp};
    while (convergents.back() != X)
    {
        int sz = convergents.size();
        pair<ll, ll> state = convergents[sz - 2];
        pair<ll, ll> moves = convergents[sz - 1];
        convergents.push_back({state.first + moves.first * f[sz - 2], state.second + moves.second * f[sz - 2]});
    }

    reverse(all(convergents));
    f.push_back(0);
    reverse(all(f));

    ll complete = 0;
    ll peasants = accumulate(a.begin(), a.end(), 0LL);
    vector<pair<ll, ll> > fractions;
    for (int i = 0; i < n; i++)
    {
        complete += a[i] / d;
        a[i] %= d;
        for (int j = convergents.size() % 2; j + 1 < convergents.size(); j += 2)
        {
            if (a[i] >= convergents[j + 1].first && convergents[j].first > 0)
            {
                ll cnt = (a[i] - convergents[j + 1].first) / convergents[j].first;
                int fl = 0;
                if (cnt > f[j])
                {
                    cnt = f[j];
                    fl = 1;
                }
                ll sec = convergents[j + 1].second + convergents[j].second * cnt;
                ll kills = convergents[j + 1].first + convergents[j].first * cnt;

                if (kills > 0)
                {
                    ll cnt2 = a[i] / kills;
                    sec *= cnt2;
                    kills *= cnt2;

                    a[i] -= kills;
                    fractions.push_back({kills, sec});
                }
                if (fl)
                    j -= 2;
            }
        }
        assert(a[i] <= 0);
    }

    sort(all(fractions), [&](pair<ll, ll> a, pair<ll, ll> b){
         return a.first * b.second > a.second * b.first;
         });

    ll ans = 0;
    ans += complete * hp * (peasants - complete * d);
    ans += ((complete * hp + 1) * (complete * d + 1) - complete) / 2 - complete * d;
    peasants -= complete * d;

    for (auto e : fractions)
    {
        ans += (peasants - e.first) * e.second;
        ans += ((e.first + 1) * (e.second + 1) - __gcd(e.first, e.second)) / 2 - e.first;
        peasants -= e.first;
    }
    cout << ans + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}