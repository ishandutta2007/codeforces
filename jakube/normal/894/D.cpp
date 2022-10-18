#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> v[i];
    }
    
    vector<vector<int>> x(n);
    vector<vector<long long>> psum(n, {0});
    if (n > 1) {
    for (int i = (n-2)/2; i >= 0; i--) {
        if (2*i + 1 == n-1) {
            x[i] = {v[2*i]};
            psum[i] = {0, v[2*i]};
        } else {
            vector<int> a = x[2*i+1], b = x[2*i+2];
            a.insert(a.begin(), 0);
            b.insert(b.begin(), 0);
            for (auto& val : a)
                val += v[2*i];
            for (auto& val : b)
                val += v[2*i+1];
            merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(x[i]));
            psum[i].assign(x[i].size() + 1, 0);
            for (int j = 0; j < (int)x[i].size(); j++) {
                psum[i][j+1] = psum[i][j] + x[i][j];
            }
        }
    }
    }

    auto compute = [&x, &psum, n](int i, int H) {
        if (i >= n)
            return 0LL;
        auto idx = lower_bound(x[i].begin(), x[i].end(), H) - x[i].begin();
        return (long long)idx * H - psum[i][idx];
    };

    for (int q = 0; q < m; q++){
        int i, H;
        cin >> i >> H;
        i--;
        long long res = H + compute(i, H);
        while (i) {
            int p = (i - 1) / 2;
            int L = H - v[2*p] - v[2*p+1];
            int o = i ^ (p*2+1) ^ (p*2+2);
            res += compute(o, L);
            if (o < n && L > 0)
                res += L;
            H -= v[i-1];
            i = p;
            if (H > 0)
                res += H;
        }

        cout << res << '\n';
    }
}