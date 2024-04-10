#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 200005

using namespace std;

int n,m, p[N], ip[N], ql[N], qr[N], ans[N], bit[N];
vector<int> v[N], qq[N];

void add(int i, int v) {
	for (i++; i < N; i+=i&-i) bit[i]+=v;
}

int sum(int i) {
	int r = 0;
	for (; i > 0; i-=i&-i) r += bit[i];
	return r;
}

int main() {
	scanf("%d%d", &n, &m);
	FO(i,0,n) {
		scanf("%d", p+i);
		ip[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			int x = ip[j],  y = ip[i];
			if (x > y) swap(x,y);
			v[x].push_back(y);
		}
	}
	FO(i,0,m) {
		scanf("%d%d", ql+i, qr+i);
		qq[ql[i]-1].push_back(i);
	}
	for (int i = n-1; i >= 0; i--) {
		for (int p : v[i]) add(p,1);
		for (int qi : qq[i]) ans[qi] = sum(qr[qi]);
	}
	FO(i,0,m) printf("%d\n", ans[i]);
}