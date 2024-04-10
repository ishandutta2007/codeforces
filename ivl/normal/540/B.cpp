#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define FOR(a, b, c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)

using namespace std;

void imp(){printf("-1\n"); exit(0);}

int n, k, p, x, y;
int a[1005];

int main(){
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	FOR(0, k, i) scanf("%d", a + i);
	int Cnt = 0;
	FOR(0, k, i) if (a[i] < y) ++Cnt;
	if (Cnt > n / 2) imp();
	Cnt = n / 2 - Cnt; //printf(" - %d\n", Cnt);
	FOR(0, n - k, i) if (i < Cnt) a[k + i] = 1; else a[k + i] = y;
	int Sum = 0;
	FOR(0, n, i) Sum += a[i];
	if (Sum > x) imp();
	FOR(k, n, i) printf("%d ", a[i]); printf("\n");
	return 0;
}