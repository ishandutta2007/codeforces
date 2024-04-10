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

ii a[10000];
bool ua[10000];

int n;

int L, b, f;

bool crosses(int x1, int y1, int x2, int y2)
{
    return min(y1, y2) > max(x1, x2);
}

bool check(int l, int len)
{
    if (l < 0) return false;
    if (l + len > L) return false;
    int r = l + len;
    l -= b;
    r += f;
    for (int i = 0; i < n; ++i)
        if (ua[i])
        {
            if (crosses(a[i].first, a[i].second, l, r))
                return false;
        }
    return true;
}

int main()
{
    cin >> L >> b >> f;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            vi t;
            t.pb(0);
            t.pb(L);
            for (int j = 0; j < i; ++j)
                if (ua[j])
                    t.pb(a[j].second + b);
            sort(all(t));
            int opt = -1;
            for (int j = 0; j < sz(t); ++j)
                if (check(t[j], y))
                {
                    opt = t[j];
                    break;
                }
            cout << opt << "\n";
            if (opt == -1)
            {
                ua[i] = false;
                continue;
            }
            ua[i] = true;
            a[i] = ii(opt, opt + y);
        }
        else
        {
            ua[i] = false;
            ua[y - 1] = false;
        }
    }
    return 0;
}