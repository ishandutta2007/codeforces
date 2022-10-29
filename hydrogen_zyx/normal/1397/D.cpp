#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[500000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int mmax = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            mmax = max(mmax, a[i]);
            sum += a[i];
        }
        if ((sum & 1) || mmax * 2 > sum)
            cout << 'T' << endl;
        else
            cout << "HL" << endl;
    }
}