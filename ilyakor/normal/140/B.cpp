/*
 * Powered by C++Helper v0.001alpha
*/

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

int n;

vi inv(vi v) {
    vi w(sz(v));
    for (int i = 0; i < sz(v); ++i)
        w[v[i]] = i;
    return w;
}

int solve(vi v1, vi v2, int ind) {
    v1 = inv(v1), v2 = inv(v2);
    int res = -1, val = 100500;
    int cur = -1, co = 100500;
    for (int i = 0; i < n; ++i) {
        if (i == ind) continue;
        if (cur == -1 || v2[i] <= v2[cur])
            cur = i, co = v1[cur];
        
        if (res == -1 || co < val)
            val = co, res = i;
        
        //if (ind == 0) cerr << i << " " << cur << " " << co << "\n";
    }
    return res + 1;
}

int main() {
    cin >> n;
    vector<vi> a;
    for (int i = 0; i <= n; ++i) {
        vi v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
            --v[j];
         }
        a.pb(v);
    }
    for (int i = 0; i < n; ++i) {
        cout << solve(a[i], a[n], i) << " ";
    }
    cout << "\n";
    return 0;
}