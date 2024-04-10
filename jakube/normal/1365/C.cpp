#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x-1] = i;
    }

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[(n + i - pos[x-1])%n]++;
    }

    int ma = 0;
    for (auto [diff, cnt] : m)
        ma = max(ma, cnt);
    cout << ma << '\n';
}