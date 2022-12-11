#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<char> muted(n, false);
	int mutedR = 0, mutedD = 0;
	int pos = 0;
	int cntR = 0, cntD = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			++cntR;
		} else {
			++cntD;
		}
	}
	while (cntR && cntD) {
		if (muted[pos]) {
			++pos;
			if (pos == n) {
				pos = 0;
			}
			continue;
		}
		if (s[pos] == 'R' && mutedR) {
			muted[pos] = true;
			--cntR;
			--mutedR;
			++pos;
			if (pos == n) {
				pos = 0;
			}
			continue;
		}
		if (s[pos] == 'D' && mutedD) {
			muted[pos] = true;
			--cntD;
			--mutedD;
			++pos;
			if (pos == n) {
				pos = 0;
			}
			continue;
		}
		if (s[pos] == 'D') {
			++mutedR;
		} else {
			++mutedD;
		}
		++pos;
		if (pos == n) {
			pos = 0;
		}
	}

	cout << (cntR ? "R\n" : "D\n");

}