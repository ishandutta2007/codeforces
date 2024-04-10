#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int i,j, n, a[400000], t[400000];
    for (i = 0; i < 3e5; ++i)
        t[i] = 1e9;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> j;
        t[j] = i;
    }
    for (i = 0; i < 3e5; ++i)
    if (t[i] < t[j])
        j = i;
    cout << j;

}