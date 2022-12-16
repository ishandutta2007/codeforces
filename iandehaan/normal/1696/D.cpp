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

struct Treemax {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Treemax(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

struct Treemin {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Treemin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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
        int a[n];
        pii entries[n];
        pii next[n];
        int posmap[n+1];
        Treemax rtmax(n);
        Treemin rtmin(n);
        rep(i, 0, n) {
            cin >> a[i];
            entries[i] = mp(a[i], i);
            rtmax.update(i, a[i]);
            rtmin.update(i, a[i]);
            posmap[a[i]] = i;
        }
        sort(entries, entries+n);
        // process in increasing order
        set<int> seen;
        rep(i, 0, n) {
            auto iter = seen.lower_bound(entries[i].second);
            if (iter == end(seen)) {
                next[entries[i].second].first = 1e9;
            } else {
                next[entries[i].second].first = *iter;
            }

            seen.insert(entries[i].second);
        }

        // now in decreasing order
        rep(i, 0, n) {
            entries[i] = mp(-1*a[i], i);
        }
        sort(entries, entries+n);
        // process in decr order
        seen.clear();
        rep(i, 0, n) {
            auto iter = seen.lower_bound(entries[i].second);
            if (iter == end(seen)) {
                next[entries[i].second].second = 1e9;
            } else {
                next[entries[i].second].second = *iter;
            }

            seen.insert(entries[i].second);
        }

        int pos = 0;
        int out = 0;
        while (pos != n-1) {
            
            out++;
            int boundary = max(next[pos].first, next[pos].second);
            boundary = min(boundary, n-1);
            //cout << pos << ' ' << boundary << endl;

            if (next[pos].first < next[pos].second) {
                // encounter max last
                // so go to min up to boundary

                int jumpval = rtmin.query(pos+1, boundary+1);
                pos = posmap[jumpval];
            } else {
                int jumpval = rtmax.query(pos+1, boundary+1);
                pos = posmap[jumpval];
            }
        }

        cout << out << '\n';

        
    }
}