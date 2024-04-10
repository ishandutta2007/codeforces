const int MOD = 1e9 + 7;
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

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    //int G = 2 * 3 * 5 * 7 * 9 * 11 * 13;
    //fill(all(a), G);
    cin >> a;

    string s;
    //forn(i, n) s += (rand() % 2 ? '*' : '/');
    cin >> s;

    const int A = 1'000'100;
    vi pr(A);
    for (int i = 2; i < A; i++)
    {
        if (pr[i] == 0)
        {
            for (int j = i; j < A; j += i)
            {
                pr[j] = i;
            }
        }
    }

    vector<vector<pii> > ops(A);
    for (int i = 2; i < A; i++)
    {
        if (pr[i] == i)
        {
            ops[i].push_back({-1, 0});
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x > 1)
        {
            if (ops[pr[x]].back().first == i)
            {
                ops[pr[x]][ops[pr[x]].size() - 1].second += (s[i] == '*' ? 1 : -1);
            }
            else
            {
                ops[pr[x]].push_back({i, ops[pr[x]].back().second + (s[i] == '*' ? 1 : -1)});
            }
            x /= pr[x];
        }
    }

    vector<vector<pii> > arrows(A);
    for (int i = 2; i < A; i++)
    {
        if (pr[i] != i) continue;

        arrows[i].resize(ops[i].size());
//        cout << i << " : ";
//        for (auto e : ops[i])
//        {
//            cout << e.first << " " << e.second << ", ";
//        }
//        cout << "\n";

        vector<pair<int, int> > st;
        st.push_back({n, -1e9});
        for (int j = ops[i].size() - 1; j >= 0; j--)
        {
            while (st.back().second >= ops[i][j].second)
                st.pop_back();
            arrows[i][j].first = ops[i][j].first;
            arrows[i][j].second = st.back().first;
            st.push_back({ops[i][j].first, ops[i][j].second});
        }

//        if (i < 10)
//        {
//            cout << i << " : ";
//            for (auto e : ops[i])
//            {
//                cout << e.fi << " " << e.se << ", ";
//            }
//            cout << "\n";
//        }
    }

    vector<int> pnt(A);
    set<pair<int, int> > lims;

    ll ans = 0;
    for (int i = 2; i < A; i++)
    {
        if (pr[i] == i)
        {
            lims.insert({arrows[i][0].second, i});
        }
    }

    for (int i = 0; i < n; i++)
    {
        int r = (*lims.begin()).first;
        ans += r - i;
        //cout << i << " -> " << r << "\n";

        int lst = 0;
        int x = a[i];
        while (x > 1)
        {
            int y = pr[x];

            if (lst != y)
            {
                lims.erase({arrows[y][pnt[y]].second, y});
                pnt[y]++;
                lims.insert({arrows[y][pnt[y]].second, y});
                lst = y;
            }

            x /= y;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}