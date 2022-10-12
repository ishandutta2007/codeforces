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

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
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

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

const int N = 696969;

int go[N][26];
int link[N];
int interest_link[N];
int sz = 1;
set<pair<int, int>, greater<pii> > term[N];
int where[N];
int cur[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int pnt = 0;
        for (int j = 0; j < s.size(); j++)
        {
            int x = s[j] - 'a';
            if (go[pnt][x] == 0)
                go[pnt][x] = sz++;
            pnt = go[pnt][x];
        }
        where[i] = pnt;
        term[pnt].insert({0, i});
    }
    vector<int> q = {0};
    for (int i = 0; i < q.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (go[q[i]][j] != 0)
            {
                int b = link[q[i]];
                int d = j;
                while (b != 0 && go[b][d] == 0)
                {
                    b = link[b];
                }
                if (go[b][d] != go[q[i]][j])
                    link[go[q[i]][j]] = go[b][d];
                q.push_back(go[q[i]][j]);
            }
        }
    }
    for (auto i : q)
    {
        int j = link[i];
        if (term[j].size()) interest_link[i] = j;
        else interest_link[i] = interest_link[j];
    }
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;
            int wh = where[i];
            term[wh].erase({cur[i], i});
            cur[i] = x;
            term[wh].insert({cur[i], i});
        }
        else
        {
            int pnt = 0;
            string s;
            cin >> s;
            int ans = -1;
            for (int i = 0; i < s.size(); i++)
            {
                int x = s[i] - 'a';
                int pnt2 = pnt;
                while (pnt2 != 0)
                {
                    if (term[pnt2].size())
                    {
                        auto it = term[pnt2].begin();
                        ans = max(ans, (*it).first);
                    }
                    pnt2 = interest_link[pnt2];
                }
                int old = pnt;
                while (pnt != 0 && go[pnt][x] == 0)
                    pnt = link[pnt];
                go[old][x] = go[pnt][x];
                pnt = go[pnt][x];
                if (term[pnt].size())
                {
                    auto it = term[pnt].begin();
                    ans = max(ans, (*it).first);
                }
            }
            while (pnt != 0)
            {
                pnt = link[pnt];
                if (term[pnt].size())
                {
                    auto it = term[pnt].begin();
                    ans = max(ans, (*it).first);
                }
            }
            cout << ans << "\n";
        }
    }
}