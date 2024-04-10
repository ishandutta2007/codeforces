#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;


typedef long long ll;

ll d[100005], da[100005], db[100005], dd[100005];
vector<pair<int,ll> > u[100005];
int n, s[100005];
ll l;

void calcd(int i, int p, ll *w) {
	for (auto x : u[i]) {
		int y; ll v;
		tie(y,v) = x;
		if (y != p) {
			w[y] = w[i]+v;
			calcd(y,i,w);
		}
	}
}

vector<int> pp;
void go(int i, int p) {
	pp.push_back(i);
	int a = 0, b = sz(pp)-1, w=b;
	while (a <= b) {
		int md = (a+b)/2;
		if ((dd[i]-dd[pp[md]]) <= l) {
			w = md; b = md - 1;
		} else a = md + 1;
	}
	s[i]++; if (w) {s[pp[w-1]]--;}
	for (auto x : u[i]) {
		int y; ll v;
		tie(y,v) = x;
		if (y != p) go(y,i);
	}
	pp.pop_back();
}

int ans;

void gogo(int i, int p) {
	for (auto x : u[i]) {
		int y; ll vv;
		tie(y,vv) = x;
		if (y != p) {
			gogo(y,i);
			s[i] += s[y];
		}
	}
	ans = max(ans,s[i]);
}

int main() {
	scanf("%d", &n);
	FO(i,0,n-1) {
		int x, y; ll l;
		scanf("%d %d %lld", &x, &y, &l);
		u[x].push_back({y,l});
		u[y].push_back({x,l});
	}
	calcd(1,0,d); int mi = 1;
	FO(i,1,n+1) if (d[i] > d[mi]) mi = i;
	calcd(mi,0,da); mi = 1;
	FO(i,1,n+1) if (da[i] > da[mi]) mi = i;
	calcd(mi,0,db);
	FO(i,1,n+1) dd[i] = max(da[i], db[i]);
	mi = 1;
	FO(i,1,n+1) if (dd[i] < dd[mi]) mi = i;

	int q; scanf("%d", &q);
	FO(Z,0,q) {
		scanf("%lld", &l);
		ans = 0;
		memset(s,0,sizeof s);
		go(mi,0);
		gogo(mi,0);
		printf("%d\n", ans);
	}
}