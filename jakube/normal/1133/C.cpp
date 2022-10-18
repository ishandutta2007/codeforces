#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());
    
    int j = 0;
    int best = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && v[j] - v[i] <= 5)
            j++;
        best = max(best, j - i);
    }
    cout << best << '\n';
}