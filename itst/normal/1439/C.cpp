#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; int mrk[_ << 2] , len[_ << 2] , sum[_ << 2] , mx[_ << 2] , mn[_ << 2];
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void mark(int x , int m){mrk[x] = mx[x] = mn[x] = m; sum[x] = m * len[x];}
void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}
void init(int x , int l , int r){
	len[x] = r - l + 1;if(l == r){cin >> sum[x]; mn[x] = mx[x] = sum[x]; return;}
	init(lch , l , mid); init(rch , mid + 1 , r);
	sum[x] = sum[lch] + sum[rch]; mx[x] = mx[lch]; mn[x] = mn[rch];
}

void mdf(int x , int l , int r , int R , int v){
	if(mn[x] >= v) return;
	if(r <= R && mx[x] <= v) return mark(x , v);
	down(x); mdf(lch , l , mid , R , v); if(mid < R) mdf(rch , mid + 1 , r , R , v);
	sum[x] = sum[lch] + sum[rch]; mx[x] = mx[lch]; mn[x] = mn[rch];
}

int fdmx(int x , int l , int r , int L , int v){
	if(mn[x] > v) return 0;
	if(l == r) return l;
	down(x); int t = 0; if(mid >= L) t = fdmx(lch , l , mid , L , v);
	return t ? t : fdmx(rch , mid + 1 , r , L , v);
}

int qlen(int x , int l , int r , int L , int &v){
	if(l >= L && v >= sum[x]){v -= sum[x]; return r + 1;}
	if(l == r) return l;
	down(x); int t = 0; if(mid >= L) t = qlen(lch , l , mid , L , v);
	if(!t || t == mid + 1) return qlen(rch , mid + 1 , r , L , v);
	return t;
}

signed main(){
	ios::sync_with_stdio(0); int N , Q; cin >> N >> Q; init(1 , 1 , N);
	while(Q--){
		int tp , x , v; cin >> tp >> x >> v;
		if(tp == 1) mdf(1 , 1 , N , x , v);
		else{
			int sum = 0 , t;
			while(x != N + 1 && (t = fdmx(1 , 1 , N , x , v))){
				int r = qlen(1 , 1 , N , t , v); sum += r - t; x = r;
			}
			cout << sum << '\n';
		}
	}
	return 0;
}