#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 2000;

int d[maxn];

void out(int x, int l)
{
    for (int i = l - 1; i >= 0; --i)
    {
        if (i >= 25) printf("0");
        else 
            printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

int main()
{
    int n;
    cin >> n;
    vector<ii> v;
    vi len(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v.pb(ii(x, i));
        len[i] = x;
    }
    sort(all(v));
    memset(d, 0, sizeof(d));
    vi res(n);
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        int t = v[i].first;
        if (t <= 25 && d[t] >= (1 << t))
        {
            printf("NO\n");
            return 0;
        }
        res[v[i].second] = d[t];
        int cur = d[t];
        while (1)
        {
            d[t] = max(d[t], cur + 1);
            if (t == 0) break;
            --t;
            cur /= 2;
        }
    }
    printf("YES\n");
    for (int i = 0; i < sz(res); ++i)
    {
        out(res[i], len[i]);
    }
    return 0;
}