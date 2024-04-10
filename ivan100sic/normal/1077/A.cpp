#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
                ll a, b, k;
                cin >> a >> b >> k;
                ll z = (a-b) * (k/2);
                if (k % 2) z += a;
                cout << z << '\n';
        }
}