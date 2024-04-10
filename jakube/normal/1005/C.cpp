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
    map<int, int> m;
    for (int x : v)
        m[x]++;

    int cnt = 0;
    for (int x : v) {
        bool b = false;
        for (int i = 0; i <= 30; i++) {
            int y = (1 << i) - x;
            if (m.count(y) && (x != y || m[y] > 1))
                b = true;
        }
        cnt += !b;
    }
    cout << cnt << '\n';
}