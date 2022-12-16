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
        // let a = r
        // then b = r/2 + 1
        // or l

        ll l, r;
        cin >> l >> r;

        ll a = r;
        ll b = max(r/2 + 1, l);
        if (b > a) b = a;
        cout << a % b << endl;
    }
}