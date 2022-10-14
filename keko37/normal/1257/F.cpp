#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 105;

int n;
int a[MAXN], x[MAXN], y[MAXN];
llint m1 = 1000000009, b1, m2 = 1000000007, b2;
map <pair <llint, llint>, int> mp;

void hash_init () {
    b1 = rand() % 10000 + (1 << 15) + 1;
    b2 = rand() % 10000 + (1 << 15) + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0) * getpid());
    hash_init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        y[i] = a[i] % (1 << 15);
        x[i] = a[i] / (1 << 15);
    }
    for (int mask = 0; mask < (1 << 15); mask++) {
        llint h1 = 0, h2 = 0;
        for (int i = 1; i < n; i++) {
            int val = __builtin_popcount(y[i - 1] ^ mask) - __builtin_popcount(y[i] ^ mask);
            h1 = (h1 * b1 + val) % m1;
            h2 = (h2 * b2 + val) % m2;
        }
        mp[{h1, h2}] = mask;
    }
    for (int mask = 0; mask < (1 << 15); mask++) {
        llint h1 = 0, h2 = 0;
        for (int i = 1; i < n; i++) {
            int val = __builtin_popcount(x[i - 1] ^ mask) - __builtin_popcount(x[i] ^ mask);
            h1 = (h1 * b1 + val) % m1;
            h2 = (h2 * b2 + val) % m2;
        }
        h1 = (m1 - h1) % m1;
        h2 = (m2 - h2) % m2;
        if (mp.find({h1, h2}) != mp.end()) {
            cout << mask * (1 << 15) + mp[{h1, h2}];
            return 0;
        }
    }
    cout << -1;
    return 0;
}