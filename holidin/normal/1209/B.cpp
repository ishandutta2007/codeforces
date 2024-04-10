#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;

int a[N], b[N];
string s;
int n;

int f(int x) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int bg = s[i] - '0';
        if (b[i] > x)
            ans += bg;
        else
            ans += bg ^ (((x - b[i]) / a[i] + 1) % 2);
    }
    return ans;
}

int main() {
    int i, j, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    int ans = 0;
    for (int tim = 0; tim < 20000; ++tim)
       ans = max(ans, f(tim));
    cout << ans;
}