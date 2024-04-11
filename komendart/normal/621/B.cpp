#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x + y]++;
        b[x - y]++;
    }

    long long result = 0;
    for (auto i: a) {
        long long t = i.second;
        result += t * (t - 1);
    }
    for (auto i: b) {
        long long t = i.second;
        result += t * (t - 1);
    }

    cout << result / 2 << '\n';
}