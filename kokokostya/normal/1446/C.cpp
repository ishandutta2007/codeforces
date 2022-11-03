#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

int solve(vector<int> a, int j) {
    if (j == -1) {
        return 1;
    }
    vector<int> b, c;
    for (int x: a) {
        if (x & (1 << j)) b.push_back(x);
        else c.push_back(x);
    }

    if (b.empty()) return solve(c, j - 1);
    if (c.empty()) return solve(b, j - 1);

    return max(solve(b, j - 1), solve(c, j - 1)) + 1;
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << n - solve(a, 30) << '\n';

    return 0;
}