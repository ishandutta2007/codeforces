#include<iostream>
#include<cstdio>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

#define PII pair < int , int >
#define st first
#define nd second
const int MAXN = 1e5 + 7 , MOD = 1e9 + 7;

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

struct Edge{int end , upEd , w , col;}Ed[MAXN << 1];
int head[MAXN] , N , nowSz , minSz , minInd , sum , ans , cnt , cntEd;
bool vis[MAXN];

struct BIT{
#define lowbit(x) ((x) & -(x))
	int BIT0[MAXN << 2] , BIT1[MAXN << 2];
	BIT(){fill(BIT0 , BIT0 + (MAXN << 2) , 1);}
	void add(int pos , int w , int tp){
		pos += 2 * N + 1;
		if(tp == -1) w = poww(w , MOD - 2);
		while(pos <= (N + 1) << 2){
			BIT0[pos] = 1ll * BIT0[pos] * w % MOD;
			BIT1[pos] += tp;
			pos += lowbit(pos);
		}
	}
	PII get(int pos){
		pos += 2 * N + 1;
		int tms = 1 , sum = 0;
		while(pos){
			tms = 1ll * tms * BIT0[pos] % MOD;
			sum += BIT1[pos];
			pos -= lowbit(pos);
		}
		return PII(tms , sum);
	}
}BIT1 , BIT2;

inline void addEd(int a , int b , int c , int d){
	Ed[++cntEd] = (Edge){b , head[a] , c , d};
	head[a] = cntEd;
}

void getSz(int x){
	vis[x] = 1; ++nowSz;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]) getSz(Ed[i].end);
	vis[x] = 0;
}

int getRt(int x){
	vis[x] = 1;
	int sz = 1 , maxSz = 0;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			int t = getRt(Ed[i].end);
			sz += t; maxSz = max(maxSz , t);
		}
	maxSz = max(maxSz , nowSz - sz);
	if(minSz > maxSz){
		minSz = maxSz;
		minInd = x;
	}
	vis[x] = 0;
	return sz;
}

void addNd(int x , int w , int colR , int colB , int tp){
	sum = 1ll * sum * w % MOD; ++cnt;
	BIT1.add(2 * colR - colB , w , tp);
	BIT2.add(2 * colB - colR , w , tp);
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end])
			addNd(Ed[i].end , 1ll * w * Ed[i].w % MOD , colR + Ed[i].col , colB + !Ed[i].col , tp);
	vis[x] = 0;
}

void qryNd(int x , int w , int colR , int colB){
	if(2 * colB >= colR && 2 * colR >= colB)
		ans = 1ll * ans * w % MOD;
	ans = 1ll * ans * sum % MOD * poww(w , cnt) % MOD;
	PII p = BIT1.get(colB - 2 * colR - 1) , q = BIT2.get(colR - 2 * colB - 1);
	ans = 1ll * ans * poww(1ll * p.st * q.st % MOD * poww(w , p.nd + q.nd) % MOD , MOD - 2) % MOD;
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end])
			qryNd(Ed[i].end , 1ll * w * Ed[i].w % MOD , colR + Ed[i].col , colB + !Ed[i].col);
	vis[x] = 0;
}

void solve(int x){
	nowSz = cnt = 0; sum = 1; minSz = 1e9;
	getSz(x); getRt(x); x = minInd;
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			qryNd(Ed[i].end , Ed[i].w , Ed[i].col , !Ed[i].col);
			addNd(Ed[i].end , Ed[i].w , Ed[i].col , !Ed[i].col , 1);
		}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end])
			addNd(Ed[i].end , Ed[i].w , Ed[i].col , !Ed[i].col , -1);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end])
			solve(Ed[i].end);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read() , w = read() , col = read();
		addEd(a , b , w , col); addEd(b , a , w , col);
	}
	ans = 1;
	solve(1);
	cout << ans;
	return 0;
}