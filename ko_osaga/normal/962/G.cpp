#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 15005;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

struct rect{
	int sx, ex, sy, ey;
};

struct block{
	int pos, s, e;
	bool operator<(const block &b)const{
		return pi(s, e) < pi(b.s, b.e);
	}
};

struct swp{
	int yc, xs, xe, act;
	bool operator<(const swp &b)const{
		return pi(yc, -act) < pi(b.yc, -b.act);
	}
};

int n;
pi a[MAXN];
vector<rect> ans;

void make_rect(){
	vector<swp> event;
	set<block> s;
	for(int i=0; i<n; i++){
		pi p1 = a[i];
		pi p2 = a[(i+1)%n];
		if(p1.second == p2.second) continue;
		if(p1.second < p2.second){
			event.push_back({p1.first, p1.second, p2.second, -1});
		}
		else{
			event.push_back({p1.first, p2.second, p1.second, +1});
		}
	}
	sort(event.begin(), event.end());
	auto rect_close = [&](block b, int pos){
		if(b.pos < pos){
			ans.push_back({b.pos, pos, b.s, b.e});
		}
	};
	for(int i=0; i<event.size(); ){
		int e = i;
		while(e < event.size() && event[e].yc == event[i].yc){
			if(event[e].act == 1){
				auto lbnd = s.lower_bound({-1, event[e].xs, event[e].xe});
				int curs = event[e].xs;
				int cure = event[e].xe;
				if(lbnd != s.begin() && prev(lbnd)->e == event[e].xs){
					curs = prev(lbnd)->s;
					rect_close(*prev(lbnd), event[e].yc);
					s.erase(prev(lbnd));
				}
				if(lbnd != s.end() && lbnd->s == event[e].xe){
					cure = lbnd->e;
					rect_close(*lbnd, event[e].yc);
					s.erase(lbnd);
				}
				s.insert({event[e].yc, curs, cure});
			}
			else{
				auto lbnd = --s.lower_bound({-1, event[e].xe + 1, -1});
				if(pi(lbnd->s, lbnd->e) == pi(event[e].xs, event[e].xe)){
					rect_close(*lbnd, event[e].yc);
					s.erase(lbnd);
				}
				else if(lbnd->s == event[e].xs){
					rect_close(*lbnd, event[e].yc);
					s.erase(lbnd);
					s.insert({event[e].yc, event[e].xe, lbnd->e});
				}
				else if(lbnd->e == event[e].xe){
					rect_close(*lbnd, event[e].yc);
					s.erase(lbnd);
					s.insert({event[e].yc, lbnd->s, event[e].xs});
				}
				else{
					rect_close(*lbnd, event[e].yc);
					block nxt1 = {event[e].yc, lbnd->s, event[e].xs};
					block nxt2 = {event[e].yc, event[e].xe, lbnd->e};
					s.erase(lbnd);
					s.insert(nxt1);
					s.insert(nxt2);
				}
			}
			e++;
		}
		i = e;
	}
	for(auto &i : ans){
	//	printf("%d %d %d %d\n", i.sx, i.ex, i.sy, i.ey);
	}
}

bool insec_by_edge(rect x, rect y){
	x.sx = max(x.sx, y.sx);
	x.ex = min(x.ex, y.ex);
	x.sy = max(x.sy, y.sy);
	x.ey = min(x.ey, y.ey);
	if(x.sx > x.ex || x.sy > x.ey) return 0;
	if(x.sx < x.ex && x.sy < x.ey) assert(0);
	if(pi(x.sx, x.sy) == pi(x.ex, x.ey)) return 0;
	return 1;
}

int main(){
	pi x, y; 
	scanf("%d %d %d %d %d",&x.first,&y.second,&y.first,&x.second,&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	a[n] = a[0];
	make_rect();
	vector<rect> comp = ans;
	ans.clear();
	for(auto &i : comp){
		i.sx = max(i.sx, x.first);
		i.ex = min(i.ex, y.first);
		i.sy = max(i.sy, x.second);
		i.ey = min(i.ey, y.second);
		if(i.sx < i.ex && i.sy < i.ey) ans.push_back(i);
	}
	disj.init(ans.size());
	int cnt = 0;
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<i; j++){
			if(insec_by_edge(ans[i], ans[j])){
				cnt += disj.uni(i, j);
			}
		}
	}
	cout << ans.size() - cnt << endl;
}