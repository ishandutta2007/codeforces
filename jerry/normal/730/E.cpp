#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

bool cross (int a, int b, int c, int i, int j) {
	bool bef = c > a || (c==a&&j<i);
	bool aft = c > b || (c==b&&j<i);
	return bef + aft == 1;
}

int N, x[110], y[110], c[110][110], ans;
vector<int> adj[110];
bool seen[110];

void go (int i) {
	seen[i] = 1;
	for (int j : adj[i]) {
		if (seen[j]) {
			puts("FAIL");
			exit(0);
		} else go(j);
	}
}

int main () {
	scanf("%d", &N);

	fo(i, 0, N) {
		scanf("%d %d", &x[i], &y[i]);
		fo(j, 0, i) {
			if (cross(x[i], x[i]+y[i], x[j], i, j)) c[i][j]++;//, printf("i crosses old j\n");
			if (cross(x[j], x[j]+y[j], x[i]+y[i], j, i)) c[i][j]++;//, printf("j crosses new i\n");

			if (cross(x[j], x[j]+y[j], x[i], j, i)) c[j][i]++;//, printf("j crosses old i\n");
			if (cross(x[i], x[i]+y[i], x[j]+y[j], i, j)) c[j][i]++;//, printf("i crosses new j\n");

			while (c[i][j] && c[j][i]) ans++, c[i][j]--, c[j][i]--;
			ans += c[i][j] + c[j][i];
		}
	}
	fo(i, 0, N) if (!seen[i]) go(i);

	printf("%d\n", ans);
	return 0;
}