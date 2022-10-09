#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <queue>
using namespace std;

int n;
int winner[7005][3];
vector<int> s[3];
int k[3];

int options[7005][3];

queue<pair<int, int>> q;

inline int yy(int x, int potez) {
	int y = x - potez;
	if (y < 0) {
		y += n;
	}
	return y;
}

void mark(int x, int g) {
	int w = winner[x][g];

	if (g != w) {
		for (int potez : s[w]) {
			int y = yy(x, potez);
			if (winner[y][w] == 0) {
				winner[y][w] = w;
				q.push({y, w});
			}			
		}
	} else {
		int o = 3-g;
		for (int potez : s[o]) {
			int y = yy(x, potez);

			if (++options[y][o] == k[o]) {
				winner[y][o] = g;
				q.push({y, o});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	cin >> k[1];

	for (int i=0; i<k[1]; i++) {
		int x;
		cin >> x;
		s[1].push_back(x);
	}

	cin >> k[2];
	for (int i=0; i<k[2]; i++) {
		int x;
		cin >> x;
		s[2].push_back(x);
	}

	winner[0][1] = 2;
	winner[0][2] = 1;

	q.push({0, 1});
	q.push({0, 2});

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		mark(p.first, p.second);
	}
	

	for (int i=1; i<n; i++) {
		if (winner[i][1] == 1) {
			cout << "Win ";
		} else if (winner[i][1] == 2) {
			cout << "Lose ";
		} else {
			cout << "Loop ";
		}
	}
	cout << '\n';

	for (int i=1; i<n; i++) {
		if (winner[i][2] == 2) {
			cout << "Win ";
		} else if (winner[i][2] == 1) {
			cout << "Lose ";
		} else {
			cout << "Loop ";
		}
	}
	cout << '\n';
}