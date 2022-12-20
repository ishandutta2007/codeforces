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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        bool good = true;
        bool decr = false;
        for (int i = 0; i < n; i++) {
            if (!decr) {
            if (a[i] < i) {
                decr = true;
                if (a[i] >= a[i-1]) {
                    a[i] = a[i-1]-1;
                    if (a[i] < 0) {
                        good = false;
                        break;
                    }
                }
            }
            } else {
                if (a[i] >= a[i-1]) {
                    a[i] = a[i-1]-1;
                    if (a[i] < 0) {
                        good = false;
                        break;
                    }
                }
            }
        }
        if (good) cout << "Yes" << endl;
        else cout << "No" << endl;
       
    }
}