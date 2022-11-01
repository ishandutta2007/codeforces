#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
#endif

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::swap;
using std::sort;
using std::lower_bound;
using std::unique;

using int64 = long long int;
using pii   = pair<int, int>;
using pii64 = pair<int64, int64>;

const int NIL = -1;

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_N = 1007;

char M[MAX_N][MAX_N];
int H, W;

void solve() {
	cin >> H >> W;

	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) {
			M[i][j] = '?';
		}
	}

	for(int i = 0; i < H; ++i) {
		int cnt;
		cin >> cnt;

		for(int j = 0; j < cnt; ++j) {
			M[i][j] = 'B';
		}

		if(cnt < W) {
			M[i][cnt] = 'W';
		}
	}

	for(int j = 0; j < W; ++j) {
		int cnt;
		cin >> cnt;

		for(int i = 0; i < cnt; ++i) {
			if(M[i][j] == 'W') {
				cout << "0\n";
				return;
			}

			M[i][j] = 'B';
		}

		if(cnt < H) {
			if(M[cnt][j] == 'B') {
				cout << "0\n";
				return;
			}

			M[cnt][j] = 'W';
		}
	}

	const int MOD = (int)1e9 + 7;
	int answ = 1;

	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) {
			if(M[i][j] == '?') {
				answ += answ;

				if(answ >= MOD)
					answ -= MOD;
			}
		}
	}

	cout << answ << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}