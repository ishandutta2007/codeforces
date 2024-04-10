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

    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll out = 0;
    ll decramt = 0;
    ll changeamt = 0;
    priority_queue<pair<int, ll>> expire;
    for (int i = n-1; i >= 0; i--) {
        changeamt -= decramt;
        a[i] -= changeamt;
        
        //cout << i << ' ' << changeamt << ' ' << decramt << ' ' << a[i] << endl;
        while (!expire.empty() && expire.top().first == i) {
            decramt -= expire.top().second;
            //cout << "decreasing by " << expire.top().second << endl;
            expire.pop();
        }
        ll biggestposs = min(k, (ll)i+1);

        ll numops = max((ll)0, (a[i] + biggestposs - 1) / biggestposs);

        out += numops;
        decramt += numops;
        changeamt += biggestposs * numops;

        // should decr a[i-1] by (biggestposs - 1) * numops
        // decr a[i-2] by (biggestposs - 2) * numops
        // ...
        // expire at i - (biggestposs - 1)

        expire.push(mp(i - biggestposs, numops));


    }
    cout << out << endl;
}