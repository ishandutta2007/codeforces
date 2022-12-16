#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int k, n;
int a[200000];

bool works(int amt) {
    // try odd indices
    int got = 0;
    bool turn = true;
    for (int i = 0; i < n; i++) {
        //cout << i << ' ' << turn << endl;
        if (turn && a[i] <= amt) {
            got++;
            turn = false;
        }

        else if (!turn) {
            got++;
            turn = true;
        }
    }
    //cout << amt << ' ' << got << endl;
    if (got >= k) return true;


    // try even indices
    got = 0;
    turn = false;
    for (int i = 0; i < n; i++) {
        if (turn && a[i] <= amt) {
            got++;
            turn = false;
        }

        else if (!turn) {
            got++;
            turn = true;
        }
    }
    if (got >= k) return true;


    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll hi = 1e9+10;
    ll lo = 0;
    while (abs(hi-lo) > 5) {
        ll mid = (hi+lo)/2;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    for (int i = lo-2; i <= hi+2; i++) {
        if (works(i)) {
            cout << i << endl;
            return 0;
        }
    }
}