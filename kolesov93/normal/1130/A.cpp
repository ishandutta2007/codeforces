#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n;
    cin >> n;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) ++neg;
        else if (x > 0) ++pos;
    }
    if (pos + pos >= n) {
        cout << 1 << endl;
    } else if (neg + neg >= n) {
        cout << -1 << endl;
    } else {

        cout << 0 << endl;
    }


    return 0;
}