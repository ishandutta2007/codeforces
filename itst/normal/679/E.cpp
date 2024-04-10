#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
#define ll long long
const int _ = 1e5 + 7; int N , Q; ll mn[_ << 2] , tar[_ << 2] , add[_ << 2] , fil[_ << 2];

void build(int x , int l , int r){
	if(l == r){mn[x] = read(); tar[x] = 1; while(tar[x] < mn[x]) tar[x] *= 42; mn[x] = tar[x] - mn[x]; return;}
	build(lch , l , mid); build(rch , mid + 1 , r); mn[x] = min(mn[lch] , mn[rch]);
}
void mark(int x , ll F , ll A){
	if(F){mn[x] = F + A; tar[x] = 1; fil[x] = F; add[x] = A; while(tar[x] < mn[x]){tar[x] *= 42;} mn[x] = tar[x] - mn[x];}
	else{add[x] += A; if((mn[x] -= A) < 0 && tar[x]) while(mn[x] < 0){mn[x] += 41 * tar[x]; tar[x] *= 42;}}
}
void down(int x){if(add[x] || fil[x]){mark(lch , fil[x] , add[x]); mark(rch , fil[x] , add[x]); tar[x] = add[x] = fil[x] = 0;}}

ll qry(int x , int l , int r , int t){if(l == r){return tar[x] - mn[x];} down(x); return mid >= t ? qry(lch , l , mid , t) : qry(rch , mid + 1 , r , t);}
void mdf(int x , int l , int r , int L , int R , ll F , ll A){
	if(l >= L && r <= R) return mark(x , F , A);
	down(x); if(mid >= L) mdf(lch , l , mid , L , R , F , A);
	if(mid < R) mdf(rch , mid + 1 , r , L , R , F , A);
	mn[x] = min(mn[lch] , mn[rch]);
}

void mdfmin(int x , int l , int r){
	down(x); if(mn[lch] < 0){mdfmin(lch , l , mid);}
	if(mn[rch] < 0){mdfmin(rch , mid + 1 , r);} mn[x] = min(mn[lch] , mn[rch]);
}

int main(){
	N = read(); Q = read(); build(1 , 1 , N);
	while(Q--){
		int op , l , r , v; op = read();
		if(op == 1) printf("%lld\n" , qry(1 , 1 , N , read()));
		else if(op == 2){l = read(); r = read(); mdf(1 , 1 , N , l , r , read() , 0);}
		else{l = read(); r = read(); v = read(); do{mdf(1 , 1 , N , l , r , 0 , v); if(mn[1] < 0) mdfmin(1 , 1 , N);}while(!mn[1]);}
	}
	return 0;
}