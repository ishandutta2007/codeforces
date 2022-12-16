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
        int n, m;
        cin >> n >> m;
        string a[n];
        rep(i, 0, n) cin >> a[i];
        int out = 1e9;
        rep(i, 0, n) {
            rep(j, i+1, n) {
                int med = 0;
                rep(k, 0, m) {
                    med += abs(a[i][k]-a[j][k]);
                }
                out = min(out, med);
            }
        }
        cout << out << '\n';
    }
}