#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    
    vector<int> ps(q);
    for (int i = 0; i < q; i++) {
        cin >> ps[i];
    }

    vector<double> p_all(1, 0);
    vector<double> p(n+1, 0);
    p[0] = 1;

    // todo: change 1000
    double dn = (double)n;
    for (int day = 1; p.back() < 0.5; day++) {
        vector<double> q(n+1, 0);
        for (int i = 1; i <= n; i++) {
            q[i] = ((dn - i + 1) * p[i-1] + i * p[i]) / dn;
        }
        p = q;
        p_all.push_back(p.back());
    }

    for (int Q : ps) {
        double prob = (Q - 1e-7) / 2000.0;
        int idx = lower_bound(p_all.begin(), p_all.end(), prob) - p_all.begin();
        cout << idx << endl;
    }

//     for(auto i : p_all)
//         cout << i << ' ';
//     cout << endl;

//     cout << endl;
//     cout << p_all.size() << endl;

    return 0;
}