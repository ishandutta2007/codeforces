#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7;

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
int mn[_ << 2] , mrk[_ << 2];
void mark(int x , int v){mrk[x] += v; mn[x] += v;}
void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}
void up(int x){mn[x] = min(mn[lch] , mn[rch]);}

void modify(int x , int l , int r , int L , int R , int v){
	if(l >= L && r <= R) return mark(x , v);
	down(x); if(mid >= L) modify(lch , l , mid , L , R , v);
	if(mid < R) modify(rch , mid + 1 , r , L , R , v);
	up(x);
}

int N , p[_] , q[_] , ans[_] , id[_];

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){cin >> p[i]; id[p[i]] = i;}
	for(int i = 1 ; i <= N ; ++i) cin >> q[i];
	int pos = N; modify(1 , 1 , N , 1 , id[N] , -1);
	for(int i = 1 ; i <= N ; ++i){
		while(mn[1] >= 0) modify(1 , 1 , N , 1 , id[--pos] , -1);
		cout << pos << ' ';
		modify(1 , 1 , N , 1 , q[i] , 1);
	}
	return 0;
}