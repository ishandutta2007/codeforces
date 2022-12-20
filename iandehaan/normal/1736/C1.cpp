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
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
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
        Tree rt(n);
        rep(i, 0, n) {
            int x;
            cin >> x;
            rt.update(i, x-i);
        }

        ll out = 0;

        rep(i, 0, n) {
            int threshold = -1*i;
            int lo = i-1;
            int hi = n;
            while (hi-lo > 1) {
                int mid = (hi+lo)/2;

                int ret = rt.query(i, mid+1);
                //cout << "trying " << mid << ' ' << ret << endl;
                if (ret > threshold) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            //cout << i << ' ' << lo << endl;
            out += lo-i+1;
        }

        cout << out << '\n';
    }
}