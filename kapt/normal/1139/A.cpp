#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0) {
            ans += i + 1;
        }
    }
    cout << ans;
    return 0;
}