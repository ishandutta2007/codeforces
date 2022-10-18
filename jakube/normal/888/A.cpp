#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > max(a[i-1], a[i+1]) || a[i] < min(a[i-1], a[i+1]))
            cnt++;
    }
    cout << cnt << endl;
}