#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 1e6 + 10;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int bt = 31;

// Code starts here

vector<int> suffix_array(vector<int> s)
{
    s.push_back(-1);
    int n = s.size();
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(s[i], i));
    sort(v.begin(), v.end());
    vector<pair<int, int> > num;
    int last = 0;
    for (int i = 0; i < n - 1; i++)
    {
        num.push_back(make_pair(last, v[i].second));
        if (v[i].first != v[i + 1].first)
            last++;
    }
    num.push_back(make_pair(last, v.back().second));
    vector<int> u(n);
    for (int i = 0; i < n; i++)
        u[num[i].second] = num[i].first;
    int d = 1;
    vector<pair<pair<int, int>, int> > t;
    vector<vector<pair<int, int> > > h;
    while (d < n)
    {
        t.clear();
        h.clear();
        h.resize(n);
        for (int i = 0; i < n; i++)
        {
            int l = num[i].second - d;
            if (l < 0)
                l += n;
            h[u[l]].push_back(make_pair(num[i].first, l));
        }
        for (int i = 0; i < n; i++)
            for (pair<int, int> r : h[i])
                t.push_back(make_pair(make_pair(i, r.first), r.second));
        last = 0;
        num.clear();
        for (int i = 0; i < n - 1; i++)
        {
            num.push_back(make_pair(last, t[i].second));
            if (t[i].first != t[i + 1].first)
                last++;
        }
        num.push_back(make_pair(last, t.back().second));
        for (int i = 0; i < n; i++)
            u[num[i].second] = num[i].first;
        d <<= 1;
    }
    vector<int> ans;
    for (int i = 1; i < n; i++)
        ans.push_back(num[i].second);
    return ans;
}

vector<int> a;

vector<int> kasai(vector<int> s)
{
    int n = s.size();
    a = suffix_array(s);
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        t[a[i]] = i;
    vector<int> lcp(n - 1);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == n - 1)
            continue;
        while (s[i + k] == s[a[t[i] + 1] + k] && a[t[i] + 1] + k < n && i + k < n)
            k++;
        lcp[t[i]] = k;
        k = max(0, k - 1);
    }
    return lcp;
}

int n, c[MAX_N], sz[MAX_N];
string s;
vector<int> v;
vector<int> cost, b, len, nw;
ll pr[MAX_N];//, mx[MAX_LOG][MAX_N], mn[MAX_LOG][MAX_N], logor[MAX_N];

/* ll getmin(int l, int r)
{
    int u = logor[r - l + 1];
    return min(mn[u][l], mn[u][r - (1 << u) + 1]);
}

ll getmax(int l, int r)
{
    int u = logor[r - l + 1];
    return max(mx[u][l], mx[u][r - (1 << u) + 1]);
} */

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (char x : s)
            v.push_back(x - 'a');
        v.push_back(30 + i);
        sz[i] = s.size();
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < sz[i]; x++)
        {
            cost.push_back(c[i]);
            len.push_back(sz[i] - x);
        }
        cost.push_back(0);
        len.push_back(0);
    }
    vector<int> lcp = kasai(v);
    b.resize(a.size());
    nw.resize(len.size());
    for (int i : a)
        b[i] = cost[a[i]], nw[i] = len[a[i]];
    pr[0] = 0;
    for (int i = 0; i < a.size(); i++)
        pr[i + 1] = pr[i] + b[i];
    /*for (int i = 0; i <= a.size(); i++)
        mn[0][i] = pr[i], mx[0][i] = pr[i];
    for (int i = 1; i < MAX_LOG; i++)
        for (int l = 0; l <= a.size(); l++)
        {
            int r = (l + (1 << (i - 1)));
            if (r > a.size())
            {
                mx[i][l] = mx[i - 1][l];
                mn[i][l] = mn[i - 1][l];
                continue;
            }
            mx[i][l] = max(mx[i - 1][l], mx[i - 1][r]);
            mn[i][l] = min(mn[i - 1][l], mn[i - 1][r]);
        }
    logor[1] = 0;
    for (int i = 2; i <= a.size() + 2; i++)
    {
        logor[i] = logor[i - 1] + 1;
        if ((1 << logor[i]) > i)
            logor[i]--;
    }*/
    vector<int> en(a.size() + 1, 0);
    set<int> gr;
    for (int i = 0; i <= a.size(); i++)
        gr.insert(i), en[i] = i;
    /*for (int i : b)
        cerr << i << " ";
    cerr << "\n";
    for (int i = 0; i < a.size(); i++)
        cerr << a[i] << " ";
    cerr << "\n";
    for (int i : lcp)
        cerr << i << " ";
    cerr << "\n";
    for (int i : v)
        cerr << i << " ";
    cerr << "\n";*/
    vector<pair<int, int> > u;
    for (int i = 0; i < lcp.size(); i++)
        u.push_back(make_pair(lcp[i], i));
    ll ans = 0;
    for (int i = 0; i < b.size(); i++)
    {
        int pos = 0;
        if (i < lcp.size())
            pos = max(pos, lcp[i]);
        if (i > 0)
            pos = max(pos, lcp[i - 1]);
        //cerr << nw[i] << " " << pos << "\n";
        if (nw[i] > pos)
            ans = max(ans, (ll)nw[i] * (ll)b[i]);
    }
    sort(u.rbegin(), u.rend());
    for (pair<int, int> t : u)
    {
        int i = t.second;
        ll len = t.first;
        int l1, r1, l2, r2;
        r1 = i;
        l2 = i + 1;
        r2 = (*gr.upper_bound(i + 1)) - 1;
        l1 = en[i];
        //cerr << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        en[r2] = l1;
        gr.erase(i + 1);
        int mx = 0;
        if (r2 < lcp.size())
            mx = max(mx, lcp[r2]);
        if (l1 > 0)
            mx = max(mx, lcp[l1 - 1]);
        if (mx < len)
            ans = max(ans, len * (pr[r2 + 1] - pr[l1]));
    }
    cout << ans;
    return 0;
}