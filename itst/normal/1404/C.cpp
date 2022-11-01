#include<bits/stdc++.h>
using namespace std;

const int _ = 300003;
int ans[_] , N , Q , A[300003]; vector < pair < int , int > > pot[300003];

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
int mx[_ << 2] , mrk[_ << 2];

void mark(int x , int v){mx[x] += v; mrk[x] += v;}
void down(int x){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}
void mdf(int x , int l , int r , int R , int v){
	if(l == r){mx[x] += mx[x] >= v; return;}
	down(x);
	if(mid + 1 > R) mdf(lch , l , mid , R , v);
	else if(mx[rch] >= v){mark(lch , 1); mdf(rch , mid + 1 , r , R , v);}
	else mdf(lch , l , mid , R , v);
	mx[x] = mx[lch];
}

int qry(int x , int l , int r , int t){
	if(l == r) return mx[x];
	down(x); return mid >= t ? qry(lch , l , mid , t) : qry(rch , mid + 1 , r , t);
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> Q;
	for(int i = 1 ; i <= N ; ++i){cin >> A[i]; A[i] = i - A[i];}
	for(int i = 1 ; i <= Q ; ++i){int x , y; cin >> x >> y; pot[N - y].push_back(make_pair(x + 1 , i));}
	for(int i = 1 ; i <= N ; ++i){
		if(A[i] >= 0) mdf(1 , 1 , N , i , A[i]);
		for(auto t : pot[i]) ans[t.second] = qry(1 , 1 , N , t.first);
	}
	for(int i = 1 ; i <= Q ; ++i) cout << ans[i] << '\n';
	return 0;
}