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

int F = -1;

bool cmp(ii p, ii q) {
    if (p.first != q.first) return p.first > q.first;
    if (q.second == F) return false;
    if (p.second == F) return true;
    return p.second > q.second;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ii> v;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        v.pb(ii(x, i));
    }
    sort(all(v));
    reverse(all(v));
    int s = n;
    for (int i = 0; i < sz(v); ++i) {
        int l = n / 2;
        l = min(l, s);
        v[i].first = min(v[i].first, l);
        s -= v[i].first;
    }
    if (s) {
        printf("-1\n");
        return 0;
    }
    vi res;
    for (int it = 0; it < n; ) {
        sort(all(v), cmp);
        res.pb(v[0].second);
        if (it == 0)
            F = v[0].second;
        --v[0].first;
        ++it;
        if (it == n) break;
        if (sz(v) > 1 && v[1].first > 0) {
            res.pb(v[1].second);
            --v[1].first;
            ++it;
        }
    }
    for (int i = 0; i < sz(res); ++i)
        printf("%d ", res[i] + 1);
    printf("\n");
    return 0;
}