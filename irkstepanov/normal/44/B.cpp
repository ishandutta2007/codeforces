#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    n *= 2;

    int ans = 0;
    for (int i = 0; i <= b; ++i) {
        for (int j = 0; j <= c; ++j) {
            if (2 * i + 4 * j <= n && n - 2 * i - 4 * j <= a) {
                ++ans;
            }
        }
    }

    cout << ans << "\n";

}