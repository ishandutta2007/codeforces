#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define sz(x) (int)x.size()
const int _ = 50003; const ld pi = acos(-1);
int N , M; ld X , Y , A[_] , B[_];
struct comp{
	ld x , y;
	comp(ld _x = 0 , ld _y = 0) : x(_x) , y(_y){}
	friend comp operator +(comp p , comp q){return comp(p.x + q.x , p.y + q.y);}
	friend comp operator -(comp p , comp q){return comp(p.x - q.x , p.y - q.y);}
	friend ld operator *(comp p , comp q){return p.x * q.x + p.y * q.y;}
	friend ld operator %(comp p , comp q){return p.x * q.y - p.y * q.x;}
	friend comp operator *(comp p , ld q){return comp(p.x * q , p.y * q);}
	friend comp operator /(comp p , ld q){return comp(p.x / q , p.y / q);}
	ld len(){return sqrt(x * x + y * y);} ld len2(){return x * x + y * y;}
	ld ang(){return atan2(y , x);}
};

struct line{ld l , r; int id;}now[_];
vector < line > seg;
void prepare(ld mid){
	comp O(X , Y); seg.clear();
	for(int i = 1 ; i <= N ; ++i){
		comp st(0 , B[i]) , p(1 , A[i]) , mdp = st + p * ((O - st) * p / p.len2());
		ld len = abs((O - st) % p) / p.len(); if(len > mid) continue;
		ld chrd = sqrt(mid * mid - len * len);
		comp tp = p * (chrd / p.len()) , s1 = mdp + tp , s2 = mdp - tp;
		ld ang1 = (s1 - O).ang() , ang2 = (s2 - O).ang(); if(ang1 > ang2) swap(ang1 , ang2);
		if(ang2 - ang1 > pi){swap(ang1 , ang2); ang1 -= 2 * pi;}
		seg.push_back((line){ang1 , ang2 , i});
	}
	sort(seg.begin() , seg.end() , [&](line p , line q){return p.l < q.l;});
}

namespace Treap{
	ld val[_]; int ch[_][2] , sz[_] , rnd[_] , cnt , rt , r1 , r2; mt19937 Rand(time(0));
	int alloc(ld v){val[++cnt] = v; ch[cnt][0] = ch[cnt][1] = 0; sz[cnt] = 1; rnd[cnt] = Rand(); return cnt;}
	void up(int x){sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;}
	
	void split(int x , ld v , int &r1 , int &r2){
		if(!x){r1 = r2 = 0; return;}
		if(val[x] < v){r1 = x; split(ch[x][1] , v , ch[r1][1] , r2); up(r1);}
		else{r2 = x; split(ch[x][0] , v , r1 , ch[r2][0]); up(r2);}
	}

	int merge(int p , int q){
		if(!p || !q) return p + q;
		if(rnd[p] < rnd[q]){ch[p][1] = merge(ch[p][1] , q); up(p); return p;}
		ch[q][0] = merge(p , ch[q][0]); up(q); return q;
	}
	
	void ins(ld v){rt = merge(merge(r1 , alloc(v)) , r2); }
	void cut(ld v){split(rt , v , r1 , rt);}
	int qry(ld v){split(rt , v , r1 , r2); return sz[r1];}
}

bool check(ld mid){
	prepare(mid); int sum = 0; Treap::cnt = Treap::rt = 0;
	for(auto t : seg){Treap::cut(t.l); sum += Treap::qry(t.r); Treap::ins(t.r);}
	int p1 = 0 , p2 = sz(seg) - 1; while(p1 < sz(seg) && seg[p1].l < -pi) ++p1;
	sort(seg.begin() + p1 , seg.end() , [&](line p , line q){return p.r < q.r;});
	multiset < ld > q;
	while(~--p1){
		while(~p2 && seg[p2].r > seg[p1].l + 2 * pi) q.insert(seg[p2--].l);
		while(!q.empty() && *--q.end() > seg[p1].l + 2 * pi) q.erase(--q.end());
		sum += q.size();
	}
	return sum < M;
}

ld dist(int p , int q){
	ld x = (B[q] - B[p]) / (A[p] - A[q]) , y = A[p] * x + B[p];
	return sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
}

ld calc(ld mid){
	prepare(mid); ld sum = 0; int num = M; multimap < ld , int > q;
	for(auto t : seg){
		while(!q.empty() && q.begin()->first <= t.l) q.erase(q.begin());
		for(auto p : q){if(p.first > t.r) break; --num; sum += dist(p.second , t.id);}
		q.insert(make_pair(t.r , t.id));
	}
	q.clear(); int p1 = 0 , p2 = sz(seg) - 1; while(p1 < sz(seg) && seg[p1].l < -pi) ++p1;
	sort(seg.begin() + p1 , seg.end() , [&](line p , line q){return p.r < q.r;});
	while(~--p1){
		while(~p2 && seg[p2].r > seg[p1].l + 2 * pi) q.insert(make_pair(seg[p2].l , seg[p2].id)) , --p2;
		while(!q.empty() && (--q.end())->first > seg[p1].l + 2 * pi) q.erase(--q.end());
		for(auto t : q){--num; sum += dist(seg[p1].id , t.second);}
	}
	return sum + num * mid;
}

int main(){
	cin >> N >> X >> Y >> M; X /= 1000; Y /= 1000;
	for(int i = 1 ; i <= N ; ++i){cin >> A[i] >> B[i]; A[i] /= 1000; B[i] /= 1000;}
	ld L = 0 , R = 3e9; for(int i = 1 ; i <= 75 ; ++i){ld mid = (L + R) / 2; check(mid) ? L = mid : R = mid;}
	cout << fixed << setprecision(9) << calc(L) << endl; return 0;
}