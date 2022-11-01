#include<bits/stdc++.h>
using namespace std;

const int _ = 4e5 + 7 , P = 1e9 + 7;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int upd(int x){return x + (x >> 31 & P);}
struct segt{
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	int sum[_ << 2]; bool tag[_ << 2];
	segt(){memset(sum , 0 , sizeof(sum)); memset(tag , 0 , sizeof(tag));}
	void mark(int x){tag[x] = 1; sum[x] = 0;}
	void down(int x){if(tag[x]){mark(lch); mark(rch); tag[x] = 0;}}
	void up(int x){sum[x] = upd(sum[lch] + sum[rch] - P);}

	void mdf(int x , int l , int r , int tar , int v){
		sum[x] = upd(sum[x] + v - P); if(l == r) return;
		down(x); mid >= tar ? mdf(lch , l , mid , tar , v) : mdf(rch , mid + 1 , r , tar , v);
	}

	void clr(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return mark(x);
		down(x); if(mid >= L) clr(lch , l , mid , L , R);
		if(mid < R) clr(rch , mid + 1 , r , L , R);
		up(x);
	}

	int qry(int x , int l , int r , int L , int R){
		if(tag[x] || (l >= L && r <= R)) return sum[x];
		int sum = 0; if(mid >= L) sum = qry(lch , l , mid , L , R);
		if(mid < R) sum = upd(sum - P + qry(rch , mid + 1 , r , L , R));
		return sum;
	}
}Tr[2]; int lft = 1 , K , N , M;
struct seg{int l , r , type;}; vector < seg > now; vector < int > lsh;

int main(){
	ios::sync_with_stdio(0); cin >> K >> N >> M;
	for(int i = 1 ; i <= N ; ++i){int l , r; cin >> l >> r; now.push_back((seg){l , r , 0}); lsh.push_back(l); lsh.push_back(r + 1);}
	for(int i = 1 ; i <= M ; ++i){int l , r; cin >> l >> r; now.push_back((seg){l , r , 1}); lsh.push_back(l); lsh.push_back(r + 1);}
	sort(now.begin() , now.end() , [&](seg p , seg q){return p.l < q.l;}); int pre = 1; lsh.push_back(0); lsh.push_back(K + 1);
	sort(lsh.begin() , lsh.end()); lsh.resize(unique(lsh.begin() , lsh.end()) - lsh.begin());
	for(int i = 1 , pos = 0 ; i < lsh.size() ; ++i){
		lft = (1ll * lft * poww(2 , lsh[i] - pre) + Tr[0].qry(1 , 0 , lsh.size() , i - 1 , i - 1) + Tr[1].qry(1 , 0 , lsh.size() , i - 1 , i - 1)) % P;
		Tr[0].clr(1 , 0 , lsh.size() , i - 1 , i - 1); Tr[1].clr(1 , 0 , lsh.size() , i - 1 , i - 1);
		while(pos < now.size() && now[pos].l == lsh[i]){
			int t = upper_bound(lsh.begin() , lsh.end() , now[pos].r) - lsh.begin();
			Tr[now[pos].type].clr(1 , 0 , lsh.size() , t , lsh.size());
			Tr[now[pos].type].mdf(1 , 0 , lsh.size() , t - 1 , upd(P - lft - Tr[now[pos].type].qry(1 , 0 , lsh.size() , 0 , t)));
			++pos;
		}
		pre = lsh[i];
	}
	cout << lft; return 0;
}