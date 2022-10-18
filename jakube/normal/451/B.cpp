#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    int left = 0;
    int right = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i-1]) {
            if (right == i-1) {
                right = i;
            }
            else {
                left = i-1;
                right = i;
            }
        }
    }

    // cout << left << " " << right << endl;

    reverse(v.begin() + left, v.begin() + right + 1);
    if (is_sorted(v.begin(), v.end())) {
        cout << "yes" << endl;
        cout << left + 1 << " " << right + 1 << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}