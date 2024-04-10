#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    int N = d[n-1] + 1;
    
    vector<pair<int, int>> v;
    int st = 0;
    while (d.size() >= 2) {
        for (int j = st + 0; j < st + d[0]; j++) {
            for (int k = j + 1; k < N; k++) {
                v.emplace_back(j, k);
            }
        }

        st += d[0];
        N -= d[n-1] - d[n-2];
        for (int j = 1; j < n; j++)
            d[j] -= d[0];
        d.pop_back();
        d.erase(d.begin());
        n -= 2;

    }

    if (!d.empty()) {
        for (int j = st; j <= st + d[0]; j++) {
            for (int k = j + 1; k <= st + d[0]; k++) {
                v.emplace_back(j, k);
            }
        }
    }

    cout << (int)v.size() << '\n';
    for (auto p : v) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}