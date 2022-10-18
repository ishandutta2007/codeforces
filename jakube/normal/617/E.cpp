#include <bits/stdc++.h>
using namespace std;

struct S {
    int l, r, idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> psum(n + 1);
    psum[0] = 0;
    for (int i = 0; i < n; i++) {
        psum[i+1] = psum[i] ^ v[i];
    }
    
    int size = sqrt(n) + 1;
    vector<vector<S>> queries(size);
    for (int i = 0; i < m; i++) {
        S q;
        cin >> q.l >> q.r;
        q.l--;
        q.idx = i;
        queries[q.l / size].push_back(q);
    }

    vector<long long> result(m, 0);
    for (auto block : queries) {
        sort(block.begin(), block.end(), [](auto a, auto b){ return a.r < b.r; });

        vector<int> cnt(1<<20, 0);
        cnt[0] = 1;
        int curl = 0;
        int curr = 0;
        long long res = 0;
        for (S q : block) {
            while (curl > q.l) {
                int val = psum[curl - 1];
                res += cnt[val ^ k];
                cnt[val]++;
                curl--;
            }

            while (curr < q.r) {
                int val = psum[curr + 1];
                res += cnt[val ^ k];
                cnt[val]++;
                curr++;
            }

            while (curl < q.l) {
                int val = psum[curl];
                cnt[val]--;
                res -= cnt[val ^ k];
                curl++;
            }

            result[q.idx] = res;
        }
    }

    for (long long r : result)
        cout << r << '\n';
}