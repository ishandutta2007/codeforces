#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
	return a;
}

#define int long long
const int _ = 2e5 + 7 , M = 2e5;
namespace segt{
	int sum[_ << 2] , mrk[_ << 2] , mx[_ << 2] , mn[_ << 2] , sz[_ << 2];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	
	void mark(int x , int val){mrk[x] = mx[x] = mn[x] = val; sum[x] = sz[x] * val;}
	void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}
	void up(int x){sum[x] = sum[lch] + sum[rch]; mx[x] = mx[rch]; mn[x] = mn[lch];}
	
	void init(int x , int l , int r){
		sz[x] = r - l + 1;
		if(l == r) sum[x] = mx[x] = mn[x] = l; else{init(lch , l , mid); init(rch , mid + 1 , r); up(x);}
	}

	void mdy(int x , int l , int r , int L , int R , int val){
		if(L > R || mn[x] >= val) return;
		if(l >= L && r <= R && mx[x] <= val) return mark(x , val);
		down(x);
		if(mid >= L) mdy(lch , l , mid , L , R , val);
		if(mid < R) mdy(rch , mid + 1 , r , L , R , val);
		up(x);
	}
}using namespace segt;
int N , arr[_] , ans[_]; vector < int > ys[_] , pos[_];

signed main() {
	N = read();
	for(int i = 1 ; i <= M ; ++i)
		for(int j = 1 ; j * i <= M ; ++j)
			ys[i * j].emplace_back(i);
	for(int i = 1 ; i <= N ; ++i){int id = read(); for(auto t : ys[id]) pos[t].emplace_back(i);}
	init(1 , 1 , N); ans[M] = (N + 1) * N - sum[1];
	for(int i = M ; i ; --i){
		if(pos[i].size() > 1){
			mdy(1 , 1 , N , pos[i][1] + 1 , N , N + 1);
			mdy(1 , 1 , N , pos[i][0] + 1 , pos[i][1] , pos[i][pos[i].size() - 1]);
			mdy(1 , 1 , N , 1 , pos[i][0] , pos[i][pos[i].size() - 2]);
		}
		ans[i - 1] = (N + 1) * N - sum[1];
	}
	int sum = 0; for(int i = 1 ; i <= M ; ++i) sum += (ans[i] - ans[i - 1]) * i;
	cout << sum; return 0;
}