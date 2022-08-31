#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 100005;
const int mod = 1e9 + 7;

struct wookje{
	int x, y, t, idx;
	bool operator<(const wookje &w)const{
		return x + y - t < w.x + w.y - w.t;
	}
};

wookje a[MAXN];
int n, w, h;
pi nxt[MAXN];

int main(){
	scanf("%d %d %d",&n,&w,&h);
	for(int i=0; i<n; i++){
		int g, p, t;
		scanf("%d %d %d",&g,&p,&t);
		if(g == 1) a[i].x = p, a[i].y = 0;
		else a[i].y = p, a[i].x = 0;
		a[i].idx = i;
		a[i].t = t;
	}
	sort(a, a+n);
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && a[e].x + a[e].y - a[e].t == a[i].x + a[i].y - a[i].t) e++;
		vector<pi> up, dn;
		for(int j=i; j<e; j++){
			if(a[j].x == 0) up.push_back({a[j].y, a[j].idx});
			else dn.push_back({a[j].x, a[j].idx});
		}
		sort(up.begin(), up.end());
		reverse(up.begin(), up.end());
		sort(dn.begin(), dn.end());
		vector<pi> l, r;
		for(auto &i : up) l.push_back(i);
		for(auto &i : dn) l.push_back(i);
		for(auto &i : dn) r.push_back(i);
		for(auto &i : up) r.push_back(i);
		for(int i=0; i<l.size(); i++){
			if(i < dn.size()) nxt[l[i].second] = pi(r[i].first, h);
			else nxt[l[i].second] = pi(w, r[i].first);
		}
		i = e;
	}
	for(int i=0; i<n; i++) printf("%d %d\n", nxt[i].first, nxt[i].second);
}