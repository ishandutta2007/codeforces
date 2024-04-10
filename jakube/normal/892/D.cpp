#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto w = v;
    sort(w.begin(), w.end());
    auto x = v;
    for (auto& V : x)
        cout << w[(lower_bound(w.begin(), w.end(), V) - w.begin() + 1) % n] << ' ';
    cout << endl;
}