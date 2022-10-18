#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<double> p(n);
    for (int idx = 0; idx < n; idx++)
        cin >> p[idx];
    
    sort(p.begin(), p.end());

    pair<double, double> cur{1.0, 0.0};
    for (int i = n-1; i >= 0; i--) {
        pair<double, double> a{cur.first*(1-p[i]), cur.first * p[i] + cur.second * (1 - p[i])};
        if (a.second > cur.second)
            cur = a;
    }

    cout << cur.second << endl;

    return 0;
}