    #include <bits/stdc++.h>
    using namespace std;
     
    #define rep(i, a, b) for (int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define sz(x) (int)(x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    #define pb push_back 
    #define mp make_pair
     
     
    // gcd(x+2, x+4) = gcd(x+2, 2) = 1 if x odd, 2 if x even
     
    // if x odd, we then want to query
    // gcd((x-1)+4, (x-1)+8)
     
    // gcd(x+4, x+8) = gcd(x+4, 4) = 4 if x div. by 4, something else otherwise
     
    // gcd(x+8, x+16)
     
    int main() {
        cin.tie(0)->sync_with_stdio(0);
    	cin.exceptions(cin.failbit);
     
        int t;
        cin >> t;
        while (t--) {
            ll x = 0;
            int numq = 30;
            ll two = 1;
            ll ind = 0;
            while (numq--) {
                cout << "? " << two-x << ' ' << (two*2 + two -x) << endl;
     
                ll resp;
                cin >> resp;
                if (resp != two) {
                    x |= (1 << ind);
                }
     
                two *= 2;
                ind++;
            }
            cout << "! " << x << endl;
        }
    }