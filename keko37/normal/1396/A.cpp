#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint n;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << -a[1] << endl;
        cout << 1 << " " << 1 << endl;
        cout << a[1] << endl;
        cout << 1 << " " << 1 << endl;
        cout << -a[1] << endl;
        return 0;
    }
    cout << 1 << " " << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << -a[i] * n << " ";
    }
    cout << endl;
    cout << 1 << " " << n - 1 << endl;
    for (int i = 1; i < n; i++) {
        cout << a[i] * (n - 1) << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << a[n] * (n - 1) << endl;
    return 0;
}