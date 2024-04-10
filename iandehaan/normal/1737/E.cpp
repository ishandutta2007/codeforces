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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}


const ll mod = 1e9 + 7; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

#define MAXN 1'000'010

vector<Mod> powtwo(MAXN, 0);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    powtwo[0] = 1;
    rep(i, 1, MAXN) powtwo[i] = powtwo[i-1] * 2;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Mod twoton = 1;
        rep(i, 0, n) twoton = twoton * 2;

        int lastaccounted = n;
        Mod subamt = 0;

        vector<Mod> cnts(n, 0);
        for (int i = n-1; i >= 0; i--) {
            int numfixedleft = (i+1 + 1)/2; // includes ourselves

            if (i == n-1) {
                numfixedleft--; // ourselves can point right
            }

            int numfree = n-numfixedleft;

            //cout << i << ' ' << numfree << ' ' << numfixedleft << endl;

            cnts[i] = powtwo[numfree];

            int nextmatter = 2*(i+1)-1;
            while (nextmatter < lastaccounted) {
                //cout << "doing " << nextmatter << endl;
                subamt = subamt + cnts[lastaccounted-1];
                lastaccounted--;



            }
            Mod mysubamt = subamt / powtwo[numfixedleft];
            
            //cout << "blah " << subamt.x << ' ' << mysubamt.x << ' ' << cnts[i].x << endl;
            cnts[i] = cnts[i] - mysubamt;
        }


        rep(i, 0, n) cnts[i] = cnts[i] / powtwo[n];
        rep(i, 0, n) cout << cnts[i].x << '\n';
    }
}