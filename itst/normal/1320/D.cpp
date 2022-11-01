#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int MOD1 = 1e9 + 7 , MOD2 = 1019260817 , _ = 2e5 + 7;
#define pii pair < int , int >
pii operator +(pii p , pii q){return pii((p.first + q.first) % MOD1 , (p.second + q.second) % MOD2);}
pii operator *(pii p , pii q){return pii((1ll * p.first * q.first % MOD1) , (1ll * p.second * q.second % MOD2));}
pii base[_]; int N , Q; char str[_];
struct data{int first , end , len; pii data;}tr[_ << 2];
data operator +(data p , data q){
	if(!p.len) return q;
	if(!q.len) return p;
	data t; t.first = p.first; t.end = q.end; t.len = p.len + q.len;
	t.data = p.data * base[q.len] + ((q.first - p.end) & 1 ? pii(1 , 1) : pii(2 , 2)) * base[q.len - 1] + q.data;
	return t;
}

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

void init(int x , int l , int r){
	if(l == r){if(str[l] == '0'){tr[x].first = tr[x].end = l; tr[x].len = 1;} return;
	}else{init(lch , l , mid); init(rch , mid + 1 , r); tr[x] = tr[lch] + tr[rch];}
}

data qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return tr[x];
	data now; now.len = 0;
	if(mid >= L) now = qry(lch , l , mid , L , R);
	if(mid < R) now = now + qry(rch , mid + 1 , r , L , R);
	return now;
}

int main(){
	base[0] = pii(1 , 1); base[1] = pii(233 , 233); N = read(); scanf("%s" , str + 1);
	for(int i = 2 ; i <= N ; ++i) base[i] = base[i - 1] * base[1];
	Q = read(); init(1 , 1 , N);
	while(Q--){
		int l1 = read() , l2 = read() , len = read();
		data p = (data){l1 - 1 , l1 - 1 , 1 , pii(0 , 0)} + qry(1 , 1 , N , l1 , l1 + len - 1) ,
															  q = (data){l2 - 1 , l2 - 1 , 1 , pii(0 , 0)} + qry(1 , 1 , N , l2 , l2 + len - 1);
		puts(p.len == q.len && p.data == q.data ? "YES" : "NO");
	}
	return 0;
}