/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
mt19937 rnd(239);

//constants
const int M = 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 610;

ll ask(vector<int> v)
{
    if ((int)v.size() <= 1) return 0;
    cout << "? " << (int)v.size() << endl;
    for (int i : v)
        cout << i + 1 << " ";
    cout << endl;
    ll ans;
    cin >> ans;
    if (ans == -1) exit(0);
    return ans;
}

void ans_bip(vector<int> v)
{
    cout << "Y " << (int)v.size() << endl;
    for (int i : v)
        cout << i + 1 << " ";
    cout << endl;
    exit(0);
}

void ans_cyc(vector<int> v)
{
    cout << "N " << (int)v.size() << endl;
    for (int i : v)
        cout << i + 1 << " ";
    cout << endl;
    exit(0);
}

int n;
int color[M];
bool used[M];
vector<int> v[M];

void add_edge(int s, int f)
{
    v[s].push_back(f);
    v[f].push_back(s);
}

ll find_kol(int p, vector<int> v)
{
    ll a1 = ask(v);
    v.push_back(p);
    ll a2 = ask(v);
    return (a2 - a1);
}

vector<int> al;

int func(int p, int l, int r)
{
    if (r - l == 1) return al[l];
    int mid = (l + r) >> 1;
    vector<int> v;
    for (int i = l; i < mid; i++) v.push_back(al[i]);
    if (find_kol(p, v) != 0)
        return func(p, l, mid);
    else
        return func(p, mid, r);
}

int fnd_go(int p)
{
    al.clear();
    for (int i = 0; i < n; i++)
        if (!used[i])
            al.push_back(i);
    if (find_kol(p, al) == 0) return -1;
    return func(p, 0, (int)al.size());
}

void dfs(int p, int c)
{
    used[p] = true;
    color[p] = c;
    while (true)
    {
        int to = fnd_go(p);
        if (to == -1) break;
        add_edge(p, to);
        dfs(to, 1 - c);
    }
}

int s, f;
vector<int> st;

void dfs_way(int p)
{
    used[p] = true;
    st.push_back(p);
    if (p == f) ans_cyc(st);
    for (int i : v[p])
        if (!used[i])
            dfs_way(i);
    st.pop_back();
}

int main()
{
    #ifdef ONPC
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    dfs(0, 0);
    vector<int> s1;
    vector<int> s2;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
            s1.push_back(i);
        else
            s2.push_back(i);
    }
    int l1 = ask(s1);
    int l2 = ask(s2);
    if (l1 == 0 && l2 == 0) ans_bip(s1);
    if (l1 == 0)
        s1 = s2;
    for (int p = 0; p < (int)s1.size(); p++)
    {
        s = s1[p];
        al.clear();
        for (int x = p + 1; x < (int)s1.size(); x++)
            al.push_back(s1[x]);
        if (find_kol(s, al) == 0) continue;
        f = func(s, 0, (int)al.size());
        break;
    }
    memset(used, 0, sizeof(used));
    dfs_way(s);
    return 0;
}