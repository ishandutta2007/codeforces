#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i : v) {
        while (2*k < i) {
            k *= 2;
            cnt++;
        }
        k = max(k, (long long)i);
    }
    cout << cnt << endl;
}