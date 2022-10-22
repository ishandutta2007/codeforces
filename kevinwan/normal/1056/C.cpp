#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ch[2001];
int p[2001];
int ot[2001];
int r[2001];
int n, m, a, b, t;
int get() {
	int op = -1,bes=0;
	for (int i = 1; i <= 2 * n; i++) {
		if (ch[i])continue;
		if (r[i] > op)bes = i, op = r[i];
	}
	return bes;
}
void disp(int x) {
	cout << x << endl;
	ch[x] = 1;
}
int main() {
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= 2 * n; i++)scanf("%d", p + i);
	for (i = 0; i < m; i++)scanf("%d%d", &a, &b),ot[a]=b,ot[b]=a;
	for (i = 1; i <= 2 * n; i++)r[i] = p[i] + (ot[i] == 0 ? 0 : 10000);
	scanf("%d", &t);
	if (t == 2) {
		scanf("%d", &a);
		ch[a] = 1;
	}
	else a = 0;
	ch[0] = 1;
	for (i = 0; i < n; i++) {
		if (ch[ot[a]] == 0) {
			disp(ot[a]);
		}
		else {
			int me = get();
			disp(get());
		}
		if (i == n - 1 && t == 2)break;
		scanf("%d", &a);
		ch[a] = 1;
	}
	getchar(); getchar();
}