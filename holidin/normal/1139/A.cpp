#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 20;


int main() {
    int i, j, k, l, r, n;
    string s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    long long ans = 0;
    for (i = 0; i < s.size(); ++i)
    if ((s[i] - '0') % 2 == 0)
        ans += i + 1;
    cout << ans;
}