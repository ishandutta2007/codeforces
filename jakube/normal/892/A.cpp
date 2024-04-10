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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    auto sum = accumulate(a.begin(), a.end(), 0LL);
    reverse(b.begin(), b.end());
    if (b[0] + b[1] >= sum)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}