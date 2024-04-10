#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) {
            if (b+d == a) {
                cout << "Yes" << endl;
                continue;
            }
        }
        if (a == d) {
            if (b + c == a) {
                cout << "Yes" << endl;
                continue;
            }
        }
        if (b == c) {
            if (a + d == b) {
                cout << "Yes" << endl;
                continue;
            }
        }
        if (b == d) {
            if (a + c == b) {
                cout << "Yes" << endl;
                continue;
            }
        }
        cout << "No" << endl;
    }
}