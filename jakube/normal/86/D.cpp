#include <bits/stdc++.h>
using namespace std;

struct Query {
    int idx, l, r;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int size = sqrt(n);
    vector<Query> queries(t);
    for (int i = 0; i < t; i++) {
        queries[i].idx = i;
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
    }

    sort(queries.begin(), queries.end(), [size](const auto& a, const auto& b){
        return (a.l / size < b.l / size) || (a.l / size == b.l / size && a.r < b.r);
    });

    int curL = 0;
    int curR = 0;
    vector<int> counts(1e6 + 1, 0);
    long long currentSum = 0;

    auto add = [&currentSum, &counts](int val) {
        currentSum -= (long long)counts[val] * counts[val] * val;
        counts[val]++;
        currentSum += (long long)counts[val] * counts[val] * val;
    };

    auto remove = [&currentSum, &counts](int val) {
        currentSum -= (long long)counts[val] * counts[val] * val;
        counts[val]--;
        currentSum += (long long)counts[val] * counts[val] * val;
    };

    vector<long long> result(t);
    for (auto q : queries) {
        while (curR < q.r) {
            add(v[curR++]);
        }
        while (curR > q.r) {
            remove(v[--curR]);
        }
        while (curL < q.l) {
            remove(v[curL++]);
        }
        while (curL > q.l) {
            add(v[--curL]);
        }

        result[q.idx] = currentSum;
    }

    for (auto res : result) {
        cout << res << '\n';
    }

    return 0;
}