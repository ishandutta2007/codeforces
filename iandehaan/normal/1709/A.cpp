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
        int x;
        cin >> x;
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        x--;
        int y = a[x];
        if (y == 0) {
            cout << "NO\n";
            continue;
        }

        y--;
        int z = a[y];
        if (z == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

    }
}