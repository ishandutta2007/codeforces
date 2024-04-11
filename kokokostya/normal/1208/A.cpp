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

typedef long long ll;

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int test;
    cin >> test;
    while (test--) {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> ans = {a, b, a ^ b};
        cout << ans[n % 3] << '\n';
    }


    return 0;
}