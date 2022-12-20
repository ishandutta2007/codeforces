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

ll getNum(ll x) {
    ll sqrtx = floor(sqrt(x));

    ll numbefore = sqrtx - 1;
    ll out = 3*numbefore;
    out += ((x-(sqrtx*sqrtx)+1) + sqrtx-1) / (sqrtx);
    return out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll out = getNum(r);
        if (l != 1) out -= getNum(l-1);
        cout << out << endl;
    }
}