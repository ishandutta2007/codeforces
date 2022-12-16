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
    while (t--){
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        bool ok = true;
        rep(offset, 0, m-1) {
            if (a[n-offset-1] != b[m-offset-1]) {
                ok = false;
                break;
            }
        }

        bool found = false;
        rep(i, 0, n-m+1) {
            if (a[i] == b[0]) found = true;
        }

        if (found && ok) cout << "YES\n";
        else cout << "NO\n";
    }
}