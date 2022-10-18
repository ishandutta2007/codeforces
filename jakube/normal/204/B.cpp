#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    map<int, int> front, back, all;

    for (int i = 0; i < n; i++) {
        int f, b;
        cin >> f >> b;
        front[f]++;
        if (f != b)
            back[b]++;
        all[f]++;
        if (f != b)
            all[b]++;
    }

    int m = numeric_limits<int>::max();
    for (auto p : all) {
        if (p.second*2 >= n) {
            m = max(min(m, (n+1)/2 - (front.count(p.first) ? front[p.first] : 0)), 0);
        }
    }

    if (m == numeric_limits<int>::max())
        cout << -1 << endl;
    else
        cout << m << endl;


    return 0;
}