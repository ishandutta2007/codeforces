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

    ll n, k;
    cin >> n >> k;
    ll foursleft = n;
    ll twosleft = n*2;
    ll rem = 0;
    ll blah = 0;
    for (int i = 0; i < k; i++) {
        ll x;
        cin >> x;
        ll usefours = min(x/4, foursleft);
        foursleft -= usefours;
        x -= usefours*4;
        ll usetwos = min(x/2, twosleft);
        twosleft -= usetwos;
        x -= usetwos*2;
        if (x > 1) {
            if (x == 2) {
                blah++;
                continue;
            } else if (x == 3) {
                blah++;
                rem++;
                continue;
            }
            cout << "NO" << endl;
            return 0;
        }

        rem += x;
        //cout << i << ' ' << x << endl;
    }

    //cout << foursleft << ' ' << twosleft << ' ' << rem << endl;

    if (blah == 0) {
        if (2*foursleft + twosleft < rem) cout << "NO" << endl;
        else cout << "YES" << endl;
    } else {
        while (foursleft < blah) {
            blah--;
            rem += 2;
        }
        if (2*foursleft < rem+blah) cout << "NO" << endl;
        else if (foursleft < blah) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
}