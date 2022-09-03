#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> L(N);
    for (auto &x : L) cin >> x;
    sort(L.rbegin(), L.rend());

    int ng = 0, ok = 1.01e9;
    while (ok - ng > 1) {
        const int c = (ok + ng) / 2;
        int cap = 1;
        multiset<pair<int, int>> ms;
        ms.emplace(0, 1);
        for (auto l : L) {
            if (cap >= K or ms.empty()) break;
            auto [h, sz] = *ms.begin();
            ms.erase(ms.begin());
            cap--;
            if (h + 1 <= c and sz > 1) ms.emplace(h + 1, sz - 1);
            int r1 = (l - 1) / 2, r2 = l - 1 - r1;
            h += 2;
            if (c - h + 1 > 0) {
                int s1 = min(r1, c - h + 1), s2 = min(r2, c - h + 1);
                if (ms.size() < N) ms.emplace(h, s1), ms.emplace(h, s2);
                cap += s1 + s2;
            }
        }
        (cap >= K ? ok : ng) = c;
    }
    cout << (ok < 1.01e9 ? ok : -1) << '\n';
}