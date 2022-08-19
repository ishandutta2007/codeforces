#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 251000

int a[maxN], sfmn[maxN], sfmx[maxN], prmn[maxN], prmx[maxN], pos[maxN];
int n, m, k;

int calc() {
	sfmn[n] = sfmx[n] = a[n];
	prmn[1] = prmx[1] = a[1];
	for (int i = n - 1; i >= 1; i--) {
		sfmn[i] = min(sfmn[i + 1], a[i]);
		sfmx[i] = max(sfmx[i + 1], a[i]);
	}
	for (int i = 2; i <= n; i++) {
		prmn[i] = min(prmn[i - 1], a[i]);
		prmx[i] = max(prmx[i - 1], a[i]);
	}
	int p = pos[1], cnt = 1;
	while (p != n) {
		if (a[p] == sfmx[p]) p = pos[sfmn[p]], cnt++;
		else p = pos[sfmx[p]], cnt++;
	}
	p = pos[n];
	while (p != 1) {
		if (a[p] == prmx[p]) p = pos[prmn[p]], cnt++;
		else p = pos[prmx[p]], cnt++;
	}
	return cnt;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	if (n == 1) {
		puts("0");
		return;
	}
	if (pos[1] < pos[n]) {
		for (int i = 1; i <= n; i++) {
			a[i] = n + 1 - a[i];
			pos[a[i]] = i;
		}
	}
	printf("%d\n", calc());
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}