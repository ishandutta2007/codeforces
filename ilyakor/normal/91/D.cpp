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


int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        --v[i];
    }
    vector<ii> per;
    vector<vector<ii> > p[4];
    for (int i = 0; i < sz(v); ++i) {
        if (v[i] == -1) continue;
        vi c;
        int cur = i;
        while (v[cur] != -1) {
            c.pb(cur);
            int nex = v[cur];
            v[cur] = -1;
            cur = nex;
        }
        if (sz(c) <= 1) continue;
        vector<ii> vc;
        for (int j = 0; j < sz(c); ++j) {
            int k = (j + 1) % sz(c);
            vc.pb(ii(c[j], c[k]));
        }
        p[sz(vc) % 4].pb(vc);
    }
    while (sz(p[1])) {
        vector<ii> w = p[1][sz(p[1]) - 1];
        for (int i = 0; i < sz(w); ++i)
            per.pb(w[i]);
        p[1].pop_back();
    }
    while (sz(p[0])) {
        vector<ii> w = p[0][sz(p[0]) - 1];
        for (int i = 0; i < sz(w); ++i)
            per.pb(w[i]);
        p[0].pop_back();
    }
    while (sz(p[2]) && sz(p[3])) {
        vector<ii> w = p[2][sz(p[2]) - 1];
        for (int i = 0; i < sz(w); ++i)
            per.pb(w[i]);
        p[2].pop_back();
        w = p[3][sz(p[3]) - 1];
        for (int i = 0; i < sz(w); ++i)
            per.pb(w[i]);
        p[3].pop_back();
    }
    while (sz(p[2])) {
        vector<ii> w = p[2][sz(p[2]) - 1];
        for (int i = 0; i < sz(w); ++i)
            per.pb(w[i]);
        p[2].pop_back();
    }
    while (sz(p[3])) {
        vector<ii> w = p[3][sz(p[3]) - 1];
        for (int i = 0; i < sz(w); ++i)
            per.pb(w[i]);
        p[3].pop_back();
    }
    vector<vector<ii> > res;
    for (int i = 0; i < sz(per); i += 4) {
        vector<ii> cur;
        set<int> s;
        for (int j = 0; j < 5 && i + j < sz(per); ++j) {
            cur.pb(per[i + j]);
            s.insert(per[i + j].first);
        }
        for (int j = 0; j < 5 && i + j < sz(per); ++j) {
            if (s.count(per[i + j].second))
                s.erase(per[i + j].second);
        }
        if (!sz(s)) {
            res.pb(cur);
            ++i;
            continue;
        }
        int x = *s.begin();
        cur[sz(cur) - 1].second = x;
        res.pb(cur);
        per[i + 4].first = x;
    }
    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); ++i) {
        printf("%d\n", sz(res[i]));
        for (int j = 0; j < sz(res[i]); ++j)
            printf("%d ", res[i][j].first + 1);
        printf("\n");
        for (int j = 0; j < sz(res[i]); ++j)
            printf("%d ", res[i][j].second + 1);
        printf("\n");
    }
    return 0;
}