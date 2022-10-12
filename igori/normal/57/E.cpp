const long long MOD = 1e9 + 7;
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

//int cx[4] = {-1, 0, 1, 0};
//int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

vector<int> cx = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> cy = {2, -2, 2, -2, 1, -1, 1, -1};

void solve()
{
    ll k, n;
    cin >> k >> n;

    int s = 500;
    vector<vector<int> > dist(2 * s + 1, vector<int>(2 * s + 1));
    dist[s][s] = 1;

    vector<pair<int, int> > q;
    q.push_back({s, s});

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x += s, y += s;
        dist[x][y] = -1;
    }

    vector<int> cnt;
    for (int i = 0; i < q.size(); i++)
    {
        int x = q[i].first;
        int y = q[i].second;
        //cout << cnt << "\n";
        if (cnt.size() < dist[x][y])
        {
            int sz = (int)cnt.size() - 1;
            if (cnt.size() >= 50 && cnt[sz] - cnt[sz - 1] == cnt[sz - 1] - cnt[sz - 2])
            {
                ll ans = 0;
                for (int di = 0; di <= k && di < cnt.size(); di++)
                {
                    ans += cnt[di];
                }
                if (k <= sz)
                {
                    cout << ans << "\n";
                    return;
                }
                ll diff = cnt[sz] - cnt[sz - 1];
                ll fst = cnt[sz] + diff; // on dist sz + 1
                ll lst = cnt[sz] + diff * ((k - sz) % MOD); // on dist k
                ll cnt = (k - sz) % MOD;
                lst %= MOD;
                ans = (ans + cnt * (fst + lst) % MOD * (MOD + 1) / 2 % MOD) % MOD;
                cout << ans << "\n";
                return;
            }
            cnt.push_back(0);
        }
        cnt[dist[x][y] - 1]++;
        for (int j = 0; j < 8; j++)
        {
            int nx = x + cx[j];
            int ny = y + cy[j];
            if (dist[nx][ny] == 0)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= k && i < cnt.size(); i++)
    {
        ans += cnt[i];
    }
    cout << ans << "\n";
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