#include<bits/stdc++.h>
using namespace std;

#define ld double
#define eps 1e-12
bool cmp(ld p , ld q){return p + eps > q && p - eps < q;}
const int _ = 1e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , cntEd , N , M;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int top[_] , sz[_] , son[_] , dep[_] , dfn[_] , fa[_] , ts;
void dfs1(int x , int p){
	sz[x] = 1; dep[x] = dep[p] + 1; fa[x] = p;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs1(Ed[i].end , x); sz[x] += sz[Ed[i].end];
			if(sz[son[x]] < sz[Ed[i].end]) son[x] = Ed[i].end;
		}
}

void dfs2(int x , int t){
	top[x] = t; dfn[x] = ++ts; if(!son[x]) return;
	dfs2(son[x] , t);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa[x] && Ed[i].end != son[x]) dfs2(Ed[i].end , Ed[i].end);
}

int dist(int x , int y){
	int sum = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x , y);
		sum += dep[x] - dep[top[x]] + 1; x = fa[top[x]];
	}
	return sum + max(dep[x] , dep[y]) - min(dep[x] , dep[y]);
}

struct comp{
	ld x , y;
	comp(ld _x = 0 , ld _y = 0) : x(_x) , y(_y){}
	friend comp operator +(comp p , comp q){return comp(p.x + q.x , p.y + q.y);}
	friend comp operator -(comp p , comp q){return comp(p.x - q.x , p.y - q.y);}
	friend ld operator *(comp p , comp q){return p.x * q.x + p.y * q.y;}
	friend ld operator %(comp p , comp q){return p.x * q.y - p.y * q.x;}
	friend comp operator *(comp p , ld q){return comp(p.x * q , p.y * q);}
};

ld mnsect , cur;
struct line{
	ld x1 , y1 , x2 , y2; bool f1 , f2;
	line(ld _x1 = 0 , ld _y1 = 0 , ld _x2 = 0 , ld _y2 = 0 , bool _f1 = 0 , bool _f2 = 0) :
		x1(_x1) , y1(_y1) , x2(_x2) , y2(_y2) , f1(_f1) , f2(_f2){}
	ld calc(ld pos){return cmp(x1 , x2) ? y1 : y1 + (pos - x1) / (x2 - x1) * (y2 - y1);}
	friend bool operator <(line p , line q){
		if(!cmp(p.calc(cur) , q.calc(cur))) return p.calc(cur) < q.calc(cur);
		if(!cmp(p.x1 , q.x1)) return p.x1 < q.x1;
		if(!cmp(p.x2 , q.x2)) return p.x2 < q.x2;
		if(!cmp(p.y1 , q.y1)) return p.y1 < q.y1;
		if(!cmp(p.y2 , q.y2)) return p.y2 < q.y2;
		return 0;
	}
}; vector < line > now; set < line > in;

void getsect(line p , line q){
	comp st1(p.x1 , p.y1) , ed1(p.x2 , p.y2) , st2(q.x1 , q.y1) , ed2(q.x2 , q.y2);
	if(((st2 - st1) % (ed1 - st1)) * ((ed2 - st1) % (ed1 - st1)) > eps) return;
	if(((st1 - st2) % (ed2 - st2)) * ((ed1 - st2) % (ed2 - st2)) > eps) return;
	ld ar = (st1 - ed1) % (st2 - ed2);
	if(cmp(ar , 0)){if((p.f2 || !cmp(cur , p.x2)) && (q.f2 || !cmp(cur , q.x2))) mnsect = min(mnsect , cur); return;}
	ld pr = abs(((st1 - st2) % (ed2 - st2)) / ar); comp now = st1 + (ed1 - st1) * pr;
	if((cmp(now.x , st1.x) && !p.f1) || (cmp(now.x , ed1.x) && !p.f2)) return;
	if((cmp(now.x , st2.x) && !q.f1) || (cmp(now.x , ed2.x) && !q.f2)) return;
	mnsect = min(mnsect , now.x);
}

int main(){
	cin >> N >> M; for(int x , y , i = 1 ; i < N ; ++i){cin >> x >> y; addEd(x , y); addEd(y , x);}
	dfs1(1 , 0); dfs2(1 , 1); 
	while(M--){
		int t , x , y , c; cin >> t >> c >> x >> y; ld start = t , end = t + 1.0 * dist(x , y) / c;
		while(top[x] != top[y])
			if(dep[top[x]] > dep[top[y]]){
				int t = top[x]; ld dis = 1.0 * (dep[x] - dep[t] + 1) / c;
				now.emplace_back(start , dfn[x] , start + dis , dfn[t] - 1 , 1 , 0);
				x = fa[t]; start += dis;
			}else{
				int t = top[y]; ld dis = 1.0 * (dep[y] - dep[t] + 1) / c;
				now.emplace_back(end - dis , dfn[t] - 1 , end , dfn[y] , 0 , 1);
				y = fa[t]; end -= dis;
			}
		now.emplace_back(start , dfn[x] , end , dfn[y] , 1 , 1);
	}
	mnsect = 1e60; sort(now.begin() , now.end() , [&](line p , line q){return p.x1 < q.x1;});
	multimap < ld , set < line > :: iterator > del0 , del1;

	for(auto t : now){
		if(t.x1 > mnsect) break;
		while(!del0.empty() && del0.begin()->first <= t.x1 + eps){
			auto t = del0.begin()->second; del0.erase(del0.begin());
			auto p = t , q = t; if(++p != in.end() && q != in.begin()) getsect(*p , *--q);
			in.erase(t);
		}
		while(!del1.empty() && del1.begin()->first <= t.x1 - eps){
			auto t = del1.begin()->second; del1.erase(del1.begin());
			auto p = t , q = t; if(++p != in.end() && q != in.begin()) getsect(*p , *--q);
			in.erase(t);
		}
		cur = t.x1; auto cur = in.insert(t); 
		if(!cur.second){mnsect = t.x1; break;}
		auto p = cur.first; ++p; if(p != in.end()) getsect(*p , t);
		if(--p != in.begin()) getsect(*--p , t);
		(t.f2 ? del1 : del0).insert(make_pair(t.x2 , cur.first));
	}

	if(mnsect > 1e20) cout << -1;
	else cout << fixed << setprecision(10) << mnsect << endl;
	
	return 0;
}