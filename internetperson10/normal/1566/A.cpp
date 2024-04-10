#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, s;
        cin >> n >> s;
        if(n%2) n++;
        else n += 2;
        n /= 2;
        cout << s/n << '\n';
    }
}