#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        bool seen[300];
        for (int i = 0; i < 300; i++) seen[i] = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            seen[a] = true;
        }

        int ind = 1;
        while (x) {
            if (!seen[ind]) {
                x--;
            }
            ind++;
        }
        while (seen[ind]) ind++;
        cout << ind-1 << endl;
    }
}