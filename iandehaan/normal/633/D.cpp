#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

map<pii, ll> memo;
set<ll> st;

map<ll, ll> cnts;

ll dp(ll a, ll b) {
    //cout << a << ' ' << b << endl;
    //cout << "cnt=" << cnts[1] << endl;
    if (st.find(a+b) == st.end() || cnts[a+b] <= 0) return 2;

    cnts[a+b]--;
    ll nxt = dp(b, a+b);
    cnts[a+b]++;
    return 1 + nxt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        st.insert(x);
        if (cnts.find(x) == cnts.end()) cnts[x] = 0;
        cnts[x]++;
    }

    ll out = 0;
    for (int diff = 1; diff < n; diff++) {
        for (int i = 0; i < n; i++) {
            //cout << out << endl;
            if (a[i] == 0 && a[(i+diff)%n] == 0) {
                out = max(out, cnts[0]);
                continue;
            }
            cnts[a[i]]--;
            cnts[a[(i+diff)%n]]--;
            out = max(out, dp(a[i], a[(i+diff)%n]));
            cnts[a[i]]++;
            cnts[a[(i+diff)%n]]++;
            //cout << "blah: " << cnts[1] << endl;
        }
    }
    cout << out << endl;
}