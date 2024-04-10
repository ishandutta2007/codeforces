#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t;
int a[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[0] + a[1] < a[2]) {
            cout << a[0] + a[1] << endl;
        } else {
            cout << (a[0] + a[1] + a[2]) / 2 << endl;
        }
    }
    return 0;
}