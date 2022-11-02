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
    vi d(n + 1, 0);
    vi u(n + 2, 0);
    for (int i = 2; i <= n; ++i) {
        int k = 2;
        while (1) {
            int x = i - (k * (k - 1)) / 2;
            if (x < 0) break;
            if (x % k == 0) {
                x /= k;
                int t = 0;
                for (int j = 0; j < k; ++j)
                    t ^= d[x + j];
                u[t] = i;
            }
            ++k;
        }
        int r = 0;
        while (u[r] == i) ++r;
        d[i] = r;
    }
    if (!d[n]) printf("-1\n");
    else {
        int k = 2;
        while (1) {
            int x = n - (k * (k - 1)) / 2;
            if (x % k == 0) {
                x /= k;
                int t = 0;
                for (int i = 0; i < k; ++i)
                    t ^= d[x + i];
                if (!t) break;
            }
            ++k;
        }
        printf("%d\n", k);
    }
    return 0;
}