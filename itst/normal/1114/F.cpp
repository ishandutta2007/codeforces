#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 4e5 + 10 , MOD = 1e9 + 7;
int prime[310] , inv[310] , cnt , N;
bool nprime[310];
short mark[64][MAXN << 2];

struct node{
	int times , mark;
	node(){
		times = mark = 1;
	}
}Tree[MAXN << 2];

inline long long poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)

inline void pushdown(int x , int l , int r){
	if(Tree[x].mark != 1){
		Tree[lch].mark = (Tree[lch].mark * 1ll * Tree[x].mark) % MOD;
		Tree[rch].mark = (Tree[rch].mark * 1ll * Tree[x].mark) % MOD;
		Tree[lch].times = (Tree[lch].times * poww(Tree[x].mark , mid - l + 1)) % MOD;
		Tree[rch].times = (Tree[rch].times * poww(Tree[x].mark , r - mid)) % MOD;
		Tree[x].mark = 1;
	}
} 

inline void pushup(int x){
	Tree[x].times = 1ll * Tree[lch].times * Tree[rch].times % MOD;
}

void modify(int x , int l , int r , int L , int R , long long mrk){
	if(l >= L && r <= R){
		long long t = poww(mrk , r - l + 1);
		Tree[x].mark = (Tree[x].mark * mrk) % MOD;
		Tree[x].times = (Tree[x].times * t) % MOD;
		return;
	}
	pushdown(x , l , r);
	if(mid >= L)
		modify(lch , l , mid , L , R , mrk);
	if(mid < R)
		modify(rch , mid + 1 , r , L , R , mrk);
	pushup(x);
}

long long query(int x , int l , int r , int L , int R){
	if(l >= L && r <= R)
		return Tree[x].times;
	pushdown(x , l , r);
	long long times = 1;
	if(mid >= L)
		(times *= query(lch , l , mid , L , R)) %= MOD;
	if(mid < R)
		(times *= query(rch , mid + 1 , r , L , R)) %= MOD;
	return times;
}

void Mark(int ind , int x , int l , int r , int L , int R){
	if(mark[ind][x] == 2)
		return;
	mark[ind][x] = 1;
	if(l >= L && r <= R){
		mark[ind][x] = 2;
		return;
	}
	if(mid >= L)
		Mark(ind , lch , l , mid , L , R);
	if(mid < R)
		Mark(ind , rch , mid + 1 , r , L , R);
}

bool Query(int ind , int x , int l , int r , int L , int R){
	if(mark[ind][x] == 2)
		return 1;
	if(l >= L && r <= R)
		return mark[ind][x];
	if(mid >= L)
		if(Query(ind , lch , l , mid , L , R))
			return 1;
	if(mid < R)
		if(Query(ind , rch , mid + 1 , r , L , R))
			return 1;
	return 0;
}

void work(int x , int l , int r){
	if(x == 1)
		return;
	modify(1 , 1 , N , l , r , x);
	for(int i = 1 ; x != 1 ; ++i){
		int cnt = 0;
		while(x % prime[i] == 0){
			x /= prime[i];
			++cnt;
		}
		if(cnt)
			Mark(i , 1 , 1 , N , l , r);
	}
}

void que(int l , int r){
	long long times = query(1 , 1 , N , l , r);
	for(int i = 1 ; i <= cnt ; ++i)
		if(Query(i , 1 , 1 , N , l , r))
			times = times * inv[i] % MOD;
	cout << times << '\n';
}

inline char getc(){
	char c = getchar();
	while(!isupper(c))
		c = getchar();
	return c;
}

signed main(){
	for(int i = 2 ; i <= 300 ; ++i)
		if(!nprime[i]){
			prime[++cnt] = i;
			for(int j = i ; j * i <= 300 ; ++j)
				nprime[j * i] = 1;
		}
	for(int i = 1 ; i <= cnt ; ++i)
		inv[i] = poww(prime[i] , MOD - 2) * (prime[i] - 1) % MOD;
	N = read();
	int Q = read();
	for(int i = 1 ; i <= N ; ++i)
		work(read() , i , i);
	while(Q--)
		if(getc() == 'T'){
			int l = read() , r = read(); 
			que(l , r);
		}
		else{
			int l = read() , r = read() , x = read();
			work(x , l , r); 
		}
	return 0;
}