#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int a[55], b[55], c[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    reverse(a, a+n);

    for (int i=0; i<n; i++) {
        if (!c[a[i]]) {
            c[a[i]] = 1;
            b[m++] = a[i];
        }
    }

    cout << m << '\n';
    reverse(b, b+m);
    for (int i=0; i<m; i++)
        cout << b[i] << ' ';
    cout << '\n';

}