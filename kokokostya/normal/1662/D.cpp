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

string conv(const string& s) {
    string u;
    for (char c : s) {
        if (c == 'B') continue;
        if (u.empty() || u.back() != c) u += c;
        else u.pop_back();
    }
    return u;
}

bool solve() {
    string s, t;
    cin >> s >> t;
    int cnt_b = 0;
    for (char c : s) {
        if (c == 'B') cnt_b++;
    }
    for (char c : t) {
        if (c == 'B') cnt_b++;
    }
    if (cnt_b % 2 == 1) return 0;
    return conv(s) == conv(t);
}


int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while (test--) cout << (solve() ? "YES" : "NO") << '\n';




    return 0;
}