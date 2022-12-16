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

ll n, k;
string s, t;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int n, k;
    cin >> n >> k;
    //string s, t;
    cin >> s >> t;

    ll out = 0;
    ll lst = 1;
    for (int i = 0; i < n; i++) {
        //cout << i << ' ' << out << ' ' << lst << endl;
        if (s[i] == t[i]) {
            // whatever we had previously we can have again
            ll intermed = lst;

            if (s[i] == 'b') {
                // maybe we can also do some things ending in a
                // in fact we can do all the things that are not minimum'd...
                intermed += lst-1;
            } else if (s[i] == 'a') {
                // maybe we can also do some things ending in b... oh
                intermed += lst-1;
            }

            out += min(k, intermed);
            lst = min(2*k, intermed);
        } else if (s[i] < t[i]) {
            // s[ind] = 'a'
            // t[ind] = 'b'

            ll intermed = 2*lst; // we can do everything we did before... twice
            out += min(k, intermed);
            lst = min(2*k, intermed);
        } else if (s[i] > t[i]) {
            // s[ind] = 'b'
            // t[ind] = 'a'

            // we can add an a to anything that is not min'd out
            ll intermed = lst-1;

            // we can add a b to anything that is not min'd out
            intermed += lst-1;

            out += min(k, intermed);
            lst = min(2*k, intermed);
        }

        //cout << i << ' ' << out << endl;
    }

    cout << out << endl;
    
}