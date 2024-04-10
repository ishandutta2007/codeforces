#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define data NE_data
#define rank NE_rank
#define endl '\n'

#define int long long


int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    int k = 1;

    for (int i = 0; i < n - 1; i++) {
        k *= 2;
        k %= MOD;
    }
    int kek = 0;
    for (int i = 0; i < m; i++) {
        int l, r, val;
        cin >> l >> r >> val;
        kek |= val;
    }

    cout << (k * kek) % MOD << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}