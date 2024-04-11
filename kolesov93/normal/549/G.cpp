#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
const int N = 300333;
ll res[N], b[N];

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<ll , ll>> a;
    for (int i = 0; i < n; ++i) {
        int cost;
        scanf("%d", &cost);
        a.emplace_back(cost + i, i);
        b[i] = cost;
    }
    sort(begin(a), end(a));
    for (size_t i = 0; i < a.size(); ++i) {
        res[i] = b[a[i].second] + a[i].second - i;
        if (res[i] < 0) {
            puts(":(");
            return 0;
        }
    }
    for (int i = 0; i + 1 < n; ++i)
        if (res[i] > res[i + 1]) {
            puts(":(");
            return 0;
        }

    for (int i = 0; i < n; ++i) printf("%d ", int(res[i]));
    puts("");

    return 0;
}