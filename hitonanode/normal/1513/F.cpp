#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    long long sum = 0;
    vector<pair<int, int>> gr, sm;
    REP(i, N) {
        sum += abs(A[i] - B[i]);
        if (A[i] < B[i]) gr.emplace_back(A[i], B[i]);
        if (A[i] > B[i]) sm.emplace_back(B[i], A[i]);
    }
    sort(gr.begin(), gr.end());
    sort(sm.begin(), sm.end());

    int tmp = 0;
    REP(_, 2) {

            map<int, vector<pair<int, int>>> mp;
            constexpr int ADD = 1;
            constexpr int RM = 2;
            constexpr int QUERY = 3;
            for (auto [l, r] : gr) mp[l].emplace_back(ADD, l);
            for (auto [l, r] : sm) mp[r].emplace_back(QUERY, l);
            for (auto [l, r] : gr) mp[r].emplace_back(RM, l);

            multiset<int> ms;
            for (const auto& [x, qs] : mp) {
                for (auto [q, v] : qs) {
                    if (q == ADD) ms.insert(v);
                    if (q == RM) ms.erase(ms.lower_bound(v));
                    if (q == QUERY and ms.size()) {
                        int lo = max(v, *ms.begin());
                        tmp = max(tmp, x - lo);
                    }
                }
            }
        swap(gr, sm);
    }
    cout << sum - tmp * 2 << '\n';
}