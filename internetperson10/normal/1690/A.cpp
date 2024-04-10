#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (n+1)/3 << ' ' << (n+5)/3 << ' ' << (n-3)/3 << '\n';
    }
}