#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int br = 0, naso = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 1 && naso == 0) br++; else naso = 1;
        }
        cout << ((br + naso) % 2 ? "First\n" : "Second\n");
    }
    return 0;
}