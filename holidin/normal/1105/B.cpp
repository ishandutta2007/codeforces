#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 2;

int a[N];

int main() {
    string s;
    int i, j, k, n, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    int ans = 0;
    for (j = 'a'; j <= 'z'; ++j) {
        int ct = 0, tk = 0;
        for (i = 0; i < s.size(); ++i)
        if (s[i] != j)
            tk = 0;
        else {
            ++tk;
            ct += tk / k;
            tk %= k;
        }
        ans = max(ans, ct);
    }
    cout << ans;
}