#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

int64 K[3], T[3];

typedef pair<int64, int64> II;

int64 ct;

bool cmp(II p, II q) {
    int64 t1 = p.second, t2 = q.second;
    int64 s1 = t1 - p.first, s2 = t2 - q.first;
    return max(t1 - s1 + ct, max(t1 + ct, t2) - s2 + ct) < max(t2 - s2 + ct, max(t2 + ct, t1) - s1 + ct);
}

int main() {    
    for (int i = 0; i < 3; ++i) cin >> K[i];
    for (int i = 0; i < 3; ++i) cin >> T[i];
    int n;
    cin >> n;
    vector<II> v[4];
    v[0] = vector<II>(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[0][i].second = x;
        v[0][i].first = 0;
    }
    for (int i = 0; i < 3; ++i) {
        sort(all(v[i]), cmp);
        multiset<int64> s;
        int64 tc = -100;
        int64 k = K[i];
        ct = T[i];
        for (int j = 0; j < sz(v[i]); ) {
            if (k > 0) {
                --k;
                int64 tmp = max(tc, v[i][j].second) + T[i];
                v[i + 1].pb(II(v[i][j].first + tmp - v[i][j].second, tmp));
                s.insert(tmp);
                ++j;
            } else {
                tc = max(tc, *s.begin());
                s.erase(s.begin());
                ++k;
            }
        }
    }
    int64 res = 0;
    for (int i = 0; i < sz(v[3]); ++i)
        res = max(res, v[3][i].first);
    cout << res << "\n";
    return 0;
}