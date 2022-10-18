#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<int> mm(n);
    int best = 0;
    for (int i = 0; i < n; i++) {
        mm[i] = best = max(best, a[i]-1);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mm[i] == i;
    }
    cout << cnt << '\n';
}