#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){
		f = c == '-'; c = getchar();
	}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define int long long
const int _ = 1e5 + 7 , INF = 1e18;
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
struct segTr{
	int mx[_ << 2] , cnt[_ << 2] , nxt[_ << 2] , sum[_ << 2] , mrk[_ << 2];
	bool in[_ << 2];

	void init(int x , int l , int r){
		mrk[x] = mx[x] = INF; cnt[x] = r - l + 1;
		if(l != r){
			init(lch , l , mid); init(rch , mid + 1 , r);
		}
	}

	void mark(int x , int val){
		if(mx[x] <= val) return;
		sum[x] -= in[x] * mx[x] * cnt[x];
		mrk[x] = mx[x] = val; in[x] = 1;
		sum[x] += val * cnt[x];
	}
	
	void down(int x){
		mark(lch , mrk[x]); mark(rch , mrk[x]);
		mrk[x] = INF;
	}

	void up(int x){
		mx[x] = max(mx[lch] , mx[rch]);
		cnt[x] = (mx[x] == mx[lch]) * cnt[lch] + (mx[x] == mx[rch]) * cnt[rch];
		nxt[x] = max(mx[x] == mx[lch] ? nxt[lch] : mx[lch] , mx[x] == mx[rch] ? nxt[rch] : mx[rch]);
		in[x] = in[lch] & in[rch];
		sum[x] = sum[lch] + sum[rch];
	}

	void modify(int x , int l , int r , int L , int R , int val){
		if(mx[x] <= val) return;
		if(l >= L && r <= R)
			if(nxt[x] < val) return mark(x , val);
			else{
				down(x);
				modify(lch , l , mid , L , R , val);
				modify(rch , mid + 1 , r , L , R , val);
				return up(x);
			}
		down(x);
		if(mid >= L) modify(lch , l , mid , L , R , val);
		if(mid < R) modify(rch , mid + 1 , r , L , R , val);
		up(x);
	}
}Tr[2];

int query(int x , int l , int r , int L , int R){
	if((Tr[0].mx[x] == INF && Tr[0].nxt[x] == 0) || (Tr[1].mx[x] == INF && Tr[1].nxt[x] == 0))
		return 0;
	if(l >= L && r <= R)
		if(Tr[0].in[x] && Tr[1].in[x]) return Tr[0].sum[x] + Tr[1].sum[x];
		else{
			Tr[0].down(x); Tr[1].down(x);
			return query(lch , l , mid , L , R) + query(rch , mid + 1 , r , L , R);
		}
	Tr[0].down(x); Tr[1].down(x); int sum = 0;
	if(mid >= L) sum += query(lch , l , mid , L , R);
	if(mid < R) sum += query(rch , mid + 1 , r , L , R);
	return sum;
}
int Q;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	Tr[0].init(1 , 1 , 1e5); Tr[1].init(1 , 1 , 1e5);
	for(Q = read() ; Q ; --Q)
		if(read() == 1){
			int l = read() , r = read() - 1 , val = read();
			bool flg = val < 0; if(flg) val *= -1;
			Tr[flg].modify(1 , 1 , 1e5 , l , r , val);
		}
		else{
			int l = read() , r = read() - 1;
			printf("%lld\n" , query(1 , 1 , 1e5 , l , r));
		}
	return 0;
}