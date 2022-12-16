#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
        ll u[n];
        for (int i = 0; i < n; i++) {
            cin >> u[i];
            u[i]--;
        }
        ll s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        vector<ll> uni[n];
        for (int i = 0; i < n; i++) {
            uni[u[i]].pb(s[i]);
        }

        for (int i = 0; i < n; i++) sort(begin(uni[i]), end(uni[i]));

        ll skills[n+1];
        for (int k = 0; k <= n; k++) {
            skills[k] = 0;
        }

        vector<ll> prefsum[n];
        for (int i = 0; i < n; i++) {
            ll sm = 0;
            // first is 0
            prefsum[i].pb(sm);
            for (ll x : uni[i]) {
                sm += x;
                prefsum[i].pb(sm);
            }

            for (int k = 1; k <= uni[i].size(); k++) {
                int numteams = uni[i].size()/k;
                int numexcl = uni[i].size() - (numteams*k);

                ll smexcl = prefsum[i][numexcl];
                skills[k] += (sm - smexcl);
            }
        }


        for (int k = 1; k <= n; k++) {
            cout << skills[k] << ' ';
        }
        cout << endl;
    }
}