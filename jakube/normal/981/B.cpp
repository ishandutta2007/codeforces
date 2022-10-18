#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[x] = max(m[x], y);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[x] = max(m[x], y);
    }
    long long sum = 0;
    for (auto p : m) {
      sum += p.second;
    }
    cout << sum << '\n';
    

}