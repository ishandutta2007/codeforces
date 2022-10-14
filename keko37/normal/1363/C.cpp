#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, x;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int d = 0;
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            if (a == x || b == x) d++;
        }
        if (d <= 1 || n % 2 == 0) cout << "Ayush\n"; else cout << "Ashish\n";
    }
    return 0;
}