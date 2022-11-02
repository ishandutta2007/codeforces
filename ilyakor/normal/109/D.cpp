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

template<class T>
bool isSorted(vector<T> v) {
    for (int i = 1; i < sz(v); ++i)
        if (v[i] < v[i - 1]) return false;
    return true;
}

int main()
{
    vector<int64> v;

    for (int i = 1; i <= 12; ++i) {
        for (int mask = 0; mask < (1 << i); ++mask) {
            int64 x = 0;
            for (int j = 0; j < i; ++j) {
                x *= 10;
                if ((mask >> j) & 1)
                    x += 7;
                else
                    x += 4;
            }
            v.pb(x);
        }
    }
    
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    int n;
    cin >> n;
    vi w(n);
    vector<ii> ww(n);
    int ind = -1;
    vi M(n);
    vi vt;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        vt.pb(x);
        ww[i] = ii(x, i);
        M[i] = i;
        x = binary_search(all(v), (int64)x) ? 1 : 0;
        w[i] = x;
        if (x == 1) ind = i;
    }

    if (ind == -1) {
        if (isSorted(ww))
            printf("0\n");
        else
            printf("-1\n");
        return 0;
    }

    vector<ii> res;

    vector<ii> www = ww;

    sort(all(ww));

    for (int i = 0; i < sz(www); ++i)
        if (binary_search(all(v), (int64)www[i].first)) {
            ind = www[i].second;
            break;
        }

    for (int i = 0; i < sz(ww); ++i) {
        int cur = ww[i].second;
        if (M[cur] == i) continue;
        if (M[ind] != i) res.pb(ii(i, M[ind]));
        int whi = www[i].second;
        swap(www[M[ind]], www[M[whi]]);
        swap(M[ind], M[whi]);

        if (M[ind] != M[cur]) res.pb(ii(M[ind], M[cur]));
        swap(www[M[ind]], www[M[cur]]);
        swap(M[ind], M[cur]);
    }

    cout << sz(res) << "\n";
    for (int i = 0; i < sz(res); ++i) {
        int x = res[i].first;
        int y = res[i].second;
        swap(vt[x], vt[y]);
        if (x > y) swap(x, y);
        printf("%d %d\n", x + 1, y + 1);    
    }

    if (!isSorted(vt)) cerr << "AAA\n";

    return 0;
}