#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll par[200001];
ll findPar(int x) {
    if (par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

void Union(int x, int y) {
    if (findPar(x) == findPar(y)) return;
    par[findPar(x)] = par[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 0; i < n; i++) par[i] = i;
        char inp[n];
        for (int i = 0; i < n; i++) cin >> inp[i];
        for (ll i = 0; i < n; i++) {
            if (i+k < n) Union(i, i+k);
            Union(i, n-i-1);
            //cerr << "done for " << i << endl;
        }

        //cerr << "here1" << endl;


        vector<ll> things[n];
        for (ll i = 0; i < n; i++) {
            things[findPar(i)].pb(i);
        }

        //cerr << "here" << endl;

        ll out = 0;
        for (ll i = 0; i < n; i++) {
            if (things[i].empty()) continue;

            ll cnts[26];
            for (int i = 0; i < 26; i++) cnts[i] = 0;
            for (ll ind : things[i]) {
                cnts[inp[ind]-'a']++;
            }

            ll mx = 0;
            for (int i = 0; i < 26; i++) mx=max(mx, cnts[i]);
            //cout << i << ' ' << things[i].size() << ' ' << mx << endl;
            out += things[i].size()-mx;
        }
        cout << out << endl;
    }
}