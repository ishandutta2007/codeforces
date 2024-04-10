//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 10;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 1100;

pair<int, int> read()
{
    string s;
    cin >> s;
    pair<int, int> ans = make_pair(0, 0);
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'B')
            ans.first++;
        else
            ans.second++;
    }
    return ans;
}

int dist(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        swap(a, b);
    if (a.second <= b.second)
        return max(abs(a.first - b.first), abs(a.second - b.second));
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int n;
pair<int, int> a[M];

int mn = BIG;
int mx = -BIG;
int mnx = BIG;
int mny = BIG;
int mxx = -BIG;
int mxy = -BIG;

int myfunc(int cx, int cy)
{
    int ans = 0;
    ans = max(ans, abs(cx - mnx));
    ans = max(ans, abs(cx - mxx));
    ans = max(ans, abs(cy - mny));
    ans = max(ans, abs(cy - mxy));
    ans = max(ans, abs((cy - cx) - mn));
    ans = max(ans, abs((cy - cx) - mx));
    return ans;
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i] = read();
#ifdef ONPC
    for (int i = 0; i < n; i++)
        cerr << a[i].first << " " << a[i].second << "\n";
#endif
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, a[i].second - a[i].first);
        mx = max(mx, a[i].second - a[i].first);
        mnx = min(mnx, a[i].first);
        mny = min(mny, a[i].second);
        mxx = max(mxx, a[i].first);
        mxy = max(mxy, a[i].second);
    }
    int l = -1;
    int r = T;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        int cmxx = mnx + h;
        int cmnx = mxx - h;
        int cmxy = mny + h;
        int cmny = mxy - h;
        if (cmxx < cmnx)
        {
            l = h;
            continue;
        }
        if (cmxy < cmny)
        {
            l = h;
            continue;
        }
        int cl = mx - h;
        int cr = mn + h;
        if (cl > cr)
        {
            l = h;
            continue;
        }
        int pl = cmny - cmxx;
        int pr = cmxy - cmnx;
        if (cr < pl || pr < cl)
        {
            l = h;
            continue;
        }
        r = h;
    }
    int ans = r;
    int cx;
    int cy;
    int cmxx = mnx + r;
    int cmnx = mxx - r;
    int cmxy = mny + r;
    int cmny = mxy - r;
    int cl = mx - r;
    int cr = mn + r;
    int pl = cmny - cmxx;
    int pr = cmxy - cmnx;
    int now = min(cr, pr);
    if (now >= cmxy - cmxx)
    {
        cy = cmxy;
        cx = cy - now;
    }
    else
    {
        cx = cmxx;
        cy = cx + now;
    }
#ifdef ONPC
    int corr = 0;
    for (int i = 0; i < n; i++)
        corr = max(corr, dist(a[i], make_pair(cx, cy)));
    cout << "real: " << corr << "\n";
#endif
    cout << ans << "\n";
    for (int i = 0; i < cx; i++)
        cout << "B";
    for (int j = 0; j < cy; j++)
        cout << "N";
    cout << "\n";
    return 0;
}