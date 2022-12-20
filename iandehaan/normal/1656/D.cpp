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
        ll n;
        cin >> n;
        ll fac2 = 1;
        while (n % 2 == 0) {
            n /= 2;
            fac2 *= 2;
        }
        if (n != 1) cout << min(n, fac2*2) << '\n';
        else cout << -1 << '\n';
    }
}