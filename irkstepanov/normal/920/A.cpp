#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> pos(k);
        for (int i = 0; i < k; ++i) {
            cin >> pos[i];
            --pos[i];
        }
        vector<bool> used(n, false);
        int ans = 0;
        while (true) {
            bool all = true;
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    all = false;
                    break;
                }
            }
            if (all) {
                break;
            }
            for (int i = 0; i < k; ++i) {
                if (pos[i] - ans >= 0) {
                    used[pos[i] - ans] = true;
                }
                if (pos[i] + ans < n) {
                    used[pos[i] + ans] = true;
                }
            }
            ++ans;
        }
        cout << ans << "\n";
    }

}