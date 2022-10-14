#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t;
int a[MAXN], b[MAXN], c[MAXN];

void precompute () {
    memset(a, -1, sizeof a);
    memset(b, -1, sizeof b);
    memset(c, -1, sizeof c);
    for (int i = 0; i <= 1000 / 3; i++) {
        for (int j = 0; j <= 1000 / 5; j++) {
            for (int k = 0; k <= 1000 / 7; k++) {
                int val = i * 3 + j * 5 + k * 7;
                if (val > 1000) break;
                a[val] = i; b[val] = j; c[val] = k;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (a[n] == -1) cout << -1 << '\n'; else cout << a[n] << " " << b[n] << " " << c[n] << '\n';
    }
    return 0;
}