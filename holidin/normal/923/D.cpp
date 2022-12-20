#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
//#include <random>
//#include <chrono>
#include <queue>
//#include <unordered_map>
//#include <unordered_set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <cassert>
#include <cmath>

#define y1 ups
#define left lll
#define right rrr
#define next nnn
//#define find fff

typedef unsigned long long ull;

using namespace std;

//mt19937_64 twister(chrono::steady_clock().now().time_since_epoch().count());
//mt19937_64 twister(8888);
//
//long long rnd(long long l, long long r)
//{
//    uniform_int_distribution<long long> dis(l, r);
//    return dis(twister);
//}

const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 88;
const int inf = 1e9 + 88;
const int logn = 22;
const int maxa = 3e6 + 88;
const int block = 775;
const long long infll = 1e18 + 88;
const char sgl[5] = {'a', 'e', 'i', 'o', 'u'};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int knightx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int knighty[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int kingx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int kingy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const char sep = 'a' - 1;
const double eps = 1e-9;
const int maxn1 = 1e3 + 88;

/**
**/

#define int long long

string s, t;
int cnt_s[maxn][3], cnt_t[maxn][3], p_s[maxn], p_t[maxn];

bool solve()
{
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, c, d, q, i;
    cin >> s >> t;
    n = s.length();
    cnt_s[0][s[0] - 'A']++;
    if (s[0] == 'A')
        p_s[0] = 1;
    for (i = 1; i < n; i++)
    {
        cnt_s[i][0] += cnt_s[i - 1][0];
        cnt_s[i][1] += cnt_s[i - 1][1];
        cnt_s[i][2] += cnt_s[i - 1][2];
        cnt_s[i][s[i] - 'A']++;
        if (s[i] == 'A')
            p_s[i] = p_s[i - 1] + 1;
    }
    cnt_t[0][t[0] - 'A']++;
    if (t[0] == 'A')
        p_t[0] = 1;
    n = t.length();
    for (i = 1; i < n; i++)
    {
        cnt_t[i][0] += cnt_t[i - 1][0];
        cnt_t[i][1] += cnt_t[i - 1][1];
        cnt_t[i][2] += cnt_t[i - 1][2];
        cnt_t[i][t[i] - 'A']++;
        if (t[i] == 'A')
            p_t[i] = p_t[i - 1] + 1;
    }
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int cnta_s = min(p_s[b], b - a + 1);
        int cnta_t = min(p_t[d], d - c + 1);
        int cntb_s = cnt_s[b][1] - (a == 0 ? 0 : cnt_s[a - 1][1]);
        int cntc_s = cnt_s[b][2] - (a == 0 ? 0 : cnt_s[a - 1][2]);
        int cntb_t = cnt_t[d][1] - (c == 0 ? 0 : cnt_t[c - 1][1]);
        int cntc_t = cnt_t[d][2] - (c == 0 ? 0 : cnt_t[c - 1][2]);
        if (cnta_s < cnta_t)
        {
            cout << 0;
            continue;
        }
        if ((cntb_t + cntc_t != 0 && cntb_s + cntc_s == 0) || (cnta_s%3 != cnta_t%3))
        {
            cnta_s--;
            cntb_s++;
            cntc_s++;
        }
        if (cnta_s < cnta_t)
        {
            cout << 0;
            continue;
        }
        if (cntb_s + cntc_s > cntb_t + cntc_t)
        {
            cout << 0;
            continue;
        }
        if ((cntb_s + cntc_s)%2 != (cntb_t + cntc_t)%2)
        {
            cout << 0;
            continue;
        }
        cout << 1;
    }
//    return bans == ans;
}

#undef int

int main()
{
//    srand(time(0));
//    srand(8);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");
//    ifstream cin("output.txt");
//    ifstream fin("12.out");
//    int a, b, i = 0;
//    while (cin >> a)
//    {
//        fin >> b;
//        if (a != b)
//        {
//            cout << i << " " << a << " " << b;
//            return 0;
//        }
//        i++;
//    }
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("f.in", "r", stdin);
//    freopen("f.out", "w", stdout);
//    int t = 10000;
//    while (t--)
//    {
//        if (t == 8077)
//            t = 8077;
//        gen();
//        cout << t << endl;
//        brut();
//        if (!solve())
//        {
//            cout << "kek";
//            return 0;
//        }
//    }
    solve();
    return 0;
}