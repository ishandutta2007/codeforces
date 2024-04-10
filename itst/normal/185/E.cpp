#include<bits/stdc++.h>
using namespace std;
     
#define int long long
int read(){
	int a = 0; bool f = 0; char c = getchar(); while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}
     
#define pii pair < int , int >
const int _ = 2e5 + 7; pii sub[_]; int N , M , ans = 1e9;
struct peo{int x , y , t;}p[_];
bool cmpt(peo p , peo q){return p.t > q.t;}
bool cmpx(peo p , peo q){return p.x < q.x || p.x == q.x && p.y < q.y || p.x == q.x && p.y == q.y && p.t < q.t;}
     
#define mid ((l + r) >> 1)
const int __ = _ << 5 , INF = 2e8;
int ch[__][2] , sz[__] , cnode;
void ins(int &x , int l , int r , int t){
	int tmp = ++cnode; ch[tmp][0] = ch[x][0]; ch[tmp][1] = ch[x][1]; sz[tmp] = sz[x] + 1; x = tmp;
	if(l != r) mid >= t ? ins(ch[x][0] , l , mid , t) : ins(ch[x][1] , mid + 1 , r , t);
}
     
int qry(int x , int l , int r , int L , int R){
	if(!sz[x] || (l >= L && r <= R)) return sz[x];
	int sum = 0; if(mid >= L) sum = qry(ch[x][0] , l , mid , L , R);
	if(mid < R) sum += qry(ch[x][1] , mid + 1 , r , L , R);
	return sum;
}
#undef mid
int rt[_];
     
int qry_rect(int x1 , int x2 , int y1 , int y2){
	if(y2 < -INF || y1 > INF) return 0;
	int pl = lower_bound(sub + 1 , sub + M + 1 , pii(x1 , -INF)) - sub - 1 ,
		pr = lower_bound(sub + 1 , sub + M + 1 , pii(x2 + 1 , -INF)) - sub - 1;
	return qry(rt[pr] , -INF , INF , y1 , y2) - qry(rt[pl] , -INF , INF , y1 , y2);
}
     
#define lowbit(x) (x & -x)
struct bit{
	int sz , arr[_]; bit(){memset(arr , -0x3f , sizeof(arr));}
	void add(int x , int v){while(x <= sz){arr[x] = max(arr[x] , v); x += lowbit(x);}}
	int qry(int x){int ans = arr[0]; while(x){ans = max(ans , arr[x]); x -= lowbit(x);} return ans;}
};
     
signed main(){
	N = read(); M = read(); for(int i = 1 ; i <= N ; ++i){p[i].x = read(); p[i].y = read(); p[i].t = 1e9;}
	for(int i = 1 ; i <= M ; ++i){sub[i].first = read(); sub[i].second = read();}
    	
	vector < peo > pot; for(int i = 1 ; i <= N ; ++i) pot.push_back(p[i]);
	for(int i = 1 ; i <= M ; ++i) pot.push_back((peo){sub[i].first , sub[i].second , -1});
	for(int i = 0 ; i < 4 ; ++i){
		sort(pot.begin() , pot.end() , cmpx); vector < int > valy; valy.push_back(-INF - 1);
		for(auto t : pot) valy.push_back(t.y);
		sort(valy.begin() , valy.end()); bit calc; calc.sz = valy.size();
    		
		for(auto &t : pot)
			if(t.t == -1) calc.add(lower_bound(valy.begin() , valy.end() , t.y) - valy.begin() , t.x + t.y);
			else t.t = min(t.t , t.x + t.y - calc.qry(lower_bound(valy.begin() , valy.end() , t.y) - valy.begin()));
    		
		for(auto &t : pot) i & 1 ? t.x = -t.x : t.y = -t.y;
	}
	N = 0; for(auto t : pot) if(t.t != -1) p[++N] = t;
	for(int i = 1 ; i <= N ; ++i){p[i].x += p[i].y; p[i].y = p[i].x - 2 * p[i].y;}
	for(int i = 1 ; i <= M ; ++i){sub[i].first += sub[i].second; sub[i].second = sub[i].first - 2 * sub[i].second;}
	sort(sub + 1 , sub + M + 1); for(int i = 1 ; i <= M ; ++i) ins(rt[i] = rt[i - 1] , -INF , INF , sub[i].second);
    	
	sort(p + 1 , p + N + 1 , cmpt); ans = p[1].t; int mnx = INF , mxx = -INF , mny = INF , mxy = -INF; p[N + 1].t = -INF;
	for(int i = 1 ; i <= N ; ++i){
		mnx = min(mnx , p[i].x); mxx = max(mxx , p[i].x); mny = min(mny , p[i].y); mxy = max(mxy , p[i].y);
		int l = max(p[i + 1].t , max((mxx - mnx + 1) / 2 , (mxy - mny + 1) / 2)) , r = INF;
		if(!M){
			if(i == N) ans = l;
			continue;
		}
		while(l < r){
			int mid = (l + r) >> 1 , more = mid - p[i + 1].t;
			qry_rect(mxx - mid - more , mnx + mid + more , mxy - mid - more , mny + mid + more) ? r = mid : l = mid + 1;
		}
		int more = l - p[i + 1].t , sum = qry_rect(mxx - l - more , mnx + l + more , mxy - l - more , mny + l + more);
		mxx -= l; mnx += l; mxy -= l; mny += l;
		if(mxx == mnx && mxy == mny && (mxx + mxy) % 2){++l; --mxx; ++mnx; --mxy; ++mny;}
		else if(i != N){
			if(mxx == mnx){
				if((mxx + mxy) & 1) sum -= qry_rect(mxx - more , mnx + more , mxy - more , mxy - more);
				if((mxx + mny) & 1) sum -= qry_rect(mxx - more , mnx + more , mny + more , mny + more);
			}
			if(mxy == mny){
				if((mny + mxx) & 1) sum -= qry_rect(mxx - more , mxx - more , mxy - more , mny + more);
				if((mny + mnx) & 1) sum -= qry_rect(mnx + more , mnx + more , mxy - more , mny + more);
			}
			if(!sum){++l; --mxx; ++mnx; --mxy; ++mny;}
		}
		ans = min(ans , l); mxx += l; mnx -= l; mxy += l; mny -= l;
	}
	cout << ans; return 0;
}