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
    int64 k;
    cin >> n >> k;
    vector<int64> v;
    vector<ii> w;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v.pb(x);
        w.pb(ii(x, i));
    }
    sort(all(w));
    int64 dec = 0;
    for (int i = 0; i < sz(w); ++i) {
        int64 cur = w[i].first - dec;
        if (cur <= 0) {
            v[w[i].second] = -1;
            continue;
        }
        cur *= (int64)(sz(w) - i);
        if (cur > k) {
            int64 tmp = k / (int64)(sz(w) - i);
            dec += tmp;
            k -= tmp * (int64)(sz(w) - i);
            break;
        }
        dec = w[i].first;
        k -= cur;
        v[w[i].second] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] <= 0) continue;
        v[i] -= dec;
    }
    int t = 0;
    while (t < n && k > 0) {
        if (v[t] > 0) {
            --v[t];
            --k;
        }
        ++t;
    }
    if (k > 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; ++i)
        if (v[i] <= 0) v[i] = -1;
    for (int i = 0; i < n; ++i)
        if (v[(t + i) % n] != -1)
            printf("%d ", (t + i) % n + 1);
    printf("\n");

    return 0;
}