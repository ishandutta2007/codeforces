#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int k[N], t[N], c[N], a[N];

int main() {
    int i, j, n;
    long long sum = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int top = 0;
    for (i = 1; i <= n; ++i) {
        j = n - a[i];
        if (k[j] == 0) {
            ++top;
            k[j] = j;
            t[j] = top;
        }
        --k[j];
        c[i] = t[j];
    }
    for (i = 1; i <= n; ++i)
    if (k[i] != 0) {
         cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    for (i = 1; i <= n; ++i)
        cout << c[i] << ' ';
}