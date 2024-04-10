#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int t, l, r;
    int i;
    pair<int, int> idx = {0, 0};
    bool operator<(Query o) {
        if (idx == o.idx)
            return r < o.r;
        return idx < o.idx;
    }
    int result = -1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    set<int> compressed;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        compressed.insert(v[i]);
    }
    
    vector<pair<int, int>> changes;
    vector<Query> queries;
    int T = 0;
    for (int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            queries.push_back({T, l-1, r-1, i});
        } else {
            T++;
            changes.push_back({l-1, r});
            compressed.insert(r);
        }
    }
    vector<int> sorted(compressed.begin(), compressed.end());
    int P = pow(n, 0.66);
    for (auto& x : v)
        x = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    for (auto& p : changes) {
        p.second = lower_bound(sorted.begin(), sorted.end(), p.second) - sorted.begin();
    }
    for (auto& p : queries)
        p.idx = {p.t / P, p.l / P};
    sort(queries.begin(), queries.end());

    
    vector<int> many(n + 1, 0);
    vector<int> cnt(sorted.size(), 0);
    vector<int> old;
    auto add = [&](int x) {
        many[cnt[x]]--;
        cnt[x]++;
        many[cnt[x]]++;
    };
    auto sub = [&](int x) {
        many[cnt[x]]--;
        cnt[x]--;
        many[cnt[x]]++;
    };

    int L = 0;
    int R = -1;
    int tt = 0;
    for (auto& Q : queries) {
        while (R < Q.r) {
            R++;
            add(v[R]);
        }
        while (L > Q.l) {
            L--;
            add(v[L]);
        }
        while (R > Q.r) {
            sub(v[R]);
            R--;
        }
        while (L < Q.l) {
            sub(v[L]);
            L++;
        }

        while (tt < Q.t) {
            auto c = changes[tt];
            int o = v[c.first];
            int ne = c.second;
            v[c.first] = ne;
            old.push_back(o);
            if (c.first >= Q.l && c.first <= Q.r) {
                sub(o);
                add(ne);
            }
            tt++;
        }
        while (tt > Q.t) {
            tt--;
            auto c = changes[tt];
            int o = v[c.first];
            int ne = old.back();
            old.pop_back();
            v[c.first] = ne;
            if (c.first >= Q.l && c.first <= Q.r) {
                sub(o);
                add(ne);
            }
        }

        // answer
        int mex = 1;
        while (many[mex])
            mex++;
        Q.result = mex;
    }

    sort(queries.begin(), queries.end(), [](auto x, auto y){ return x.i < y.i;});
    for (auto Q : queries) {
        cout << Q.result << endl;
    }
    
}