#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    ll n, m;
    cin >> n >> m;

    ll ans = 1, x = 3;
    while (n) {
        if (n & 1) ans = (ans * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    ans = (ans + m - 1) % m;

    cout << ans << endl;

    return 0;
}