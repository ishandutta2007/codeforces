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
        ll n, x;
        cin >> n >> x;
        ll out = 0;
        ll a[n];
        ll mn = 1e9;
        ll mx = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        for (int i = 0; i < n-1; i++) {
            out += abs(a[i]-a[i+1]);
        }

        if (mn > 1) {
            ll cost = 1e9;
            cost = min(cost, abs(a[0]-1));
            cost = min(cost, abs(a[n-1]-1));
            for (int i = 0; i < n-1; i++) {
                // slot it inbeween
                ll minelmt = min(a[i], a[i+1]);
                cost = min(cost, 2*abs(minelmt-1));
            }
            out += cost;
        }
        if (mx < x) {
            ll cost = 1e9;
            cost = min(cost, abs(a[0]-x));
            cost = min(cost, abs(a[n-1]-x));
            for (int i = 0; i < n-1; i++) {
                // slot it inbeween
                ll maxelmt = max(a[i], a[i+1]);
                cost = min(cost, 2*abs(x-maxelmt));
            }
            out += cost;

        }
        cout << out << endl;
    }
}