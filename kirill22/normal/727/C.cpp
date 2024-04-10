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
    int n;
    cin >> n;
    int res, res2, res3;
    cout << "? 1 2" << endl; cin >> res;
    cout << "? 1 3" << endl; cin >> res2;
    cout << "? 2 3" << endl; cin >> res3;
    vector<int> a = {(res + res2 - res3) / 2, (res + res3 - res2) / 2, (res2 + res3 - res) / 2};
    for (int i = 3; i < n; i++) {
        cout << "? 1 " << i + 1 << endl; cin >> res;
        a.pb(res - a[0]);
    }
    cout << "! ";
    for (auto x : a) cout << x << " ";
    cout << endl;
}