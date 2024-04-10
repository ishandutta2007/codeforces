#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int yours;
        int amtincr = 0;
        cin >> yours;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            amtincr += x;
        }

        cout << min(m, yours+amtincr) << endl;
    }
}