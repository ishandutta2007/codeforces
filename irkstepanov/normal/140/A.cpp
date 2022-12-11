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

const ld pi = 4 * atan(1.0);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, R, r;
    cin >> n >> R >> r;

    if (n == 1) {
        cout << (R >= r ? "YES\n" : "NO\n");
        return 0;
    }

    if (R < 2 * r) {
        cout << "NO\n";
        return 0;
    }

    if (R == 2 * r) {
        cout << (n == 2 ? "YES\n" : "NO\n");
        return 0;
    }

    ld alpha = asin(ld(r) / (R - r));

    if (alpha * n - 0.0000001 <= pi) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}