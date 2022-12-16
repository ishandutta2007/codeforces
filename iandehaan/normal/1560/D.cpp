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

// turn b into a
int stringdist(string a, string b) {
    int aind = 0;
    int bind = 0;
    int out = 0;
    while (aind < sz(a)) {
        if (bind < sz(b)) {
            if (a[aind] == b[bind]) {
                aind++;
                bind++;
            } else {
                out++;
                bind++;
            }
        } else {
            out++;
            aind++;
        }
    }

    while (bind < sz(b)) {
        out++;
        bind++;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    //cout << stringdist("64", "6") << endl;
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int out = 1e9;
        for (ll i = 0; i <= 63; i++) {
            ll big = ((ll) 1 << i);

            out = min(out, stringdist(to_string(big), n));

        }
        cout << out << endl;
    }
}