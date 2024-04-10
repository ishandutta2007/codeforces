#include <bits/stdc++.h>
using namespace std;

struct Query {
    long long cnt, idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> s(n);
    for (auto& x : s)
        cin >> x;
    sort(s.begin(), s.end());
    
    int Q;
    cin >> Q;
    vector<Query> queries(Q);
    int idx = 0;
    for (auto& q : queries) {
        long long l, r;
        cin >> l >> r;
        q.cnt = r - l + 1;
        q.idx = idx++;
    }

    // sort(queries.begin(), queries.end(), [](auto p, auto q) {
    //     return p.cnt < q.cnt;
    // });

    vector<long long> diffs;
    for (int i = 0; i < n; i++) {
        long long upper = i == n-1 ? std::numeric_limits<long long>::max() : s[i+1];
        diffs.push_back(upper - s[i]);
    }
    sort(diffs.begin(), diffs.end());
    vector<long long> psum(diffs.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < diffs.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + diffs[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return psum[y+1] - psum[x];
    };
    
    for (auto q : queries) {
        long long cnt = q.cnt;
        int smaller = lower_bound(diffs.begin(), diffs.end(), cnt) - diffs.begin();
        cout << sum(0, smaller-1) + (n - smaller) * cnt << " ";
    }
    cout << endl;
}