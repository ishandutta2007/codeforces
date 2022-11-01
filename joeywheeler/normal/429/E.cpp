#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[300005], r[300005], t[300005], n, m;
int u[200005], us;
int a[200005];
set<int> v[200005];

void go(int i) {
	while (sz(v[i])) {
		int x = *v[i].begin();
		int o = l[x]^r[x]^i;
		v[i].erase(x);
		v[o].erase(x);
		if (o < i) t[x] = 1;
		go(o);
	}
}

int main() {
	scanf("%d", &n); m = n;
	FO(i,0,n) {
		scanf("%d%d", l+i, r+i);
		u[us++] = l[i];
		u[us++] = ++r[i];
	}
	sort(u,u+us);
	us = unique(u,u+us)-u;
	FO(i,0,n) {
		l[i] = lower_bound(u,u+us,l[i])-u;
		r[i] = lower_bound(u,u+us,r[i])-u;
		a[l[i]]++;
		a[r[i]]--;
	}
	FO(i,1,us) a[i] += a[i-1];
	FO(i,0,us) if (a[i]%2) {
		l[n] = i; r[n] = i+1;
		n++;
	}
	FO(i,0,n) v[l[i]].insert(i), v[r[i]].insert(i);
	FO(i,0,us) go(i);
	FO(i,0,m) printf("%d%c", t[i], " \n"[i+1==m]);
}