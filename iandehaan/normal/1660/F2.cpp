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
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] += val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
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
        Tree rt0(3*n);
        Tree rt1(3*n);
        Tree rt2(3*n);
        char a[n];
        rep(i, 0, n) cin >> a[i];

        int numplus = 0;
        int numneg = 0;

        rt0.update(n, 1);

        ll out = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '+') numplus++;
            else numneg++;

            int currmod = (numplus - numneg) % 3;
            if (currmod < 0) currmod += 3;

            int neededdiff = (numplus - numneg) + n;
            if (currmod == 0) out += rt0.query(neededdiff, 3*n);
            else if (currmod == 1) out += rt1.query(neededdiff, 3*n);
            else out += rt2.query(neededdiff, 3*n);



            int diff = (numplus - numneg) + n;
            if (currmod == 0) rt0.update(diff, 1);
            else if (currmod == 1) rt1.update(diff, 1);
            else rt2.update(diff, 1);

            //cout << i << ' ' << out << endl;
        }

        cout << out << '\n';
    }
}