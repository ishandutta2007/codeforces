#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int pad = -1, padc = 0, y;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    a[n+1] = a[1];

    for (int i=1; i<=n; i++) {
        if (a[i] > a[i+1]) {
            padc++;
            pad = i;
        }
    }

    if (padc == 0) {
        y = 0;
    } else if (padc == 1) {
        y = n - pad;
    } else {
        y = -1;
    }

    cout << y << '\n';
}