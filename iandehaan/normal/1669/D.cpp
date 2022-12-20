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
        int r = 0;
        int b = 0;
        string out = "YES";
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'W') {
                if (r != 0 || b != 0) {
                    if (r == 0 || b == 0) out = "NO";
                }
                r = 0;
                b = 0;
            } else if (c == 'R') r++;
            else b++;
        }
        if (r != 0 || b != 0) {
            if (r == 0 || b == 0) out = "NO";
        }
        cout << out << endl;
    }
}