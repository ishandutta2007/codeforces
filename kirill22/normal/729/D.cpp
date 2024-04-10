#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int tmp = 0, c = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            c += tmp / b;
            tmp = 0;
        }
        else tmp++;
    }
    c += tmp / b;
    tmp = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            tmp = 0;
        }
        else {
            tmp++;
            if (tmp >= b) {
                ans.pb(i + 1);
                c--;
                if (c <= a - 1) break;
                tmp -= b;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
}