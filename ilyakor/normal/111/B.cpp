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

const int maxn = 218 * 1000;

int d[maxn];

int main()
{
    memset(d, -1, sizeof(d));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int res = 0;
        for (int j = 1; j * j <= x; ++j) {
            if (x % j) continue;
            int k = j;
            if (d[k] < i - y)
                ++res;
            d[k] = i;
            if (j != x / j) {
                k = x / j;
                if (d[k] < i - y)
                    ++res;
                d[k] = i;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}