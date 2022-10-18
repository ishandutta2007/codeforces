#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int a, b, n;
        cin >>  a >> b >> n;
        int c = 0;
        while (max(a, b) <= n) {
            if (a < b)
                a += b;
            else
                b += a;
            c++;
        }
        cout << c << '\n';
    }
}