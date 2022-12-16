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

ll best(string n, int digit1, int digit2) {
    string out;
    if (digit2 != -1) {
        if (digit2 > n[0]-'0') {
            // small man is bigger... fill with small men
            out.pb('0' + digit2);
            for (int i = 0; i < sz(n)-1; i++) {
                out.pb('0'+digit2);
            }
            return stoll(out);
        }
        
        if (digit2 == n[0] - '0') {
            // small man is equal.. check if we can put a small man here
            if (sz(n) == 1) {
                // yep we can do it
                return digit2;
            }

            string newstr;
            for (int i = 1; i < sz(n); i++) {
                newstr.pb(n[i]);
            }

            ll intout = best(newstr, digit1, digit2);
            if (intout != -1) {
                // yep we can do it
                ll thousands = 1;
                for (int i = 0; i < sz(n)-1; i++) thousands *= 10;
                intout += thousands*digit2;
                return intout;
            }
        }
    }

    // well we can't put digit2 there sad face
    if (digit1 > n[0]-'0') {
        // small man is bigger... fill with small men
        out.pb('0' + digit1);
        for (int i = 0; i < sz(n)-1; i++) {
            if (digit2 != -1) out.pb('0'+digit2);
            else out.pb('0'+digit1);
        }
        return stoll(out);
    }
    
    if (digit1 == n[0] - '0') {
        // small man is equal.. check if we can put a small man here
        if (sz(n) == 1) {
            // yep we can do it
            return digit1;
        }

        string newstr;
        for (int i = 1; i < sz(n); i++) {
            newstr.pb(n[i]);
        }

        ll intout = best(newstr, digit1, digit2);
        if (intout != -1) {
            // yep we can do it
            ll thousands = 1;
            for (int i = 0; i < sz(n)-1; i++) thousands *= 10;
            intout += thousands*digit1;
            return intout;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //cout << best("100", 1, -1) << endl;

    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int k;
        cin >> k;
        if (k == 2) {
            ll out = -1;
            for (int digit1 = 1; digit1 < 10; digit1++) {
                for (int digit2 = 0; digit2 < digit1; digit2++) {
                    if (out == -1) {
                        out = best(n, digit1, digit2);
                    } else {
                        ll intout = best(n, digit1, digit2);
                        if (intout != -1) out = min(out, intout);
                    }
                }
            }
            if (out != -1) cout << out << endl;
            else {
                // i don't think we ever get here but eh
                n.insert(0, "0");
                for (int digit1 = 1; digit1 < 10; digit1++) {
                    for (int digit2 = 0; digit2 < digit1; digit2++) {
                        if (out == -1) {
                            out = best(n, digit1, digit2);
                        } else {
                            ll intout = best(n, digit1, digit2);
                            if (intout != -1) out = min(out, best(n, digit1, digit2));
                        }
                    }
                }

                cout << out << endl;
            }
        } else {
            ll out = -1;
            for (int digit1 = 1; digit1 < 10; digit1++) {
                if (out == -1) {
                    out = best(n, digit1, -1);
                } else {
                    ll intout = best(n, digit1, -1);
                    if (intout != -1) out = min(out, intout);
                }
            }

            cout << out << endl;
        }
    }
}