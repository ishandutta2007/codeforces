#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, x;
int w[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        sort(w, w + n);
        int sum = 0, ind = -1;
        for (int i = 0; i < n; i++) {
            sum += w[i];
            if (sum == x) {
                ind = i;
                break;
            }
        }
        if (ind == -1 || ind < n-1) {
            if (ind != -1) swap(w[ind], w[ind + 1]);
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << w[i] << " "; cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}