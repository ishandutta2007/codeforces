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

struct edge {
	int a,b;
	ll w;
	bool operator< (const edge &e) {
		return w<e.w || w==e.w && a<e.a || w==e.w && a==e.a && b<e.b;
	}
	edge () {}
	edge (int a, int b, ll w) : a(a), b(b), w(w) {}
};

const int maxn=1<<17;
const ll inf=(1e16)+7;


int n,m,k;
ll ans;
bool portal[maxn];
int p[maxn],pr[maxn];
ll d[maxn];
edge a[maxn],b[maxn];
vector <pair<int,int>> e[maxn];


void reading() {
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].w);
		e[a[i].a].push_back(make_pair(a[i].b,a[i].w));
		e[a[i].b].push_back(make_pair(a[i].a,a[i].w));
	}
	scanf("%d",&k);
	for (int i=0; i<k; i++) {
		int x;
		scanf("%d",&x);
		portal[x]=1;
	}
}

void dijkstra() {
	for (int i=1; i<=n; i++) {
		d[i]=(portal[i]?0:inf);
		p[i]=i;
	}
	set<pair<ll,int>> s;
	for (int i=0; i<m; i++) {
		if (portal[a[i].a] && a[i].w<d[a[i].b]) {
			d[a[i].b]=a[i].w;
			p[a[i].b]=a[i].a;
		}
		if (portal[a[i].b] && a[i].w<d[a[i].a]) {
			d[a[i].a]=a[i].w;
			p[a[i].a]=a[i].b;
		}
	}
	for (int i=1; i<=n; i++) if (!portal[i]) s.insert(make_pair(d[i],i));

	while (!s.empty()) {
		int v=s.begin()->second;
		ll cd=s.begin()->first;
		s.erase(s.begin());
		for (int i=0; i<e[v].size(); i++) {
			int u=e[v][i].first, w=e[v][i].second;
			if (cd+w<d[u]) {
				s.erase(make_pair(d[u],u));
				d[u]=cd+w;
				p[u]=p[v];
				s.insert(make_pair(d[u],u));
			}
		}
	}

	for (int i=0; i<m; i++) {
		int v=a[i].a, u=a[i].b;
		ll w=a[i].w;
		w+=d[v]+d[u];
		v=p[v]; u=p[u];
		b[i]=edge(v,u,w);
	}
}

int findparent(int x) {
	if (x==pr[x]) return x;
	return pr[x]=findparent(pr[x]);
}

void kruskal() {
	for (int i=1; i<=n; i++) pr[i]=i;
	sort(b,b+m);
	for (int i=0; i<m; i++) {
		if (findparent(b[i].a)!=findparent(b[i].b)) {
			if (rand()&1)
				pr[findparent(b[i].a)]=findparent(b[i].b);
			else 
				pr[findparent(b[i].b)]=findparent(b[i].a);
			ans+=b[i].w;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	reading();
	dijkstra();
	kruskal();
	cout << ans+d[1] << endl;
	return 0;
}