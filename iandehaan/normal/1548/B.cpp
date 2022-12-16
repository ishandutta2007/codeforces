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


struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return __gcd(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
        //cout << "blah " << ra << ' ' << rb << endl;
		return f(ra, rb);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        

        Tree ragetree = Tree(n-1);
        for (int i = 0 ; i < n-1; i++) {
            ragetree.update(i, abs(a[i+1]-a[i]));
            //cout << "hello " << i << ' ' << abs(a[i+1]-a[i]) << endl;
        }

        int out = 0;
        int currstart = 0;
        for (int i = 0; i < n-1; i++) {
            while (ragetree.query(currstart, i+1) == 1) {
                //cout << currstart << ' ' << i << ' ' << ragetree.query(currstart, i+1) << endl;
                if (currstart == i+1) break;
                currstart++;
            }
            out = max(out, i-currstart+1);
            //cout << "next " << i << ' ' << currstart << ' ' << ragetree.query(currstart, i+1) << endl;
        }

        cout << out+1 << endl;
        
    }
}