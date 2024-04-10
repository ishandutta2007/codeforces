#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

struct zahvat {
	int m,p,pr;
	ll d,r;
	zahvat () {}
	zahvat(int m, int p, ll r, int pr, ll d) : m(m), p(p), r(r), pr(pr), d(d) {}
	bool operator< (const zahvat &a) {
		return m<a.m || m==a.m && d<a.d || m==a.m && d==a.d && pr<a.pr;
	}
};

const int maxn=300100;

int p,n,ans;
int pr[maxn];
ll x,y,r;
zahvat a[maxn];
vector<zahvat> b;

bool cmp1(const zahvat &a, const zahvat &b) {
	return a.d<b.d || a.d==b.d && a.m<b.m || a.d==b.d && a.m==b.m && a.pr<b.pr;
}

int binsearch(ll x) {
	int l=0, r=n-1;
	while (r-l>1) {
		int m=(l+r)>>1;
		if (b[m].d<=x) l=m;
		else r=m;
	}
	if (b[r].d<=x) return r;
	if (b[l].d<=x) return l;
	return -1;
}

int t[4*maxn];

void build(int v, int tl, int tr) {
	if (tl==tr) {
		t[v]=tl;
		return;
	}
	int tm=(tl+tr)>>1;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	if (b[t[v*2]]<b[t[v*2+1]]) 
		t[v]=t[v*2];
	else t[v]=t[v*2+1];
}

int get(int v, int tl, int tr, int l, int r) {
	if (l>r) return n;
	if (tl==l && tr==r) {
		return t[v];
	}
	int tm=(tl+tr)>>1;
	int k1=get(v*2,tl,tm,l,min(r,tm));
	int k2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
	if (b[k1]<b[k2]) return k1;
	else return k2;
}

void upd(int v, int tl, int tr, int x) {
	if (tl==tr) {
		b[tl].m=b[b.size()-1].m;
		return;
	}
	int tm=(tl+tr)>>1;
	if (x<=tm) upd(v*2,tl,tm,x);
	else upd(v*2+1,tm+1,tr,x);
	if (b[t[v*2]]<b[t[v*2+1]]) t[v]=t[v*2];
	else t[v]=t[v*2+1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> x >> y >> p >> r >> n;
	r=r*r;
	for (int i=0; i<n; i++) {
		int x0,y0,m0,p0,r0;
		scanf("%d%d%d%d%d",&x0,&y0,&m0,&p0,&r0);
		a[i]=zahvat(m0,p0,(ll)r0*r0,i,sqr(x-(ll)x0)+sqr(y-(ll)y0));
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end(),cmp1);
	b.push_back(b[0]);
	b[b.size()-1].m=(1000000000)+1;
	b[b.size()-1].d=(8000000000000000005LL)+1;
	for (int i=0; i<n; i++) {
		pr[b[i].pr]=i;
	}
	build(1,0,n-1);

	ll curr=r;
	int curp=p;
	queue<zahvat> q;
	while (1) {
		int m=binsearch(curr);
		if (m!=-1) {
			int o=get(1,0,n-1,0,m);
			while (o<=m && b[o].m<=curp) {
				q.push(b[o]);
				upd(1,0,n-1,o);
				o=get(1,0,n-1,0,m);
				ans++;
			}
		}
		if (q.empty()) break;
		else {
			curr=q.front().r;
			curp=q.front().p;
			q.pop();
		}
	}
	cout << ans;
	return 0;
}