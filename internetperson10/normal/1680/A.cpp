#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        if(r1 >= l2) cout << l2 << '\n';
        else cout << l1 + l2 << '\n';
    }
}