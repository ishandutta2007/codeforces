#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define id(i , j) ((i - 1) * M + j)
#define PII pair < int , int >
const int _ = 2e5 + 3 , dir[4][2] = {0,1,0,-1,1,0,-1,0};
int N , M , L = 1 , R , arr[_]; long long cnt; PII to[_];

namespace segt{
	int mn[_ << 2] , cnt[_ << 2] , mrk[_ << 2];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

	void init(int x , int l , int r){mn[x] = 1e9; cnt[x] = r - l + 1; if(l != r){init(lch , l , mid); init(rch , mid + 1 , r);}}
	void mark(int x , int val){mrk[x] += val; mn[x] += val;}
	void down(int x){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}
	void up(int x){mn[x] = min(mn[lch] , mn[rch]); cnt[x] = (mn[x] == mn[lch]) * cnt[lch] + (mn[x] == mn[rch]) * cnt[rch];}
	
	void modify(int x , int l , int r , int L , int R , int val){
		if(l >= L && r <= R) return mark(x , val);
		down(x);
		if(mid >= L) modify(lch , l , mid , L , R , val);
		if(mid < R) modify(rch , mid + 1 , r , L , R , val);
		up(x);
	}
}

namespace LCT{
	int fa[_] , ch[_][2]; bool rmrk[_];
	
	bool nroot(int x){return ch[fa[x]][0] == x || ch[fa[x]][1] == x;}
	bool son(int x){return ch[fa[x]][1] == x;}
	void mark(int x){rmrk[x] ^= 1; swap(ch[x][0] , ch[x][1]);}
	void down(int x){if(rmrk[x]){mark(ch[x][0]); mark(ch[x][1]); rmrk[x] = 0;}}
	void dall(int x){if(nroot(x)) dall(fa[x]); down(x);}

	void rot(int x){
		bool f = son(x); int y = fa[x] , z = fa[y] , w = ch[x][f ^ 1];
		fa[x] = z; if(nroot(y)) ch[z][son(y)] = x;
		fa[y] = x; ch[x][f ^ 1] = y;
		ch[y][f] = w; if(w) fa[w] = y;
	}

	void splay(int x){dall(x); while(nroot(x)){if(nroot(fa[x])) rot(son(fa[x]) == son(x) ? fa[x] : x); rot(x);}}
	void access(int x){for(int y = 0 ; x ; y = x , x = fa[x]){splay(x); ch[x][1] = y;}}
	int fdrt(int x){access(x); splay(x); while(ch[x][0]) down(x = ch[x][0]); splay(x); return x;}
	void mkrt(int x){access(x); splay(x); mark(x);}
	void split(int x , int y){mkrt(x); access(y); splay(y);}
	void link(int x , int y){mkrt(x); fa[x] = y;}
	void cut(int x , int y){split(x , y); ch[y][0] = fa[x] = 0;}
}

void cut(){
	PII pos = to[L]; segt::modify(1 , 1 , N * M , L , L , 1e9);
	for(int i = 0 ; i < 4 ; ++i){
		int x = pos.first + dir[i][0] , y = pos.second + dir[i][1];
		if(x > 0 && x <= N && y > 0 && y <= M && LCT::fdrt(arr[id(x , y)]) == LCT::fdrt(L))
			LCT::cut(arr[id(x , y)] , L);
	}
	++L;
}

void link(){
	PII pos = to[R];
	for(int i = 0 ; i < 4 ; ++i){
		int x = pos.first + dir[i][0] , y = pos.second + dir[i][1];
		if(x > 0 && x <= N && y > 0 && y <= M){
			int t = arr[id(x , y)];
			while(t >= L && LCT::fdrt(t) == LCT::fdrt(R)) cut();
			if(t >= L && t <= R) LCT::link(t , R);
		}
	}
	for(int i = 0 ; i < 4 ; ++i){
		int x = pos.first + dir[i][0] , y = pos.second + dir[i][1];
		if(x > 0 && x <= N && y > 0 && y <= M && arr[id(x , y)] >= L && arr[id(x , y)] <= R)
			segt::modify(1 , 1 , N * M , 1 , arr[id(x , y)] , -1);
	}
}

int main(){
	N = read(); M = read(); segt::init(1 , 1 , N * M);
	for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= M ; ++j) to[arr[id(i , j)] = read()] = PII(i , j);
	while(++R <= N * M){
		segt::modify(1 , 1 , N * M , R , R , -1e9);
		segt::modify(1 , 1 , N * M , 1 , R , 1); link();
		cnt += (segt::mn[1] == 1) * segt::cnt[1];
	}
	cout << cnt; return 0;
}