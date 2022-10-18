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
    int idx = 0;
    int x = *min_element(v.begin(), v.end());
    idx = x % n;
    for (int i = 0; i < n; i++) {
        v[i] -= x;
    }
    
    for (int i = 0; i < n; i++) {
        if (v[(idx + i) % n] <= i) {
            cout << (idx + i) % n + 1 << '\n';
            return 0;
        }
    }
}