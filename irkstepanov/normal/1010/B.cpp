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
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    vector<bool> t(n);
    for (int i = 0; i < n; ++i) {
        cout << "1\n";
        cout.flush();
        int x;
        cin >> x;
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            t[i] = true;
        } else {
            t[i] = false;
        }
    }

    int lf = 1, rg = m;

    int i = 0;
    while (true) {
        int md = (lf + rg) >> 1;
        cout << md << "\n";
        cout.flush();
        int x;
        cin >> x;
        if (x == 0) {
            return 0;
        }
        if (!t[i % n]) {
            x *= (-1);
        }
        if (x == 1) {
            lf = md + 1;
        } else {
            rg = md - 1;
        }
        ++i;
    }

}