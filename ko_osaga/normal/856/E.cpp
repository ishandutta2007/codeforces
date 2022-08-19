#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 998244353;
const int MAXN = 500005;
typedef pair<int, int> pi;

struct seg{
	multiset<int> tree[1050000];
	int val[1050000];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void insert(int x, int y){
		x += lim;
		tree[x].insert(y);
		val[x] = *--tree[x].end();
		while(x > 1){
			x >>= 1;
			val[x] = max(val[2*x], val[2*x+1]);
		}
	}
	void erase(int x, int y){
		x += lim;
		tree[x].erase(tree[x].find(y));
		if(tree[x].empty()) val[x] = 0;
		else val[x] = *--tree[x].end();
		while(x > 1){
			x >>= 1;
			val[x] = max(val[2*x], val[2*x+1]);
		}
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = 0;
		while(s < e){
			if(s%2 == 1) ret = max(ret, val[s++]);
			if(e%2 == 0) ret = max(ret, val[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, val[s]);
		return ret;
	}
}seg;

int r, n;
int qt[MAXN], qi[MAXN], qj[MAXN];
int vx[MAXN], vy[MAXN];
pi a[MAXN];

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

lint dot(pi a, pi b){
	return 1ll * a.first * b.first + 1ll * a.second * b.second;
}

bool cross(pi a, pi b){
	a.first += r;
	b.first -= r;
	return dot(a, b) < 0;
}

void solve(){
	int cnt = 0;
	for(int i=0; i<n; i++){
		if(qt[i] == 1){
			cnt++;
			seg.insert(vx[cnt], vy[cnt]);
		}
		if(qt[i] == 2){
			int p = qi[i];
			seg.erase(vx[p], vy[p]);
		}
		if(qt[i] == 3){
			int x = qi[i], y = qj[i];
			if(vx[x] > vx[y]) swap(x, y);
			if(cross(a[x], a[y])) puts("NO");
			else{
				int px = min(vx[x], vx[y]);
				int py = min(vy[x], vy[y]);
				bool ok = 1;
				seg.erase(vx[x], vy[x]);
				seg.erase(vx[y], vy[y]);
				if(seg.query(px, MAXN - 1) >= py) puts("NO");
				else puts("YES");
				seg.insert(vx[x], vy[x]);
				seg.insert(vx[y], vy[y]);
			}
		}
	}
}

struct point{ pi x; int idx; };
vector<point> v;

int main(){
	scanf("%d %d",&r,&n);
	int cnt = 0;
	for(int i=0; i<n; i++){
		scanf("%d",&qt[i]);
		if(qt[i] != 2) scanf("%d %d",&qi[i],&qj[i]);
		else scanf("%d",&qi[i]);
		if(qt[i] == 1){
			a[++cnt] = pi(qi[i], qj[i]);
		}
	}
	for(int i=1; i<=cnt; i++) v.push_back({a[i], i});
	sort(v.begin(), v.end(), [&](const point &a, const point &b){
		return ccw(pi(-r, 0), a.x, b.x) > 0;
	});
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && ccw(pi(-r, 0), v[i].x, v[e].x) == 0) e++;
		for(int j=i; j<e; j++) vx[v[j].idx] = i+1;
		i = e;
	}
	sort(v.begin(), v.end(), [&](const point &a, const point &b){
		return ccw(pi(r, 0), a.x, b.x) < 0;
	});
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && ccw(pi(r, 0), v[i].x, v[e].x) == 0) e++;
		for(int j=i; j<e; j++) vy[v[j].idx] = i+1;
		i = e;
	}
	seg.init(MAXN);
	solve();
}