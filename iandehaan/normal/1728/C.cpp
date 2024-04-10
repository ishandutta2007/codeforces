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

int dlog(int x) {
	//cout << "log of " << x << endl;
	ll ten = 1;
	int out = 0;
	while (ten <= x) {
		ten *= 10;
		out++;
	}
	return out;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	//cout << dlog(99999999) << endl;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		multiset<int> a;
		multiset<int> b;
		rep(i, 0, n) {
			int x;
			cin >> x;
			a.insert(x);
		}
		rep(i, 0, n) {
			int x;
			cin >> x;
			b.insert(x);
		}
		
		int out = 0;
		while (!a.empty()) {
			int abig = *a.rbegin();
			int bbig = *b.rbegin();
			//cout << abig << ' ' << bbig << endl;

			if (abig == bbig) {
				// great!
				a.erase(prev(a.end()));
				b.erase(prev(b.end()));
			} else if (abig > bbig) {
				a.erase(prev(a.end()));
				a.insert(dlog(abig));
				out++;
			} else {
				b.erase(prev(b.end()));
				b.insert(dlog(bbig));
				out++;
			}
		}
		cout << out << '\n';
	}
}