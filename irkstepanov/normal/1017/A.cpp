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
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < 4; ++j) {
            int x;
            cin >> x;
            s += x;
        }
        a[i] = {s, i};
    }

    sort(all(a), [&] (pii x, pii y) {
        if (x.first != y.first) {
            return x.first > y.first;
        }
        return x.second < y.second;
    });

    for (int i = 0; i < n; ++i) {
        if (a[i].second == 0) {
            cout << i + 1 << "\n";
        }
    }

}