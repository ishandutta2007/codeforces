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

const int maxn = 218;

int main()
{
    int n;
    cin >> n;
    vector<vi> v;
    vi g[maxn];
    for (int i = 0; i < (n * (n - 1)) / 2; ++i) {
        int k;
        cin >> k;
        vi t(k);
        for (int j = 0; j < k; ++j) {
            int x;
            scanf("%d", &x);
            t[j] = x;
            g[x].pb(sz(v));
        }
        sort(all(t));
        v.pb(t);
    }
    vector<vi> res;
    if (n == 2) {
        vi t;
        t.pb(v[0][0]);
        res.pb(t);
        t.clear();
        for (int i = 1; i < sz(v[0]); ++i)
            t.pb(v[0][i]);
        res.pb(t);
    } else {
        for (int i = 0; i < maxn; ++i) {
            if (!sz(g[i])) continue;
            int x = g[i][0];
            int y = g[i][1];
            vi tmp(sz(v[x]));
            tmp.erase(set_intersection(all(v[x]), all(v[y]), tmp.begin()), tmp.end());
            sort(all(tmp));
            res.pb(tmp);
            for (int j = 0; j < sz(tmp); ++j)
                g[tmp[j]].clear();
        }
    }
    //cout << sz(res) << "\n";
    for (int i = 0; i < sz(res); ++i) {
        cout << sz(res[i]) << " ";
        for (int j = 0; j < sz(res[i]); ++j)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}