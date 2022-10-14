#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 55;

int t, n;
llint a[MAXN], sum[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        sum[0] = sum[1] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum[i % 2] += a[i];
        }
        int tip = (sum[1] < sum[0]);
        for (int i = 0; i < n; i++) {
            if (i % 2 == tip) cout << 1 << " "; else cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}