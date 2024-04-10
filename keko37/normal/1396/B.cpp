#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }
        if (sum % 2 == 1 || mx * 2 > sum) {
            cout << "T\n";
        } else {
            cout << "HL\n";
        }
    }
    return 0;
}