#include <bits/stdc++.h>
using namespace std;

struct S
{
    int a, t, idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, T;
    cin >> n >> T;
    vector<S> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].t;
        v[i].idx = i + 1;
    }
    sort(v.begin(), v.end(), [](auto p, auto q) {
        return p.t < q.t;
    });

    auto choose = [&v, T](int M) {
        vector<int> x;
        int remaining = T;
        for (auto& e : v) {
            if (e.a >= M && e.t <= remaining) {
                x.push_back(e.idx);
                remaining -= e.t;
            }
        }
        return x;
    };

    int L = 0; // possible
    int R = n + 1; // impossible
    while (L + 1 < R) {
        int M = (L + R) / 2;
        if ((int)choose(M).size() >= M) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << L << endl;
    cout << L << endl;
    auto x = choose(L);
    for (int i = 0; i < L; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}