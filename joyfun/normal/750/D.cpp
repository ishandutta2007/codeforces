#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 35;
const int dir[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
int n, t[N];

struct Node {
	int x, y, d, id;
	Node() {}
	Node(int x, int y, int d, int id) : x(x), y(y), d(d), id(id) {}
};

queue<Node> Q;
int vis[305][305][10][31], vi[305][305];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &t[i]);
	Q.push(Node(150, 150, 0, 0));
	while (!Q.empty()) {
		Node u = Q.front(); Q.pop();
	//	printf("%d %d\n", u.x, u.y);
		if (u.id == n) continue;
		int x = u.x, y = u.y;
		for (int j = 0; j < t[u.id]; j++) {
			x += dir[u.d][0];
			y += dir[u.d][1];
			vi[x][y] = 1;
		}
		for (int i = -1; i <= 1; i++) {
			if (i == 0) continue;
			int d = (u.d + i + 8) % 8;
			if (vis[x][y][d][u.id + 1]) continue;
			vis[x][y][d][u.id + 1] = 1;
			Q.push(Node(x, y, d, u.id + 1));
		}
	}
	int ans = 0;
	for (int i = 0; i < 305; i++)
		for (int j = 0; j < 305; j++)
			ans += vi[i][j];
	printf("%d\n", ans);
	return 0;
}