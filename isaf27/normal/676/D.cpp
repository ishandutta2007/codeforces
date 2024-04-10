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
#include <deque>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int (rand() << 15) | rand()
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-9;
const ld zero = 0;
const ll INF = 1e18;
const int prost = 239;
const ll prost64 = 239;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 1001;
const int km = (1 << 18) - 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string int_to_str(ll n)
{
    if (n == 0)
        return "";
    return int_to_str(n / 10) + (char)('0' + n % 10);
}

ll str_to_int(string s)
{
    ll ans = 0;
    for (char x : s)
        ans = 10LL * ans + (x - '0');
    return ans;
}

vector<ll> prime_divisors(ll n)
{
    ll k = n;
    vector<ll> ans;
    ll ogr = trunc(sqrt(n));
    for (ll i = 2; i <= ogr; i++)
    {
        if (k % i == 0)
        {
            ans.push_back(i);
            while (k % i == 0)
                k /= i;
        }
    }
    if (k - 1)
        ans.push_back(k);
    return ans;
}

bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    ll ogr = trunc(sqrt(n));
    for (int i = 2; i <= ogr; i++)
        if (n % i == 0)
            return false;
    return true;
}

int n, m, xt, yt, xm, ym;
string s[4][MAX_N];
int dist[4][MAX_N][MAX_N];
queue<pair<int, pair<int, int> > > q;
map<char, char> w;
map<char, vector<bool> > r;

void bfs(int xn, int yn)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 4; d++)
                dist[d][i][j] = BIG;
    dist[0][xn][yn] = 0;
    q.push(make_pair(0, make_pair(xn, yn)));
    while (!q.empty())
    {
        pair<int, pair<int, int> > t = q.front();
        q.pop();
        int d = t.first;
        int x = t.second.first;
        int y = t.second.second;
        //cerr << d << " " << x << " " << y << endl;
        vector<bool> go = r[s[d][x][y]];
        int nxt = (d + 1) % 4;
        if (dist[nxt][x][y] > dist[d][x][y] + 1)
        {
            dist[nxt][x][y] = dist[d][x][y] + 1;
            q.push(make_pair(nxt, make_pair(x, y)));
        }
        for (int i = 0; i < 4; i++)
            if (go[i])
            {
                int gx = x + dx[i];
                int gy = y + dy[i];
                if (gx < 0 || gy < 0 || gx >= n || gy >= m)
                    continue;
                if (!r[s[d][gx][gy]][(i + 2) % 4])
                    continue;
                //cerr << "new\n" << endl;
                //cerr << x << " " << y << " " << gx << " " << gy << " " << d << endl;
                if (dist[d][gx][gy] > dist[d][x][y] + 1)
                {
                    dist[d][gx][gy] = dist[d][x][y] + 1;
                    q.push(make_pair(d, make_pair(gx, gy)));
                }
            }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_read;
    w['+'] = '+';
    r['+'] = {1, 1, 1, 1};
    w['-'] = '|';
    r['-'] = {0, 1, 0, 1};
    w['|'] = '-';
    r['|'] = {1, 0, 1, 0};
    w['^'] = '>';
    r['^'] = {1, 0, 0, 0};
    w['>'] = 'v';
    r['>'] = {0, 1, 0, 0};
    w['v'] = '<';
    r['v'] = {0, 0, 1, 0};
    w['<'] = '^';
    r['<'] = {0, 0, 0, 1};
    w['L'] = 'U';
    r['L'] = {1, 1, 1, 0};
    w['R'] = 'D';
    r['R'] = {1, 0, 1, 1};
    w['U'] = 'R';
    r['U'] = {0, 1, 1, 1};
    w['D'] = 'L';
    r['D'] = {1, 1, 0, 1};
    w['*'] = '*';
    r['*'] = {0, 0, 0, 0};
    cin >> n >> m;
    getline(cin, s[0][0]);
    for (int i = 0; i < n; i++)
        getline(cin, s[0][i]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            s[i + 1][j] = s[i][j];
    for (int d = 0; d < 3; d++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                s[d + 1][i][j] = w[s[d][i][j]];
    /*for (int d = 0; d < 4; d++)
    {
        cout << "new\n";
        for (int i = 0; i < n; i++)
            cout << s[d][i] << endl;
        cout << endl;
    }*/
    cin >> xt >> yt >> xm >> ym;
    bfs(xt - 1, yt - 1);
    int ans = BIG;
    for (int i = 0; i < 4; i++)
        ans = min(ans, dist[i][xm - 1][ym - 1]);
    if (ans >= BIG - 1)
        ans = -1;
    cout << ans;
    return 0;
}