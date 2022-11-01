#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define FOR(a, b, c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)

using namespace std;

void imp(){printf("NO\n"); exit(0);}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char in[505][505];
int r1, c1;
int r2, c2;

bool bio[505][505];
void DFS(int a, int b){
	if (a < 1 || b < 1 || a > n || b > m) return;
	if (bio[a][b]++) return;
	FOR(0, 4, i) if (in[a + dx[i]][b + dy[i]] == '.') DFS(a + dx[i], b + dy[i]);
}

int main(){
	scanf("%d%d", &n, &m);
	FOR(1, n + 1, i) scanf("%s", in[i] + 1);
	scanf("%d%d", &r1, &c1), in[r1][c1] = '.';
	scanf("%d%d", &r2, &c2);
	if (r1 == r2 && c1 == c2){
		int Cnt = 0;
		FOR(0, 4, i) if (in[r2 + dx[i]][c2 + dy[i]] == '.') ++Cnt;
		if (Cnt < 1) imp();
		printf("YES\n");
		return 0;
	}
	if (in[r2][c2] == '.'){
		int Cnt = 0;
		FOR(0, 4, i) if (in[r2 + dx[i]][c2 + dy[i]] == '.') ++Cnt;
		if (Cnt < 2) imp();
	} else in[r2][c2] = '.';
	DFS(r1, c1);
	if (!bio[r2][c2]) imp();
	printf("YES\n");
	return 0;
}