#include <bits/stdc++.h>
#define fo(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
#define MOD 1000003LL

int c, w, h;
long long mat[28][123][123], fin[2][123][123], ans;
int main() {
	scanf("%d %d %d", &c, &w, &h);
	fo(i,0,w) mat[0][i][i+1] = h;
	fo(i,0,w+1) mat[0][i][0] = 1;
	fo(i,1,28) {
		fo(ii,0,w+1) fo(jj,0,w+1) {
			fo(kk,0,w+1) mat[i][ii][jj] += mat[i-1][ii][kk]*mat[i-1][kk][jj];
			mat[i][ii][jj] %= MOD;
		}
	}
	fo(i,0,w+1) fin[0][i][i] = 1;
	fo(i,0,28) if (c & (1<<i)) {
		fo(ii,0,w+1) fo(jj,0,w+1) {
			fin[1][ii][jj] = 0;
			fo(kk,0,w+1) fin[1][ii][jj] += fin[0][ii][kk]*mat[i][kk][jj];
			fin[1][ii][jj] %= MOD;
		}
		swap(fin[0], fin[1]);
	}
	fo(i,0,w+1) ans += fin[0][0][i];
	printf("%d\n", ans%MOD);

	return 0;
}