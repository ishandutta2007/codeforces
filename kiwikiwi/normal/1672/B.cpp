#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

char s[maxN];
void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int cntB = 0, hasB = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'B') cntB++, hasB = 1;
		else if (s[i] == 'A') {
			if (!hasB) {
				puts("NO");
				return;
			}
			if (cntB > 0) --cntB;
		}
	}
	if (cntB > 0) puts("NO");
	else puts("YES");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}