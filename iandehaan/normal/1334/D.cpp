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

    ll t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        ll sm = 0;
        ll iters = 0;
        ll add = n-1;
        if (l == n*(n-1)+1) {
            cout << 1 << endl;
            continue;
        }
        // TODO: last 1 case
        //cout << "mmm" << endl;
        while (2*sm < l) {
            sm += add;
            add--;
            iters++;
        }
        
       sm -= (add+1);
       sm *= 2;
       sm++;
       //cout << "here" << endl;
       ll currnext = iters+1;
       bool startonone = true;
       while (sm < l) {
           
           if (sm +1 < l) {
               sm += 2;
               currnext++;
           } else {
               startonone = false;
               sm++;
           }
       }

       //cout << "here" << endl;
       

       for (ll i = l; i <= min(r, n*(n-1)); i++) {
           ll toprint;
           if (startonone) {
               if ((i-l) % 2 == 0) toprint = iters;
               else {
                   toprint = currnext;
                   currnext++;
               }
           } else {
               if ((i-l)%2 == 0) {
                   toprint = currnext;
                   currnext++;
               } else {
                   toprint = iters;
               }
           }
           if (toprint == n) {
               iters++;
               currnext = iters+1;
           }
           cout << toprint << ' ';
       }

       if (r == n*(n-1)+1) {
           cout << 1 << ' ';
       }
       cout << endl;
    }
}