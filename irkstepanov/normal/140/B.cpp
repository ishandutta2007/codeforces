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

    int n;
    cin >> n;

    vector<vector<int> > pos(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int z;
            cin >> z;
            --z;
            pos[i][z] = j;
        }
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int z;
        cin >> z;
        --z;
        a[z] = i;
    }

    vector<int> best(n, -1);
    vector<int> res(n);

    for (int i = 0; i < n; ++i) {
        for (int to = 0; to < n; ++to) {
            int opt = -1;
            for (int u = 0; u <= i; ++u) {
                if (u == to) {
                    continue;
                }
                if (opt == -1 || a[u] < a[opt]) {
                    opt = u;
                }
            }
            if (opt == -1) {
                continue;
            }
            if (best[to] == -1 || best[to] > pos[to][opt]) {
                best[to] = pos[to][opt];
                res[to] = i;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " ";
    }
    cout << "\n";

}