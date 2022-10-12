const long long MOD = 1e9 + 7;
const long long INF = 1e9;
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

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

void solve()
{
    int n;
    cin >> n;
    vector<int> cur_values(n);
    vector<int> ok(n);
    fill(all(ok), 1);
    iota(all(cur_values), 0);

    int lst = 0;
    while (1)
    {
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (ok[i] == 1 && cur_values[i] / n == lst)
                cnt++;
            else
                ok[i] = 0;
        }
        if (cnt == 1)
        {
            for (int i = 1; i < n; i++)
            {
                if (ok[i] && cur_values[i] / n == lst)
                    cnt = cur_values[i];
            }
            cout << "! " << cnt << endl;
            return;
        }
        else
        {
            int opt = 0, diff = 599595;
            for (int add = 1; add < n; add++)
            {
                int c_same = 0, c_more = 0;
                for (int i = 1; i < n; i++)
                {
                    if (ok[i] == 0) continue;
                    if ((cur_values[i] + add) / n == lst)
                        c_same++;
                    else
                        c_more++;
                }
                if (abs(c_same - c_more) < diff)
                {
                    diff = abs(c_same - c_more);
                    opt = add;
                }
            }
            cout << "+ " << opt << endl;
            cin >> lst;
            for (int i = 1; i < n; i++)
                cur_values[i] += opt;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}