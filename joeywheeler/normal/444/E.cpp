#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<pair<int,int> > u[3005];
int x[3005], s[3005];
int V;

int go(int i) {
	int r = x[i]+1; s[i] = 1;
	for (auto j : u[i]) if (!s[j.first] && j.second < V) r += go(j.first);
	return r;
}

bool can(int v) {
	V = v;
	int sx = 0;
	FO(i,0,n) sx += x[i], s[i] = 0;;
	FO(i,0,n) if (!s[i]) if (go(i) > sx) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	FO(i,0,n-1) {
		int a,b,c; scanf("%d%d%d", &a, &b, &c); a--; b--;
		u[a].emplace_back(b,c);
		u[b].emplace_back(a,c);
	}
	FO(i,0,n) scanf("%d", x+i);
	int s = 0, e = 10005, b = 0;
	while (s <= e) {
		int m = (s+e)/2;
		if (can(m)) b = m, s = m+1;
		else e = m-1;
	}
	printf("%d\n", b);
}