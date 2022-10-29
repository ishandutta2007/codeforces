#include <bits/stdc++.h>
using namespace std;
int a[300000], b[300000];
int cnt[300000];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        cnt[(b[i] - a[i] + n) % n]++;
    }
    int mmax = 0;
    for (int i = 0; i < n; i++) {
        mmax = max(mmax, cnt[i]);
    }
    cout << mmax;
}