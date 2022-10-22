#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a = 0, b = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1) a++;
        else b++;
    }
    int ans = 0;
    ans += min(a, b);
    a -= min(a, b);
    cout << ans + a/3 << '\n';

}