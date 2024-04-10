#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);

    int n;
    ll M;
    cin >> n >> M;

    vector<ll> dp_prev_l(n + 1, 0);
    vector<vector<ll>> dp_next_0(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> dp_next_f(n + 1, vector<ll>(n + 1, 0));


    dp_prev_l[1] = 1;
    dp_next_0[2][0] = 1;
    dp_next_0[2][1] = 0;
    dp_next_f[2][0] = 1;
    dp_next_f[2][1] = 2;

    for (int i = 3; i <= n; i++) {
        vector<vector<ll>> dp_0(n + 1, vector<ll>(n + 1, 0));
        vector<vector<ll>> dp_1(n + 1, vector<ll>(n + 1, 0));

        for (int l = 1; l <= i; l++) {
            for (int pos = 0; pos < l; pos++) {
                dp_0[l][pos] = (dp_0[l][pos] + dp_prev_l[l - 1]) % M;
            }
        }

        for (int l = 1; l <= i; l++) {
            for (int pos = 0; pos < l; pos++) {
                dp_0[l][pos] = (dp_0[l][pos] + dp_next_0[l - 1][pos]) % M;
            }
        }

        for (int l = 1; l <= i; l++) {
            for (int pos = 1; pos < l; pos++) {
                dp_1[l][pos] = (dp_1[l][pos] + dp_next_f[l - 1][pos - 1]) % M;
            }
        }

        for (int l = 1; l < i; l++) {
            dp_prev_l[l] = dp_next_f[l][l - 1];
        }

        for (int l = 1; l <= i; l++) {
            for (int pos = l - 1; pos >= 0; pos--) {
                dp_next_0[l][pos] = (dp_next_0[l][pos + 1] + dp_0[l][pos]) % M;
            }
        }

        for (int l = 1; l <= i; l++) {
            dp_next_f[l][0] = (dp_0[l][0] + dp_1[l][0]) % M;
            for (int pos = 1; pos < l; pos++) {
                dp_next_f[l][pos] = (dp_next_f[l][pos - 1] + dp_0[l][pos] + dp_1[l][pos]) % M;
            }
        }
    }

    ll res = 0;
    for (int l = 1; l <= n; l++) {
        res = (res + dp_next_f[l][l - 1]) % M;
    }
    cout << res << "\n";
}