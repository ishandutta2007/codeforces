#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll f[10005], d[10005];
vector<int> u[10005];
int a[20005], b[20005];
ll l[20005], r[20005];
bool p[10005];
int n, m;
int sw, st, e;

// from us using l
void cf() {
	FO(i,1,n+1) p[i] = false, f[i] = 1e15;
	priority_queue<pair<ll,int>> q;
	f[sw] = 0;
	q.emplace(0,sw);
	while (!q.empty()) {
		ll d; int i; tie(d,i) = q.top(); q.pop();
		if (p[i]) continue;
		p[i] = true; d *= -1;
		for (int ed : u[i]) {
			int j = a[ed]^b[ed]^i;
			ll nd = d + l[ed];
			if (nd < f[j]) {
				f[j] = nd;
				q.emplace(-nd,j);
			}
		}
	}
}

// from them using r
void cd() {
	FO(i,1,n+1) p[i] = false, d[i] = 1e15;
	priority_queue<pair<ll,int>> q;
	d[st] = 0;
	q.emplace(0,st);
	while (!q.empty()) {
		ll D; int i; tie(D,i) = q.top(); q.pop();
		if (p[i]) continue;
		p[i] = true; D *= -1;
		for (int ed : u[i]) {
			int j = a[ed]^b[ed]^i;
			ll nd = D + r[ed];
			if (nd < d[j]) {
				d[j] = nd;
				q.emplace(-nd,j);
			}
		}
	}
}

vector<int> pa;

bool canwin(int i) {
	if (f[i] >= d[i]) return false;
	if (p[i]) return false;
	p[i] = true;
	pa.push_back(i);
	if (i == e) return true;
	for (int ed : u[i]) {
		int j = a[ed]^b[ed]^i;
		if (canwin(j)) return true;
	}
	pa.pop_back();
	return false;
}

bool candraw(int i) {
	if (f[i] > d[i]) return false;
	if (p[i]) return false;
	p[i] = true;
	pa.push_back(i);
	if (i == e) return true;
	for (int ed : u[i]) {
		int j = a[ed]^b[ed]^i;
		if (candraw(j)) return true;
	}
	pa.pop_back();
	return false;
}

int loc[10005];

int main() {
	int k;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d", &sw, &st, &e);
	FO(i,0,m) {
		scanf("%d%d%lld", a+i, b+i, l+i);
		r[i] = l[i];
	}
	FO(i,m,m+k) {
		scanf("%d%d%lld%lld", a+i, b+i, l+i, r+i);
	}
	m += k;
	FO(i,0,m) {
		u[a[i]].push_back(i);
	}
	cf(); cd();
	//FO(i,1,n+1) printf("%lld %lld\n", f[i], d[i]);
	if (memset(p,0,sizeof p), canwin(sw)) printf("WIN\n");
	else if (memset(p,0,sizeof p), candraw(sw)) printf("DRAW\n");
	else {
		printf("LOSE\n");
		return 0;
	}
	FO(i,0,sz(pa)) {
		loc[pa[i]] = i+5;
	}
	FO(i,m-k,m) {
		if (abs(loc[a[i]]-loc[b[i]]) == 1) {
			printf("%lld ", l[i]);
		} else {
			printf("%lld ", r[i]);
		}
	}
	printf("\n");
}