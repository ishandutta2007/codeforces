#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    string s(100, 'a');
    cout << s << '\n';
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s[x] == 'a') s[x] = 'b';
        else s[x] = 'a';
        cout << s << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
}