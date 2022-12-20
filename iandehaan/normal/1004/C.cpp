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

    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll numunique[n];
    unordered_set<ll> seen;
    for (int i = n-1; i>= 0; i--) {
        
        numunique[i] = seen.size();
        seen.insert(a[i]);
    }

    ll out = 0;
    unordered_set<ll> seen2;
    for (int i = 0; i < n; i++) {
        if (seen2.find(a[i]) == seen2.end()) {
            out += numunique[i];
        }
        seen2.insert(a[i]);
    }
    cout << out << endl;
}