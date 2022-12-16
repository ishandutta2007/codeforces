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
        rep(i, 0, n) cin >> a[i];
        int b[n];
        rep(i, 0, n) b[i] = a[i];
        sort(b, b+n);
        string out = "YES";
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                if (a[i] == b[i] && a[i+1] == b[i+1]) continue;
                if (a[i+1] == b[i] && a[i] == b[i+1]) continue;
                out = "NO";
                break;
            }
        } else {
            for (int i = 1; i < n; i += 2) {
                if (a[i] == b[i] && a[i+1] == b[i+1]) continue;
                if (a[i+1] == b[i] && a[i] == b[i+1]) continue;
                out = "NO";
                break;
            }
            if (a[0] != b[0]) out = "NO";
        }
        cout << out << endl;
    }
}