#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

struct t1{
	int first, second, nsub;
};

int n, m;
t1 a[100005];
pi b[100005];

vector<int> vx;

struct seg{
	set<int> tree[270000];
	int lim;
	void init(int n, pi *b){
		for(int i=0; i<n; i++){
			vx.push_back(b[i].first);
		}
		for(lim = 1; lim <= n; lim <<= 1);
		sort(vx.begin(), vx.end());
		vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
		for(int i=0; i<n; i++){
			int t1 = lower_bound(vx.begin(), vx.end(), b[i].first) - vx.begin();
			t1 += lim;
			while(t1){
				tree[t1].insert(b[i].second);
				t1 >>= 1;
			}
		}
	}
	int query(int s, int e, int sy, int ey){
		s += lim;
		e += lim;
		while(s < e){
			if(s%2 == 1){
				auto t = tree[s].lower_bound(sy);
				if(t != tree[s].end() && *t <= ey) return 1;
				s++;
			}
			if(e%2 == 0){
				auto t = tree[e].lower_bound(sy);
				if(t != tree[e].end() && *t <= ey) return 1;
				e--;
			}
			s >>= 1;
			e >>= 1;
		}
		if(s == e){
			auto t = tree[s].lower_bound(sy);
			if(t != tree[s].end() && *t <= ey) return 1;
		}
		return 0;
	}
}seg;

bool query(int sx, int ex, int sy, int ey){
	int t1 = lower_bound(vx.begin(), vx.end(), sx) - vx.begin();
	int t2 = upper_bound(vx.begin(), vx.end(), ex) - vx.begin() - 1;
	return seg.query(t1, t2, sy, ey);
}

bool ok(int sx, int ex, int sy, int ey, int d2){
	if(sx > ex || sy > ey || d2 < 0) return 0;
	return query(sx - d2, ex + d2, sy - d2, ey + d2);
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[i] = {x+y, x-y, -1};
	}
	int ret = 1e9;
	int maxx = -1e9, minx = 1e9, maxy = -1e9, miny = 1e9;
	for(int i=0; i<n; i++){
		maxx = max(maxx, a[i].first);
		minx = min(minx, a[i].first);
		maxy = max(maxy, a[i].second);
		miny = min(miny, a[i].second);
	}
	ret = min(ret, max(maxx-minx+1, maxy-miny+1) / 2);
	if(m == 0){
		printf("%d",ret);
		return 0;
	}
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		b[i] = pi(x+y, x-y);
	}
	seg.init(m, b);
	for(int i=0; i<n; i++){
		a[i].nsub = 1e9;
		int s = 0, e = 5e8;
		while(s != e){
			int m = (s+e)/2;
			if(query(a[i].first - m, a[i].first + m, a[i].second - m, a[i].second + m)){
				e = m;
			}
			else s = m+1;
		}
		a[i].nsub = s;
	}
	sort(a, a+n, [&](const t1 &a, const t1 &b){
		return a.nsub > b.nsub;
	});
	vector<int> cnd;
	for(int i=0; i<n; i++){
		cnd.push_back(a[i].nsub);
	}
	sort(cnd.begin(), cnd.end());
	cnd.resize(unique(cnd.begin(), cnd.end()) - cnd.begin());
	ret = min(ret, cnd.back());
	reverse(cnd.begin(), cnd.end());
	int pnt = 0;
	int sx = -1e9, ex = 1e9, sy = -1e9, ey = 1e9;
	for(auto &i : cnd){
		while(pnt < n && a[pnt].nsub > i){
			sx = max(sx, a[pnt].first);
			ex = min(ex, a[pnt].first);
			sy = max(sy, a[pnt].second);
			ey = min(ey, a[pnt].second);
			pnt++;
		}
		int s = 0, e = 5e8;
		while(s != e){
			int m = (s+e)/2;
			if(ok(sx-m, ex+m, sy-m, ey+m, m-i)) e = m; 
			else s = m+1;
		}
		ret = min(ret, s);
	}
	cout << ret;
}