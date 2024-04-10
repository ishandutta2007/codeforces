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

#define MAXN 200'010
int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> last;
        rep(i, 0, n) {
            cin >> a[i];
            last[a[i]] = i+1;
        }

        int out = -1;

        rep(x, 1, 1001) rep(y, 1, 1001) {
            if (last.count(x) == 0 || last.count(y) == 0) continue;
            if (__gcd(x, y) != 1) continue;

            out = max(out, last[x] + last[y]);
        }
        cout << out << endl;
    }
}