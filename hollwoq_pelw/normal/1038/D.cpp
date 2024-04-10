#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    if (n == 1) return cout << a[0], 0;
    long long t = -a[0];
    for (int i = 1; i < n-1; i++){
        t += abs(a[i]);
    }
    t += a[n-1];
    cout << t;
    return 0;
}