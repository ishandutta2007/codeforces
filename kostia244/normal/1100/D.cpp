#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

int kx, ky, k, px, py;
int pos[700][2];
int board[1010][1010] = { { 0, } }, s[2][2] = { { 0, } };

void go(int x, int y) {
	while (kx != x || ky != y) {
		if (kx < x && !board[kx + 1][ky])
			++kx;
		if (kx > x && !board[kx - 1][ky])
			--kx;
		if (ky < y && !board[kx][ky + 1])
			++ky;
		if (ky > y && !board[kx][ky - 1])
			--ky;
		cout << kx << " " << ky << "\n";
		cout.flush();

		cin >> k >> px >> py;
		if (k < 0)
			exit(0);
		if (k == 0)
			exit(-100);
		board[pos[k][0]][pos[k][1]] = 0;
		pos[k][0] = px, pos[k][1] = py;
		board[pos[k][0]][pos[k][1]] = 1;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> kx >> ky;
	for (int i = 1; i <= 666; i++)
		cin >> pos[i][0] >> pos[i][1], board[pos[i][0]][pos[i][1]] = 1;
	go(1, 1);
	go(500, 500);
	for (int i = 1; i <= 999; i++)
		for (int j = 1; j <= 999; j++)
			if (board[i][j]) {
				s[i / 500][j / 500]++;
				s[i / 500][((j / 500) + 1) & 1]++;
				s[((i / 500) + 1) & 1][j / 500]++;
			}
	int mx = max( { s[0][0], s[0][1], s[1][0], s[1][1] });
	if (s[0][0] == mx) {
		mx = 1;
		go(1, 1);
	} else if (s[0][1] == mx) {
		mx = 2;
		go(1, 999);
	} else if (s[0][1] == mx) {
		mx = 3;
		go(999, 1);
	} else {
		mx = 4;
		go(999, 999);
	}
	go(499, 499);
	for (int i = 1; i <= 999; i++)
		for (int j = 1; j <= 999; j++)
			if (board[i][j]) {
				s[i / 500][j / 500]++;
				s[i / 500][((j / 500) + 1) & 1]++;
				s[((i / 500) + 1) & 1][j / 500]++;
			}
	mx = max( { s[0][0], s[0][1], s[1][0], s[1][1] });
	if (s[0][0] == mx) {
		mx = 1;
		go(1, 1);
	} else if (s[0][1] == mx) {
		mx = 2;
		go(1, 999);
	} else if (s[0][1] == mx) {
		mx = 3;
		go(999, 1);
	} else {
		mx = 4;
		go(499, 499);
		go(999, 999);
	}
	return mx;
}