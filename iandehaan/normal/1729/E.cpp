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


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	srand(time(NULL));


	rep(i, 2, 27) {
		cout << "? 1 " << i << endl;
		ll a1;
		cin >> a1;
		cout << "? " << i << " 1" << endl;
		ll a2;
		cin >> a2;
		if (a2 == -1) {
			cout << "! " << i-1 << endl;
			return 0;
		}
		if (a1 != a2) {
			cout << "! " << a1 + a2 << endl;
			return 0;
		}
	}
}