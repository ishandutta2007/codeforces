#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, s;
    cin >> n >> k >> s;

    long long full = s / (n - 1);
    int partial = s - full * (n - 1);
    if (full + (partial > 0) >  k || k > s) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<int> res;
    int last = 1;
    while (s > 0) {
        // s - dist >= k - 1
        // dist <= s - k + 1
        int dist = min(s - k + 1, n - 1);
        if (last == 1) {
            last += dist;
        } else {
            last -= dist;
        }
        res.push_back(last);
        s -= dist;
        k--;
    }

    cout << "YES" << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}