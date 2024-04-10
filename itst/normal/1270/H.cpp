#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
const int _ = 1e6 + 7; int mrk[_ << 2] , mn[_ << 2] , cnt[_ << 2] , N , Q , A[_];
void mark(int x , int v){mn[x] += v; mrk[x] += v;}
void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}
void up(int x){mn[x] = min(mn[lch] , mn[rch]); cnt[x] = (mn[x] == mn[lch]) * cnt[lch] + (mn[x] == mn[rch]) * cnt[rch];}

void mdf(int x , int l , int r , int L , int R , int v){
	if(l >= L && r <= R) return mark(x , v);
	down(x); if(mid >= L) mdf(lch , l , mid , L , R , v);
	if(mid < R) mdf(rch , mid + 1 , r , L , R , v);
	up(x);
}

void mdf_cnt(int x , int l , int r , int t , int flg){
	if(l == r){cnt[x] = (flg + 1) / 2; return;}
	down(x); mid >= t ? mdf_cnt(lch , l , mid , t , flg) : mdf_cnt(rch , mid + 1 , r , t , flg); up(x);
}

void add(int x , int flg){mdf(1 , 1 , 1e6 + 1 , min(A[x] , A[x + 1]) + 1 , max(A[x] , A[x + 1]) , flg); mdf_cnt(1 , 1 , 1e6 + 1 , A[x] , flg);}

int main(){
	ios::sync_with_stdio(0); cin >> N >> Q; A[0] = 1e6 + 1; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = 0 ; i <= N ; ++i) add(i , 1);
	while(Q--){int p , q; cin >> p >> q; add(p - 1 , -1); add(p , -1); A[p] = q; add(p , 1); add(p - 1 , 1); cout << cnt[1] - 1 << '\n';}
	return 0;
}