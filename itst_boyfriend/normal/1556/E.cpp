#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 1e5 + 7; int N , Q , A[100003] , sum[100003];
struct dat{int need[2] , lft[2];}tr[_ << 2];
dat merge(dat p , dat q){
	dat r;
	for(int i = 0 ; i < 2 ; ++i){
		r.need[i] = p.need[i] + max(0ll , q.need[i] - p.lft[i]);
		r.lft[i] = max(p.lft[i] - q.need[i] , 0ll) + q.lft[i];
	}
	return r;
}
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void build(int x , int l , int r){
	if(l == r){tr[x].need[A[l] < 0] += abs(A[l]); tr[x].lft[A[l] > 0] += abs(A[l]); return;}
	build(lch , l , mid); build(rch , mid + 1 , r); tr[x] = merge(tr[lch] , tr[rch]);
}
dat qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return tr[x];
	if(mid < L) return qry(rch , mid + 1 , r , L , R);
	if(mid >= R) return qry(lch , l , mid , L , R);
	return merge(qry(lch , l , mid , L , R) , qry(rch , mid + 1 , r , L , R));
}

signed main(){
	cin >> N >> Q;
	for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = 1 ; i <= N ; ++i){int B; cin >> B; A[i] = B - A[i];}
	for(int i = 1 ; i <= N ; ++i) sum[i] = sum[i - 1] + A[i];
	build(1 , 1 , N);
	while(Q--){
		int l , r; cin >> l >> r;
		dat ans = qry(1 , 1 , N , l , r);
		cout << (sum[r] != sum[l - 1] || ans.need[1] ? -1 : ans.need[0]) << endl;
	}
	return 0;
}