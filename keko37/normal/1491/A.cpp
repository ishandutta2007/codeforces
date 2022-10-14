#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, q, br;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        br += a[i];
    }
    for (int i = 1; i <= q; i++) {
        int tip, k;
        cin >> tip >> k;
        if (tip == 1) {
            br -= a[k];
            a[k] = 1 - a[k];
            br += a[k];
        } else {
            if (k <= br) cout << "1\n"; else cout << "0\n";
        }
    }
    return 0;
}