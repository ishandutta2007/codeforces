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
#include <ctime>

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

vi p[7][100 * 1000];

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int a[10];

int l;

int dfs(int x) {
    if (x >= l) 
        return 1;

    int s = a[x], h = l - x;
    int res = 0;
    if (x == l - 1) res += sz(p[h][s]); else {
        for (int i = 0; i < sz(p[h][s]); ++i) {
            int y = p[h][s][i];
            int t = l - 1;
            while (t >= x) {
                a[t] = a[t] * 10 + y % 10;
                y /= 10;
                --t;
            }

            res += dfs(x + 1);

            for (int j = x; j < l; ++j) a[j] /= 10;
        }
    }

    return res;
}

int main()
{
    for (int i = 2; i < 100 * 1000; ++i) if (isPrime(i)) {
        int x = i;
        int l = 0;
        while (x) {
            p[l][x].pb(i);
            x /= 10;
            ++l;
        }
        for (int j = l; j < 7; ++j)
            p[j][0].pb(i);
    }

    int nc;
    cin >> nc;
    for (int it = 0; it < nc; ++it) {
        memset(a, 0, sizeof(a));
        int x;
        cin >> x;
        l = 0;
        vi v;
        while (x)
            ++l, v.pb(x % 10), x /= 10;

        for (int i = 1; i < l; ++i)
            a[i - 1] = v[sz(v) - i - 1];

        --l;

        time_t st = clock();

        cout << dfs(0) << "\n";

        time_t t = clock() - st;

        if (t > CLOCKS_PER_SEC * 0.1) cerr << "AAA\n";
    }
    return 0;
}