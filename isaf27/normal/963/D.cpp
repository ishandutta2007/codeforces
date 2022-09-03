//isaf27

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
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
const ld eps = 1e-10;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 9;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

vector<int> z_function(string s)
{
    int n = s.length();
    vector<int> z;
    z.resize(n);
    z[0] = 0;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = min(z[i - l], r - i);
        if (z[i] < 0)
            z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

string s;
int q, k[M];
string t[M];
vector<vector<int> > pos(M), v(M);
int ans[M];

struct Node
{
    Node* a[alf];
    int id;

    Node()
    {
        for (int x = 0; x < alf; x++)
            a[x] = NULL;
        id = -1;
    }
};

Node* root;

void add(string z, int id)
{
    Node *cur = root;
    for (char x : z)
    {
        if (cur->a[x - 'a'] != NULL)
            cur = cur->a[x - 'a'];
        else
        {
            Node *d = new Node();
            cur->a[x - 'a'] = d;
            cur = d;
        }
    }
    cur->id = id;
}

const int MG = 200;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    root = new Node();
    cin >> s >> q;
    for (int i = 0; i < q; i++)
        cin >> k[i] >> t[i];
    for (int i = 0; i < q; i++)
    {
        if (t[i].size() >= MG)
        {
            string w = t[i];
            w += "&";
            w += s;
            vector<int> z = z_function(w);
            for (int x = 0; x < s.size(); x++)
                if (z[x + t[i].size() + 1] >= t[i].size())
                    pos[x].push_back(i);
            continue;
        }
        add(t[i], i);
    }
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        Node *cur = root;
        for (int x = i; x < n; x++)
        {
            if (cur->a[s[x] - 'a'] == NULL) break;
            cur = cur->a[s[x] - 'a'];
            if (cur->id != -1)
                pos[i].push_back(cur->id);
        }
    }
    for (int i = 0; i < q; i++)
        ans[i] = BIG;
    for (int i = 0; i < n; i++)
    {
        for (int x : pos[i])
        {
            v[x].push_back(i);
            if (v[x].size() >= k[x])
                ans[x] = min(ans[x], v[x].back() - v[x][(int)v[x].size() - k[x]]);
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (ans[i] == BIG)
            cout << "-1\n";
        else
            cout << ans[i] + t[i].size() << "\n";
    }
    return 0;
}