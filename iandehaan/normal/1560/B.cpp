#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        ll circlesize = (b-a)*2;
        if (circlesize < max(b, c)) {
            cout << -1 << endl;
            continue;
        }

        ll diff = b-a;
        if (c + diff > circlesize) {
            if (c - diff <= 0) {
                cout << -1 << endl;
            } else {
                cout << c-diff << endl;
            }
        } else {
            cout << c+diff << endl;
        }
    }
}