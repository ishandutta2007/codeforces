#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

ll p[MAXN];
ll pos[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        rep(i, 0, n) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        ll lb = pos[0];
        ll ub = pos[0];

        ll out = 1; // full sequence
        rep(elmt, 0, n-1) {
            lb = min(lb, pos[elmt]);
            ub = max(ub, pos[elmt]);

            ll maxlen = (elmt+1)*2;

            ll nxtpos = pos[elmt+1];
            if (nxtpos >= lb && nxtpos <= ub) continue; // must include

            // do *not* include nxtpos

            ll reqlen = ub-lb+1;
            if (reqlen > maxlen) continue;

            ll leftextend = lb;
            if (nxtpos < lb) {
                leftextend = lb-nxtpos-1;
            }
            ll rightextend = n-ub-1;
            if (nxtpos > ub) {
                rightextend = nxtpos-ub-1;
            }

            leftextend = lb-leftextend;
            rightextend = ub + rightextend;

            leftextend = max(leftextend, ub-maxlen+1);
            rightextend = min(rightextend, lb+maxlen-1);
            
            ll med = -1*(lb-leftextend+1)*(ub-1);
            //cout << "med " << med << endl;

            // find where i+maxlen-1 = rightextend
            // i = rightextend-maxlen+1
            ll upperi = rightextend-maxlen+1;
            ll loweri = leftextend;
            //cout << "upper is " << loweri << ' ' << upperi << endl;
            if (upperi < loweri) upperi = leftextend-1;
            else {
                med += (maxlen-1)*(upperi-loweri+1);
                med += (upperi*(upperi+1))/2;
                med -= (loweri*(loweri-1))/2;
            }

            ll remaining = lb - upperi;
            med += rightextend*remaining;
            //cout << "adding " << rightextend << ' ' << remaining << endl;

            out += med;
            //cout << elmt << ' ' << med << endl;
            //out << lb << ' ' << ub << ' ' << leftextend << ' ' << rightextend << ' ' << loweri << ' ' << upperi << endl;
        }
        cout << out << '\n';
    }
}