#include <bits/stdc++.h>
using namespace std;

long long f() {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m > n)
        swap(m, n);

    if (n > k)
        return -1;

    long long diag = m;
    int normal = 0;
    n -= m;

    if (n & 1) {
        diag += n - 1;
        normal += 1;
    } else {
        diag += n;
    }
    
    long long moves_left = k - diag - normal;
    if (moves_left & 1) {
        if (normal)
            diag += moves_left;
        else
            diag += moves_left - 2;
    } else {
        diag += moves_left;
    }
    return diag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q --> 0)
        cout << f() << '\n';
}