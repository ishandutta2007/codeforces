#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e3;

int main() {
    int a, b, x;
    //freopen("input.txt", "r", stdin);
    //ios_base:: sync_with_stdio(false);
    cin >> x;
    for (a = 1; a < N; ++a)
    for (b = 1; b < N; ++b)
    if (a % b == 0 && a * b > x && a / b < x) {
        cout << a << ' ' << b << endl;
        return 0;
    }
    cout << -1;
}