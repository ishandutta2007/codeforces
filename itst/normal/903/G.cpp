#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7;
struct Edge{int s , t , w;}now[_];
int N , M , Q , v1[_] , v2[_] , tmp[_];
namespace segt{
	int mn[_ << 2] , mrk[_ << 2];
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

	void mark(int x , int v){mrk[x] += v; mn[x] += v;}
	void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}
	
	void modify(int x , int l , int r , int L , int R , int v){
		if(l >= L && r <= R) return mark(x , v);
		down(x);
		if(mid >= L) modify(lch , l , mid , L , R , v);
		if(mid < R) modify(rch , mid + 1 , r , L , R , v);
		mn[x] = min(mn[lch] , mn[rch]);
	}
}using namespace segt;

signed main(){
	ios::sync_with_stdio(0); cin >> N >> M >> Q;
	for(int i = 1 ; i < N ; ++i){cin >> v1[i] >> v2[i]; modify(1 , 0 , N - 1 , i , i , v2[i]);}
	for(int i = 1 ; i <= M ; ++i){cin >> now[i].s >> now[i].t >> now[i].w; modify(1 , 0 , N - 1 , 0 , now[i].t - 1 , now[i].w);}
	sort(now + 1 , now + M + 1 , [&](Edge p , Edge q){return p.s > q.s;}); int pos = 1;
	for(int i = N ; i ; --i){
		tmp[i] = mn[1] + v1[i];
		while(pos <= M && now[pos].s == i){modify(1 , 0 , N - 1 , 0 , now[pos].t - 1 , -now[pos].w); ++pos;}
	}
	memset(mn , 0 , sizeof(mn)); memset(mrk , 0 , sizeof(mrk));
	for(int i = 1 ; i <= N ; ++i) modify(1 , 1 , N , i , i , tmp[i]);
	cout << mn[1] << endl;
	while(Q--){int p , q; cin >> p >> q; modify(1 , 1 , N , p , p , q - v1[p]); v1[p] = q; cout << mn[1] << endl;}
	return 0;
}