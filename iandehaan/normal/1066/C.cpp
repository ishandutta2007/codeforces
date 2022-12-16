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

	int q;
	cin >> q;
	vi lft, rt;
	map<int, pair<char, int>> pos;
	while (q--) {
		
		char cmd;
		cin >> cmd;
		int id;
		cin >> id;
		
		if (cmd == 'L') {
			lft.pb(id);
			pos[id] = mp('L', sz(lft)-1);
		} else if (cmd == 'R') {
			rt.pb(id);
			pos[id] = mp('R', sz(rt)-1);
		} else {
			pair<char, int> posinfo = pos[id];

			if (posinfo.first == 'R') {
				int pos1 = sz(rt) - posinfo.second-1;
				int pos2 = sz(lft) + posinfo.second;
				cout << min(pos1, pos2) << endl;
			} else {
				int pos1 = sz(rt) + posinfo.second;
				int pos2 = sz(lft) - posinfo.second-1;
				//cout << sz(rt) << ' ' << posinfo.second << endl;
				cout << min(pos1, pos2) << endl;
			}
		}
	}
}