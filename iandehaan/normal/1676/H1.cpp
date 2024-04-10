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

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
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
        FT rt(n);
        ll out = 0;
        pair<int, int> a[n];
        rep(i, 0, n) {
            cin >> a[i].first;
            a[i].second = -1*i;
        }
        sort(a, a+n); reverse(a, a+n);
        for (int i = 0; i < n; i++) {
            int ind = -1*a[i].second;
            //nt dest = a[i].first;
            int numbefore = rt.query(ind);
            out += numbefore;
            rt.update(ind, 1);
        }
        cout << out << '\n';
    }    
}