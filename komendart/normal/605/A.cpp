#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }

    int l = 1;
    int maxl = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] > b[i - 1]) {
            l++;
            maxl = max(maxl, l);
        } else {
            l = 1;
        }
    }
    cout << n - maxl << endl;

}