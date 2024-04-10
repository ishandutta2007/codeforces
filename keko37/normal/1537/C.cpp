#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
int h[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        sort(h + 1, h + 1 + n);
        int mn = 2e9, ind = -1;
        for (int i = 2; i <= n; i++) {
            int val = h[i] - h[i - 1];
            if (val < mn) {
                mn = val;
                ind = i;
            }
        }
        if (h[n] - h[1] == mn) {
            for (int i = 1; i <= n; i++) {
                cout << h[i] << " ";
            }
            cout << '\n';
        } else {
            for (int i = ind; i <= n; i++) {
                cout << h[i] << " ";
            }
            for (int i = 1; i < ind; i++) {
                cout << h[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}