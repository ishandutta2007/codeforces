#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    vector<int> psum1(n+1, 0);
    vector<int> psum2(n+1, 0);
    for (int i = 0; i < n; i++) {
        psum1[i+1] = psum1[i] + a[i];
        psum2[i+1] = psum2[i] + a[i] * t[i];
    }

    int best = psum2[n];
    for (int i = 0; i + k <= n; i++) {
        int cur = psum2[n] + psum1[i+k] - psum1[i] - psum2[i+k] + psum2[i];
        best = max(best, cur);
    }
    cout << best << endl;
}