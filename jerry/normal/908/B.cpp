#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

char buf[64][64], s[250];
int ord[5] = {0, 1, 2, 3};
int r, c, ans;

bool inb(int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; }

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++) scanf("%s", buf[i]);
	scanf("%s", s);
	do
	{
		int x = 0, y = 0;
		for (int i = 0;i < r;i++) for (int j = 0;j < c;j++) if (buf[i][j] == 'S') x = i, y = j;
		for (int i = 0;s[i] && inb(x, y) && buf[x][y] != '#' && buf[x][y] != 'E';i++) x += dx[ord[s[i]-'0']], y += dy[ord[s[i]-'0']];
		if (inb(x, y) && buf[x][y] == 'E') ans++;
	} while (next_permutation(ord, ord+4));
	printf("%d\n", ans);
	return 0;
}