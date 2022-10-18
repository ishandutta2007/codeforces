#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int h = std::numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        int wi, hi;
        cin >> wi >> hi;
        if (max(wi, hi) <= h)
            h = max(wi, hi);
        else if (min(wi, hi) <= h)
            h = min(wi, hi);
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}