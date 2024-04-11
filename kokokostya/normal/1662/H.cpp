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

void solve() {
    int w, l;
    cin >> w >> l;
    set<int> s;
    for (int a = 1; a * a <= w; a++) {
        if (w % a != 0) continue;
        if ((l - 2) % a == 0) s.insert(a);
        if ((l - 2) % (w / a) == 0) s.insert(w/a);
    }
    swap(w, l);
    for (int a = 1; a * a <= w; a++) {
        if (w % a != 0) continue;
        if ((l - 2) % a == 0) s.insert(a);
        if ((l - 2)% (w / a) == 0) s.insert(w/a);
    }
    for (int a = 1; a * a <= w - 1; a++) {
        if ((w - 1) % a != 0) continue;
        if ((l - 1) % a == 0) s.insert(a);
        if ((l - 1) % ((w - 1) / a) == 0) s.insert((w - 1) / a);
    }
    s.insert(2);
    cout << s.size() << ' ';
    for (int i : s) cout << i << ' ';
    cout << '\n';
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while (test--) solve();


    return 0;
}