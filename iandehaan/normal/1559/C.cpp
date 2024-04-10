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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        if (a[0] == 1) {
            // start at n+1
            cout << n+1 << ' ';
            for (int i = 1; i <= n; i++) cout << i << ' ';
            cout << endl;
            continue;
        }

        if (a[n-1] == 0) {
            // 1 -> n
            for (int i = 1; i <= n+1; i++) cout << i << ' ';
            cout << endl;
            continue;
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0 && a[i+1] == 1) {
                //cout << "this case " << i << endl;
                // start at 1, go to i
                for (int j = 1; j <= i+1; j++) cout << j << ' ';
                // go to n+1
                cout << n+1 << ' ';
                // go back to i+1, to the end
                for (int j = i+2; j <= n; j++) cout << j << ' ';
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << endl;
    }
}