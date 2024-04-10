#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<string> plan;
int n, m, k;

vector< vector<pii> > from;

int sx, sy, fx, fy;

const string INFS(2500, 'z' + 1);
vector<char> u(26, 0);

const int MXY[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

string GetShortestPath(const char* moves) {
	from.assign(n, vector<pii>(m, pii(-1, -1)));
	vector< vector<pii> > curq;
	vector< vector<pii> > nq;
	curq.resize(1);
	curq[0].push_back(pii(sx, sy));
	while (!curq.empty()) {
		nq.clear();
		for (int i = 0; i < (int)curq.size(); i++) {
			if (curq[i].empty())
				continue;
			int off = (int)nq.size();
			nq.resize(off + k);
			for (int j = 0; j < (int)curq[i].size(); j++) {
				int cx = curq[i][j].first;
				int cy = curq[i][j].second;
				for (int mv = 0; mv < 4; mv++) {
					int nx = cx + MXY[mv][0];
					int ny = cy + MXY[mv][1];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m || from[nx][ny] != pii(-1, -1))
						continue;
					char ch = plan[nx][ny];
					if (ch == 'T') {
						from[nx][ny] = pii(cx, cy);
						continue;
					}
					if (ch == 'S' || !u[ch - 'a'])
						continue;
					from[nx][ny] = pii(cx, cy);
					for (int l = 0; l < k; l++) {
						if (plan[nx][ny] == moves[l]) {
							nq[off + l].push_back(pii(nx, ny));
						}
					}
				}
			}
		}
		nq.swap(curq);
	}
	if (from[fx][fy] == pii(-1, -1))
		return INFS;
	vector<char> res;
	for (int x = fx, y = fy; x != sx || y != sy; ) {
		res.push_back(plan[x][y]);
		pii nxy = from[x][y];
		x = nxy.first;
		y = nxy.second;
	}
	reverse(res.begin(), res.end());
	res.back() = char(0);
	return string(&res[0]);
}

int main(void) {
	cin >> n >> m >> k;
	plan.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> plan[i];
		for (int j = 0; j < m; j++) {
			if (plan[i][j] == 'S') {
				sx = i; sy = j;
			} else if (plan[i][j] == 'T') {
				fx = i; fy = j;
			}
		}
	}
	string res = INFS;
	for (int i = 0; i < k; i++)
		u[i] = 1;
	sort(u.begin(), u.end());
	do {
		char moves[4];
		for (int i = 0, j = 0; i < 26; i++) {
			if (u[i])
				moves[j++] = char(i + 'a');
		}
		string cand = GetShortestPath(moves);
		if (cand.length() < res.length())
			res = cand;
		else if (cand.length() == res.length() && cand < res)
			res = cand;
	} while (next_permutation(u.begin(), u.end()));
	if (res != INFS)
		cout << res << endl;
	else cout << -1 << endl;
	return 0;
}