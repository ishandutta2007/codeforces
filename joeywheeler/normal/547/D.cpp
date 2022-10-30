#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

set<int> u[400005], v[400005];
int n;

void go(int i) {
	while (sz(u[i])) {
		int j = *u[i].begin();
		u[i].erase(j); u[j].erase(i);
		v[j].insert(i); go(j);
	}
}

int main() {
	scanf("%d", &n);
	FO(i,0,n) {
		int x, y; scanf("%d%d", &x, &y);
		u[x].insert(200000+y);
		u[200000+y].insert(x);
	}
	FO(i,0,400005) if (sz(u[i])&1) {
		u[0].insert(i);
		u[i].insert(0);
	}
	FO(i,0,400005) if (sz(u[i])) go(i);
	rewind(stdin);
	scanf("%d", &n);
	FO(i,0,n) {
		int x, y; scanf("%d%d", &x, &y);
		if (v[x].count(200000+y)) putchar('b');
		else putchar('r');
	}
	putchar('\n');
}