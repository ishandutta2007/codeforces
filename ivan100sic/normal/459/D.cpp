#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005], f[1000005];
int b[1000005];

void fadd(int x, int y) {
    while (x < 1000005) {
        b[x] += y;
        x += x & -x;
    }
}

int fget(int x) {
    int y = 0;
    while (x > 0) {
        y += b[x];
        x -= x & -x;
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        f[i] = ++mp[a[i]];
        fadd(f[i], 1);
    }
    mp.clear();
    long long z = 0;
    for (int i=n; i>=1; i--) {
        fadd(f[i], -1);
        int b = ++mp[a[i]];
        z += i - 1 - fget(b);
    }
    cout << z << '\n';
}