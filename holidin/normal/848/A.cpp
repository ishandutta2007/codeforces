#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 0) {
        cout << 'a';
        return 0;
    }
    char top = 'a';
    string s;
    for (i = 5000; i >= 1; --i)
    while ((i * (i - 1)) / 2 <= n && n > 0) {
        for (j = 0; j < i; ++j)
            s += top;
        ++top;
        n -= (i * (i - 1)) / 2;
    }
    cout << s;
}