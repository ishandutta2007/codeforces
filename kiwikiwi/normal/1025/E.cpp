#include <bits/stdc++.h>
using namespace std;

const int N = 56;
struct cube {
	int x, y, id;
} p1[N], p2[N];
int n, m;
vector<vector<int>> ans1, ans2;

void solve(vector<vector<int>> &ans, cube *p) {
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
		--p[i].x;
		--p[i].y;
		p[i].id = i;
	}
	sort(p, p + m, [&](const cube & a, const cube & b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});
	while (1) {
		bool move = 0;
		for (int i = 0; i < m; i++) {
			if (p[i].x > i) {
				ans.push_back(vector<int> {p[i].x, p[i].y, p[i].x - 1, p[i].y});
				p[i].x -= 1;
				move = 1;
			}
		}

		for (int i = m - 1; i >= 0; i--) {
			if (p[i].x < i) {
				ans.push_back(vector<int> {p[i].x, p[i].y, p[i].x + 1, p[i].y});
				p[i].x += 1;
				move = 1;
			}
		}
		if (!move) break;
	}
	for (int i = 0; i < m; i++) {
		while (p[i].y < p[i].id) {
			ans.push_back(vector<int> {p[i].x, p[i].y, p[i].x, p[i].y + 1});
			p[i].y++;
		}

		while (p[i].y > p[i].id) {
			ans.push_back(vector<int> {p[i].x, p[i].y, p[i].x, p[i].y - 1});
			p[i].y--;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	solve(ans1, p1);
	solve(ans2, p2);
	auto cmp = [&](const cube & a, const cube & b) {
		return a.id < b.id;
	};
	sort(p1, p1 + m, cmp);
	sort(p2, p2 + m, cmp);
	for (int i = 0; i < m; i++) {
		while (p1[i].x < p2[i].x) {
			ans1.push_back(vector<int> {p1[i].x, p1[i].y, p1[i].x + 1, p1[i].y});
			p1[i].x++;
		}
		while (p1[i].x > p2[i].x) {
			ans1.push_back(vector<int> {p1[i].x, p1[i].y, p1[i].x - 1, p1[i].y});
			p1[i].x--;
		}
	}
	reverse(ans2.begin(), ans2.end());
	for (auto p : ans2) {
		ans1.push_back(vector<int> {p[2], p[3], p[0], p[1]});
	}
	printf("%d\n", (int)ans1.size());
	for (auto p : ans1) {
		printf("%d %d %d %d\n", p[0] + 1, p[1] + 1, p[2] + 1, p[3] + 1);
	}
}