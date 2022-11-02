#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

vector<ii> v;

const int maxn = 1010;

bool open[maxn];

int n, m, k;

vi keys[2][maxn];

int a1[maxn], a2[maxn];

int get1(int x)
{
    if (a1[x] == x) return x;
    return a1[x] = get1(a1[x]);
}

int get2(int x)
{
    if (a2[x] == x) return x;
    return a2[x] = get2(a2[x]);
}

int uni1(int x, int y)
{
    x = get1(x), y = get1(y);
    if (rand() % 2) swap(x, y);
    return a1[x] = y;
}

int uni2(int x, int y)
{
    x = get2(x), y = get2(y);
    if (rand() % 2) swap(x, y);
    return a2[x] = y;
}

map<int, int> keySet;

int main()
{
    cin >> n >> m >> k;
    map<string, vi> M;
    map<int, vi> kM;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        v.pb(ii(x, y));
    }
    for (int it = 0; it < 2; ++it)
    {
        for (int i = 0; i < k; ++i)
        {
            string s;
            int room;
            cin >> s >> room;
            --room;
            M[s].pb(room);
            int knum;
            cin >> knum;
            for (int j = 0; j < knum; ++j)
            {
                int x;
                cin >> x;
                --x;
                keys[it][room].pb(x);
                kM[x].pb(room);
            }
        }
    }
    bool ok = true;
    for (int it = 0; it < 2; ++it)
    {
        for (int i = 0; i < maxn; ++i)
            a1[i] = a2[i] = i;
        keySet.clear();
        for (int i = 0; i < n; ++i)
        {
            int ind = -1;
            for (int j = 0; j < sz(keys[it][i]); ++j)
            {
                if (ind != -1) uni2(ind, keys[it][i][j]);
                ind = get2(keys[it][i][j]);
            }
            keySet[get1(i)] = ind;
        }
        memset(open, 0, sizeof(open));
        while (1)
        {
            bool ch = false;
            for (int i = 0; i < m; ++i)
            {
                if (open[i]) continue;
                if (get1(v[i].first) == get1(v[i].second)) continue;
                int s1 = keySet[get1(v[i].first)];
                int s2 = keySet[get1(v[i].second)];
                if (get2(i) == s1 || get2(i) == s2)
                {
                    ch = true;
                    open[i] = true;
                    int root = uni1(v[i].first, v[i].second);
                    int kr;
                    if (s1 == -1) kr = s2; else if (s2 == -1) kr = s1; else kr = uni2(s1, s2);
                    keySet[root] = kr;
                }
            }
            if (!ch) break;
        }
        for (int i = 0; i < m; ++i)
            if (get1(kM[i][0]) != get1(kM[i][1]))
            {
                ok = false;
                break;
            }
        for (map<string, vi>::iterator it = M.begin(); it != M.end(); ++it)
        {
            if (get1(it->second[0]) != get1(it->second[1]))
            {
                ok = false;
                break;
            }
        }
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}