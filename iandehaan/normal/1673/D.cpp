#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair

constexpr ll mod = 1e9+7;

ll lcm(ll a, ll b) {
    return (a*b)/(__gcd(a,b));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    // cd(B) = 3
    // B = 0, 3, 6, 9, 12, 15
    // cd(C) = 6
    // C = 6, 12

    // cd(A) = 2
    // A = 6, 8, 10, 12
    // A = 2, 4, 6, 8, 10, 12, 14, 16

    // possible starts = [2, 4, 6]
    // possible ends = [12, 14, 16]
    // sz(starts) = cd(B)/gcd(cd(A), cd(B))?

    // Try every possible cd(A) that divides cd(C)
    // add cd(B)/gcd(cd(A), cd(B)) squared possibilities

    // need lcm(cd(A), cd(B)) = cd(C)



    // B = 0, 4, 8, 12, 16
    // C 

    // cd(C) =? lcm(cd(A), cd(B))

    // cd(A) | cd(C)
    // cd(B) | cd(C)

    int t;
    cin >> t;
    while (t--) {
        ll b, q, y, c, r, z;
        cin >> b >> q >> y >> c >> r >> z;

        if (r % q != 0) {
            // uh-oh!
            cout << 0 << endl;
            continue;
        }

        ll bend = b + q*(y-1);
        ll cend = c + r*(z-1);
        if (cend > bend || c < b) {
            // b does not contain c
            cout << 0 << endl;
            continue;
        }
        if ((c-b) % q != 0) {
            // can't generate first term
            cout << 0 << endl;
            continue;
        }

        if (cend+r > bend || c-r < b) {
            cout << -1 << endl;
            continue;
        }



        // Assume not 0 or infinity.
        set<ll> facs;
        ll out = 0;
        for (ll d = 1; d*d <= r; d++) {
            if (r % d == 0) {
                facs.insert(d);
                facs.insert(r/d);
            }
            
        }

        for (ll d : facs) {
            if (lcm(q, d) == r) {
                // poggies!!!
                ll thing = q / (__gcd(q, d));
                out += thing*thing;
                out %= mod;
            }
        }
        cout << out << endl;
    }
}