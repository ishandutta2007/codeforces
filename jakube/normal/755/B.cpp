#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<string> w(m);
    for (int idx = 0; idx < n; idx++)
        cin >> w[idx];

    set<string> s2(w.begin(), w.end());

    int together = count_if(v.begin(), v.end(), [&](string s){ return s2.count(s) > 0; });

    pair<int, int> a(n-together, together), b(m-together, together);

    // vector<vector<vector<int>>> grundy(a.first + 1, vector<vector<int>>(b.first + 1, vector<int>(together + 1, 0)));
    // for (int i = 0; i <= a.first; i++) {
    //     for (int j = 0; j <= b.first; j++) {
    //         for (int t = 0; t <= together; t++) {
    //             if (t == 0) {
    //                 if (i == 0 || j == 0) {
    //                     grundy[i][j][t] = 0;
    //                 }
    //                 else {
    //                     gundy[i][j][t] = !grundy[
    //                 }
    //             }
    //         }
    //     }
    // }
    
    int A = a.first + (together + 1) / 2;
    int B = b.first + together / 2;

    if (A > B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}