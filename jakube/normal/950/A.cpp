#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, a;
    cin >> l >> r >> a;
    while (a) {
        if (l < r)
            l++;
        else 
            r++;
        a--;
    }
    cout << min(l, r) * 2 << endl;
}