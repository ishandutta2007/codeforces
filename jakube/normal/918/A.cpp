#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<bool> fib(n + 1, false);
    int a = 1;
    int b = 1;
    while (b <= n) {
        fib[b] = true;
        int tmp = b;
        b += a;
        a = tmp;
    }
    for (int i = 0; i < n; i++) {
        cout << (fib[i+1] ? 'O' : 'o');
    }
    cout << '\n';
}