#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

void bad() {
    cout << "YES" << endl;
    exit(0);
}

ll one = 1;
ll big = one << 50;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<ll> out;
    ll n;
    cin >> n;
    pair<ll, pair<ll, ll>> a[n];
    for (ll i = 0; i < n; i++) cin >> a[i].first >> a[i].second.first >> a[i].second.second;

    for (ll i = 0; i < n; i++) {
        //cout << i << ' ' << a[i].second.second << endl;
        if (a[i].second.second > 1e6) continue;
        out.pb(i+1);
        ll chnge = a[i].first;
        queue<ll> q;
        for (ll j = i+1; j < n; j++) {
            if (chnge < 0) break;
            if (a[j].second.second > 1e6) continue;
            a[j].second.second -= chnge;
            chnge--;
            if (a[j].second.second < 0) {
                q.push(j);
                a[j].second.second = big;
            }
        }

        while (!q.empty()) {
            
            ll top = q.front(); q.pop();
            //cout << top << endl;
            for (ll j = top+1; j < n; j++) {
                a[j].second.second -= a[top].second.first;
                if (a[j].second.second < 0) {
                    q.push(j);
                    a[j].second.second = big;
                }
            }
        }
    }
    cout << out.size() << endl;
    for (ll entry : out) cout << entry << ' ';
    cout << endl;
}