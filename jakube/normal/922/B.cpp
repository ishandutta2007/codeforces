#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int c = a ^ b;
            if (c >= b && c <= n && a + b > c) 
                cnt++;
        }
    }
    cout << cnt << '\n';
}