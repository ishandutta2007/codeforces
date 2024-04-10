#include <bits/stdc++.h>
using namespace std;

struct S {
    int idx, l, r;
    long long result;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (t[i] == 2)
            a[i] *= -1;
    }

    vector<long long> psum(n+1);
    psum[0] = 0;
    for (int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + a[i];
    }

    int q;
    cin >> q;
    vector<S> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].l--;
        v[i].idx = i;
    }
    int sq = sqrt(n); 
    sort(v.begin(), v.end(), [sq](auto p, auto q) {
        int p_i = p.l / sq;
        int q_i = q.l / sq;
        if (p_i < q_i)
            return true;
        if (p_i > q_i)
            return false;
        return p.r < q.r;
    });

    vector<long long> psumadd;
    for (auto i : psum)
        psumadd.push_back(i + k);

    vector<long long> psumminus;
    for (auto i : psum)
        psumminus.push_back(i - k);

    set<long long> all;
    all.insert(psum.begin(), psum.end());
    all.insert(psumadd.begin(), psumadd.end());
    all.insert(psumminus.begin(), psumminus.end());
    vector<long long> unique(all.begin(), all.end());
    for (auto& i : psum) 
        i = lower_bound(unique.begin(), unique.end(), i) - unique.begin();
    for (auto& i : psumadd) 
        i = lower_bound(unique.begin(), unique.end(), i) - unique.begin();
    for (auto& i : psumminus) 
        i = lower_bound(unique.begin(), unique.end(), i) - unique.begin();

    long long result = 0;
    vector<int> m(unique.size(), 0);
    int L = 0, R = 0;
    m[psum[0]]++;
    for (auto& query : v) {
        while (R < query.r) {
            R++;
            // sum[R] - sum[???] = k;
            // sum[???] = sum[R] - k;
            result += m[psumminus[R]];
            m[psum[R]]++;
        }

        while (L > query.l) {
            L--;
            // sum[???] - sum[L] = k;
            // sum[???] = sum[L] + k;
            result += m[psumadd[L]];
            m[psum[L]]++;
        }

        while (R > query.r) {
            m[psum[R]]--;
            result -= m[psumminus[R]];
            R--;
        }
        
        while (L < query.l) {
            m[psum[L]]--;
            result -= m[psumadd[L]];
            L++;
        }

        query.result = result;
    }

    sort(v.begin(), v.end(), [](auto p, auto q) {
        return p.idx < q.idx;
    });

    for (auto query : v) {
       cout << query.result << '\n';
    }
}