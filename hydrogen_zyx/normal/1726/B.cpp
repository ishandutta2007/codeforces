
#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n > m) {
            cout << "NO" << endl;
            continue;
        }
        if (n & 1) {
            cout << "YES" << endl;
            for (int i = 1; i < n; i++) cout << 1 << ' ';
            cout << m - n + 1 << endl;
        } else {
            if ((m - n + 2) % 2 == 0) {
                cout << "YES" << endl;
                for (int i = 1; i < n - 1; i++) cout << 1 << ' ';
                cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}