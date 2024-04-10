#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[200005], c[200005];
int n, m, q, p[18][200005], l[200005], lo[200005], id[200005], T, d[200005];
long long s[200005];

int gl(int i) {
	return i==l[i]?i:gl(l[i]);
}

void go(int i, int pr) {
	int opr = pr;
	lo[i] = id[i] = ++T;
	for (int x : u[i]) {
		if (x == pr) pr = -1;
		else {
			if (id[x]) lo[i] = min(lo[i],id[x]);
			else {
				go(x,i);
				lo[i] = min(lo[i], lo[x]);
			}
		}
	}
	if (lo[i] != id[i] && opr) l[gl(i)] = gl(opr);
}

void go2(int i, int pr) {
	T++;
	for (int x : u[i]) if (id[x] == T+1) go2(x,i);
	if (lo[i] == id[i]) {
		p[0][gl(i)] = gl(pr);
		c[gl(pr)].push_back(gl(i));
	}
}

void go3(int i) {
	for (int x : c[i]) {
		d[x] = d[i]+1;
		go3(x);
	}
}

void go4(int i) {
	for (int x : c[i]) {
		go4(x);
		s[i] += s[x];
	}
	if (s[i] >= 1000000 && s[i] % 1000000) {
		printf("No\n");
		exit(0);
	}
}

int lca(int i, int j) {
	if (d[i] < d[j]) swap(i,j);
	for (int t = 17; t >= 0; t--) if (d[i]-(1<<t) >= d[j]) i = p[t][i];
	if (i == j) return i;
	for (int t = 17; t >= 0; t--) if (p[t][i] != p[t][j]) {
		i = p[t][i];
		j = p[t][j];
	}
	return p[0][i];
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	FO(i,0,m) {
		int x,v; scanf("%d%d", &x, &v);
		u[x].push_back(v); u[v].push_back(x);
	}
	FO(i,1,n+1) l[i] = i;
	FO(i,1,n+1) if (!id[i]) go(i,0);

	T = 0;
	FO(i,1,n+1) if (id[i] == T+1) go2(i,0);

	FO(i,1,18) FO(j,1,n+1) p[i][j] = p[i-1][p[i-1][j]];
	go3(0);

	FO(i,0,q) {
		int x, y; scanf("%d%d", &x, &y);
		x = gl(x); y = gl(y);
		int lc = lca(x,y);
        if (lc == 0) {
            printf("No\n");
            return 0;
        }
		s[x] += 1;
		s[lc] -= 1000001;
		s[y] += 1000000;
	}
	go4(0);
	printf("Yes\n");
}