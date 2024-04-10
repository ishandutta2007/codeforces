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

const ll MOD = 998244353;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;
    vector<ll> num_divs(n + 1, 2);
    num_divs[1] = 1;
    for (int i = 2; i <= n / 2; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            num_divs[j]++;
        }
    }

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    if (n == 2) {
        cout << "3\n";
        return 0;
    }

    ll curr_sum = 4;
    for (int i = 3; i < n; i++) {
        curr_sum = (2 * curr_sum + num_divs[i]) % MOD;
    }

    cout << (curr_sum + num_divs[n]) % MOD << "\n";
}