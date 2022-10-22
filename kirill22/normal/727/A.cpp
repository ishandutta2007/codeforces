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
    int x, y;
    cin >> x >> y;
    vector<int> a;
    while (y > 0) {
        a.pb(y);
        if (x == y) {
            cout << "YES\n";
            cout << a.size() << "\n";
            while (a.size() > 0) { cout << a.back() << " "; a.pop_back(); }
            return 0;
        }
        if (y % 2 == 0) y /= 2;
        else {
            if (y % 10 == 1) { y /= 10; }
            else { cout << "NO"; return 0; }
        }
    }
    cout << "NO";
}