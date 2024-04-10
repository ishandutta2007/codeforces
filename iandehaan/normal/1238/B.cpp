#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> q;
    while (q--) {
        ll n, r;
        cin >> n >> r;
        priority_queue<ll> q;
        map<ll, ll> cnt;
        ll x[n];
        for (int i = 0; i < n; i++) cin >> x[i];
        sort(x, x+n);

        ll numshots = 0;
        unordered_set<int> shot;
        for (int i = n-1; i >= 0; i--) {
            if (shot.find(x[i]) != shot.end()) continue;
            shot.insert(x[i]);
            if (x[i]-numshots*r <= 0) break;
            numshots++;
        }
        cout << numshots << endl;

        

        
    }


}