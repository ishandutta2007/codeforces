#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

set <long long> ans;

long long f(long long n, long long a) {
    return a * ((n / a) * (n / a - 1)) / 2 + n / a;
}

int main() {
    int a, b, c, i, j, y, n, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i * i <= n; ++i)
    if (n % i == 0) {
        ans.insert(f(n, i));
        ans.insert(f(n, n / i));
    }
    for (set <long long> :: iterator it = ans.begin(); it != ans.end(); ++it)
        cout << (*it) << ' ';
}