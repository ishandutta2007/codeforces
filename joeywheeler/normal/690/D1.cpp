#include <bits/stdc++.h>
#define fo(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;

int r, c, cur, ans;
char w[123][123];
int main() {
	scanf("%d %d", &r, &c);
	fo(i,0,r) scanf("%s ", w[i]);
	fo(i,0,c) {
		if (w[r-1][i] == 'B' && !cur) {
			cur = 1; ans++;
		}
		if (w[r-1][i] == '.') cur = 0;
	}
	printf("%d\n", ans);

	return 0;
}