#include <bits/stdc++.h>
using namespace std;
const long INF = 21;
int main() {
    long long n, k, t, q, x;
    vector<long long> a;
    map<long,long> m;
    set<long long> s;
    cin >> n >> k;
    for (long i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
        for (long j = 0; j <= k; ++j) {
            s.insert(j * t);
            if (m.count(j * t) == 0)
                m[j * t] = j;
            else
                m[j * t] = min(m[j * t], j);
        };
    };
    cin >> q;
    for (long i = 0; i < q; ++i) {
        cin >> x;
        long rez = INF;
        for (long j = 0; j < n; ++j)
            for (long l = 0; l <= k; ++l)
                if (s.count(x - l * a[j]) > 0)
                    if (m[x - l * a[j]] + l <= k)
                        rez = min(rez, m[x - l * a[j]] + l);
        if (rez == INF) cout << "-1\n";
        else cout << rez << "\n";
    };
};