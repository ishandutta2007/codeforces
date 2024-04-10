#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> u[100005];
vector<int> v[100005];
int l[100005];

bool go(int i, int p) {
	if (sz(u[i]) == 2) l[i] = l[p];
	else l[i] = i;
	if (sz(u[i]) == 1) {
		//printf("%d->%d\n", l[p], i);
		v[l[p]].push_back(i);
		v[i].push_back(l[p]);
	}
	bool add = sz(u[i]) > 2;
	for (int x : u[i]) if (x != p) {
		add |= go(x,i);
	}
	if (add && p) {
		l[i] = i;
		v[p].push_back(i);
		v[i].push_back(p);
	}

	return add;
}

bool negligible(int i, int p) {
	if (sz(v[i])-1 > 2) return false;
	for (int x : v[i]) if (x != p && sz(v[x])>1) return false;
	return true;
}

int numnnegc(int i) {
	int res = 0;
	for (int x : v[i]) res += !negligible(x,i);
	return res;
}

int main() {
	scanf("%d", &n);
	FO(i,0,n-1) {
		int a, b; scanf("%d%d", &a, &b);
		u[a].push_back(b);
		u[b].push_back(a);
	}
	int r = -1;
	FO(i,1,n+1) if (sz(u[i]) >= 3) r = i;
	if (r == -1) {
		printf("Yes\n");
		return 0;
	}
	go(r,0);
	int nr = -1;
	FO(i,1,n+1) nr = max(nr, numnnegc(i));
	if (nr > 2) printf("No\n");
	else printf("Yes\n");
}