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

    int n, m;
    cin >> n >> m;

    vector<int> cnt(n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        for (int i = l; i <= r; ++i) {
            ++cnt[i];
        }
    }

    int f = -1;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] != 1) {
            f = i;
            break;
        }
    }

    if (f == -1) {
        cout << "OK\n";
    } else {
        cout << f + 1 << " " << cnt[f] << "\n";
    }

}