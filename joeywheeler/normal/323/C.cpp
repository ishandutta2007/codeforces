#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, p[1000005], q[1000005];
vector<int> rt[2000005];

void init() {
	FO(i,n,n+n) rt[i].push_back(q[i-n]);
	for (int i=n-1;i;i--) merge(rt[2*i].begin(),rt[2*i].end(),rt[2*i+1].begin(),rt[2*i+1].end(),back_inserter(rt[i]));
}

int qu(int l, int r, int a, int b) {
	int res = 0;
	for (l+=n,r+=n;l<r;l/=2,r/=2) {
		if (l&1) {
			res += lower_bound(rt[l].begin(),rt[l].end(),b)-lower_bound(rt[l].begin(),rt[l].end(),a);
			l++;
		}
		if (r&1) {
			r--;
			res += lower_bound(rt[r].begin(),rt[r].end(),b)-lower_bound(rt[r].begin(),rt[r].end(),a);
		}
	}
	return res;
}

int main() {
	scanf("%d", &n);
	FO(i,0,n) {
		int x; scanf("%d", &x);
		p[x-1] = i;
	}
	FO(i,0,n) {
		int x; scanf("%d", &x);
		q[i] = p[x-1];
	}
	init();
	int m; scanf("%d", &m);
	int x = 0;
	FO(i,0,m) {
#define f(a) ((a-1+x)%n)
		int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
		a = f(a),b=f(b),c=f(c),d=f(d);
		if (a>b) swap(a,b); if (c>d) swap(c,d);
		b++; d++;
		x = qu(c,d,a,b)+1;
		printf("%d\n", x-1);
	}
}