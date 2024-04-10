#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    int ans = 0;
    while(n--) {
        int x;
        cin >> x;
        ans++;
        if(x > h) ans++;
    }
    cout << ans << '\n';
}