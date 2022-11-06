#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    k++;
    string s;
    cin >> s;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') a.push_back(i);
    }

    int res = 2 * n;
    for (int i = 0; i <= a.size() - k; i++) {
        int left = i, right = i + k;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            res = min(res, max(a[mid] - a[i], a[i + k - 1] - a[mid]));
            if (a[mid] - a[i] < a[i + k - 1] - a[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }

    cout << res << endl;
}