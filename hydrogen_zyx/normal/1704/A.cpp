#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        while (!a.empty() && !b.empty() && a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        }
        if (b.size() >= 2) {
            cout << "NO" << endl;
        } else if (b.empty()) {
            cout << "YES" << endl;
        } else {
            char c = b[0];
            bool ok = 0;
            for (auto x: a) if (x == c) ok = 1;
            if (ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}