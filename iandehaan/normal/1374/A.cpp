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

    int t;
    cin >> t;
    while (t--) {
        ll x, y, n;
        cin >> x >> y >> n;

        int first = n/x;
        if (first*x + y > n) {
            first--;
        }

        cout << first*x + y << endl;
    }
}