#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    //vector<int> mn(n, 0);
    int mn = 0;
    ll ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x + mn <= k) {
            if (mn) {
                ans += bool(x + mn);
                mn = 0;
            } else
                mn = x;
        } else {
            ans += 1;
            x -= k - mn;
            mn = x % k;
            ans += x / k;
        }
    }

    cout << ans + bool(mn);

    return 0;
}