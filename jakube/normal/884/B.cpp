#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    if (x == sum + n - 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}