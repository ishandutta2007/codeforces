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
const int INF = (int)2e9;

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_N = 13;
int n;
pii pos[MAX_N * MAX_N];

vector<pii> knight_moves, bishop_moves, rook_moves;

struct DistanceMatrix {
	int d[MAX_N][MAX_N][MAX_N][MAX_N];

	DistanceMatrix() {
		for(int i1 = 0; i1 < MAX_N; ++i1) {
			for(int j1 = 0; j1 < MAX_N; ++j1) {
				for(int i2 = 0; i2 < MAX_N; ++i2) {
					for(int j2 = 0; j2 < MAX_N; ++j2) {
						d[i1][j1][i2][j2] = INF;
					}
				}
			}
		}
	}

	int valid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < n);
	}

	void calc(const vector<pii>& moves) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				d[i][j][i][j] = 0;

				for(auto& m: moves) {
					int i2 = i + m.first;
					int j2 = j + m.second;

					if(valid(i2, j2)) {
						d[i][j][i2][j2] = std::min(d[i][j][i2][j2], 1);
					}
				}
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int i1 = 0; i1 < n; ++i1) {
					for(int j1 = 0; j1 < n; ++j1) {
						if(d[i1][j1][i][j] == INF)
							continue;

						for(int i2 = 0; i2 < n; ++i2) {
							for(int j2 = 0; j2 < n; ++j2) {
								if(d[i][j][i2][j2] == INF)
									continue;

								d[i1][j1][i2][j2] = std::min(d[i1][j1][i2][j2], d[i1][j1][i][j] + d[i][j][i2][j2]);
							}
						}
					}
				}
			}
		}
	}
};

DistanceMatrix dist[4];

const int T_KINGHT = 1;
const int T_BISHOP = 2;
const int T_ROOK   = 3;

void init_chess() {
	for(int i = 1; i <= 2; ++i) {
		int j = 3 - i;

		knight_moves.emplace_back(i, j);
		knight_moves.emplace_back(-i, j);
		knight_moves.emplace_back(i, -j);
		knight_moves.emplace_back(-i, -j);
	}

	for(int i = 1; i < n; ++i) {
		bishop_moves.emplace_back(i, i);
		bishop_moves.emplace_back(-i, i);
		bishop_moves.emplace_back(i, -i);
		bishop_moves.emplace_back(-i, -i);

		rook_moves.emplace_back(0, i);
		rook_moves.emplace_back(0, -i);

		rook_moves.emplace_back(i, 0);
		rook_moves.emplace_back(-i, 0);
	}

	dist[T_KINGHT].calc(knight_moves);
	dist[T_BISHOP].calc(bishop_moves);
	dist[T_ROOK].calc(rook_moves);
}

pii add(const pii& lhs, const pii& rhs) {
	return {lhs.first + rhs.first, lhs.second + rhs.second};
}

pii D[4][MAX_N][MAX_N][4][MAX_N][MAX_N];
pii dp[4][MAX_N * MAX_N];

void solve() {
	cin >> n;
	init_chess();

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int value;
			cin >> value;
			--value;

			pos[value] = {i, j};
		}
	}

	vector<int> types = {T_KINGHT, T_BISHOP, T_ROOK};

	for(int& t1: types) {
		for(int i1 = 0; i1 < n; ++i1) {
			for(int j1 = 0; j1 < n; ++j1) {
				for(auto& t2: types) {
					for(int i2 = 0; i2 < n; ++i2) {
						for(int j2 = 0; j2 < n; ++j2) {
							D[t1][i1][j1][t2][i2][j2] = {INF, INF};
						}
					}
				}
			}
		}
	}

	for(auto& t1: types) {
		for(int i1 = 0; i1 < n; ++i1) {
			for(int j1 = 0; j1 < n; ++j1) {
				//D[t1][i1][j1][t1][i1][j1] = {0, 0};

				for(auto& t2: types) {
					if(t1 != t2)
						D[t1][i1][j1][t2][i1][j1] = {1, 1};
				}

				for(int i2 = 0; i2 < n; ++i2) {
					for(int j2 = 0; j2 < n; ++j2) {
						D[t1][i1][j1][t1][i2][j2] = {dist[t1].d[i1][j1][i2][j2], 0};
					}
				}
			}
		}
	}

	for(auto& t: types) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(auto& t1: types) {
					for(int i1 = 0; i1 < n; ++i1) {
						for(int j1 = 0; j1 < n; ++j1) {
							pii left = D[t1][i1][j1][t][i][j];

							if(left.first == INF || left.second == INF)
								continue;

							for(auto& t2: types) {
								for(int i2 = 0; i2 < n; ++i2) {
									for(int j2 = 0; j2 < n; ++j2) {
										pii right = D[t][i][j][t2][i2][j2];

										if(right.first == INF || right.second == INF)
											continue;

										D[t1][i1][j1][t2][i2][j2] = std::min(D[t1][i1][j1][t2][i2][j2], add(left, right));
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for(int i = 1; i < n * n; ++i) {
		for(int& t: types) {
			dp[t][i] = {INF, INF};
		}
	}

	for(int i = 0; i < n * n - 1; ++i) {
		for(int& t1: types) {
			for(int& t2: types) {
				pii local = dp[t1][i];

				if(local.first == INF || local.second == INF)
					continue;

				pii to_add = D[t1][pos[i].first][pos[i].second][t2][pos[i + 1].first][pos[i + 1].second];

				if(to_add.first == INF || to_add.second == INF)
					continue;

				local = add(local, to_add);
				dp[t2][i + 1] = std::min(dp[t2][i + 1], local);
			}
		}
	}

	pii answ = {INF, INF};

	for(auto& t: types)
		answ = std::min(answ, dp[t][n * n - 1]);

	cout << answ.first << ' ' << answ.second << '\n';
}

int main() {
	init_IO();

	solve();

	return 0;
}