#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m;

int x[100005], y[100005], xy;

void ispravi_h(vector<pair<int, int>>& ret, vector<string>& s, int x, int y) {
	if (s[x][y] == 'L' && s[x][y+1] == 'R') {
		return;
	}
	// inace je U
	if (s[x][y+1] == 'L') {
		ispravi_h(ret, s, x+1, y+1);
		ret.push_back({x, y+1});
		ret.push_back({x, y});
		s[x][y] = 'L';
		s[x+1][y] = 'L';
		s[x][y+1] = 'R';
		s[x+1][y+1] = 'R';
		s[x][y+2] = 'U';
		s[x+1][y+2] = 'D';
		return;
	} else {
		ret.push_back({x, y});
		s[x][y] = 'L';
		s[x+1][y] = 'L';
		s[x][y+1] = 'R';
		s[x+1][y+1] = 'R';
		return;
	}
}

char flip(char x) {
	switch(x) {
		case 'U': return 'L';
		case 'L': return 'U';
		case 'D': return 'R';
		case 'R': return 'D';
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	vector<string> st(n), en(n);
	bool transpose = m % 2;

	for (int i=0; i<n; i++) {
		cin >> st[i];
	}
	for (int i=0; i<n; i++) {
		cin >> en[i];
	}

	typedef vector<pair<int, int>> sol_t;

	sol_t r1, r2;

	if (transpose) {
		vector<string> stt(m, string(n, 0)), ent(m, string(n, 0));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				stt[j][i] = flip(st[i][j]);
				ent[j][i] = flip(en[i][j]);
			}
		}

		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j+=2) {

				/*
				cerr << "~~~~\n";
				for (int i=0; i<m; i++) {
					cerr << stt[i] << '\n';
				}
				*/

				ispravi_h(r1, stt, i, j);
				ispravi_h(r2, ent, i, j);

			}
		}

		for (auto it=r2.rbegin(); it!=r2.rend(); ++it) {
			r1.push_back(*it);
		}

		for (auto& p : r1) {
			swap(p.first, p.second);
		}

	} else {

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j+=2) {
				ispravi_h(r1, st, i, j);
				ispravi_h(r2, en, i, j);
			}
		}

		for (auto it=r2.rbegin(); it!=r2.rend(); ++it) {
			r1.push_back(*it);
		}
	}

	cout << r1.size() << '\n';
	for (auto p : r1) {
		cout << p.first+1 << ' ' << p.second+1 << '\n';
	}
}