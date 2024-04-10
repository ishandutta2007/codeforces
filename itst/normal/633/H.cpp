#include<bits/stdc++.h>
//This code is written by Itst
#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
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

const int MAXN = 3e4 + 7;
int step = 0 , N , M , Q , T , cnt , num[MAXN] , lsh[MAXN] , times[MAXN] , ans[MAXN];
struct query{
	int ind , l , r;
	bool operator <(const query a)const{
		return l / T == a.l / T ? ((l / T) & 1 ? r > a.r : r < a.r) : l < a.l;
	}
}now[MAXN];
struct matrix{
	int a[2][2];
	int* operator [](int x){return a[x];}
	matrix(bool f = 1){if(f) memset(a , 0 , sizeof(a));}
	matrix operator *(matrix b){
		matrix c;
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				for(int k = 0 ; k < 2 ; ++k)
					c[i][j] += a[i][k] * b[k][j];
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				c[i][j] %= M;
		return c;
	}
	matrix operator *(int b){
		matrix c(0);
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				c[i][j] = a[i][j] * b;
		return c;
	}
	matrix operator +(matrix b){
		matrix c(0);
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				c[i][j] = (a[i][j] + b[i][j]) % M;
		return c;
	}
	bool operator ==(matrix b){
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				if(a[i][j] != b[i][j])
					return 0;
		return 1;
	}
	bool operator !=(matrix b){
		return !(*this == b);
	}
}F , E , G , a , b;
struct node{
	matrix ans , mark;
	int times;
}Tree[MAXN << 2];

inline void mark(int x , const matrix mark){
	Tree[x].mark = Tree[x].mark * mark;
	Tree[x].ans = Tree[x].ans * mark;
}

inline void pushdown(int x){
	if(Tree[x].mark != E){
		mark(lch , Tree[x].mark);
		mark(rch , Tree[x].mark);
		Tree[x].mark = E;
	}
}

inline void pushup(int x){
	a = Tree[lch].ans;
	b = Tree[rch].ans;
	if(Tree[lch].times != 1)
		a = a * Tree[lch].times;
	if(Tree[rch].times != 1)
		b = b * Tree[rch].times;
	Tree[x].ans = a + b;
}

void insert(int x , int l , int r , int tar){
	if(l == r){
		Tree[x].times = lsh[tar];
		return; 
	}
	pushdown(x);
	if(mid >= tar){
		insert(lch , l , mid , tar);
		mark(rch , F);
	}
	else
		insert(rch , mid + 1 , r , tar);
	pushup(x);
}

void erase(int x , int l , int r , int tar){
	if(l == r){
		Tree[x].times = 0;
		return; 
	}
	pushdown(x);
	if(mid >= tar){
		erase(lch , l , mid , tar);
		mark(rch , G);
	}
	else
		erase(rch , mid + 1 , r , tar);
	pushup(x);
}

void init(int x , int l , int r){
	Tree[x].times = l != r;
	Tree[x].mark = E;
	if(l != r){
		init(lch , l , mid);
		init(rch , mid + 1 , r);
	}
	else
		Tree[x].ans = F;
}

inline void add(int a){
	if(!times[a]++)
		insert(1 , 1 , cnt , a);
	++step;
}

inline void del(int a){
	if(!--times[a])
		erase(1 , 1 , cnt , a);
	++step;
}

int main(){
	N = read();
	M = read();
	T = sqrt(N);
	E[0][0] = E[1][1] = F[0][1] = F[1][0] = F[1][1] = G[1][0] = G[0][1] = 1;
	G[0][0] = M - 1;
	for(int i = 1 ; i <= N ; ++i)
		num[i] = lsh[i] = read();
	sort(lsh + 1 , lsh + N + 1);
	cnt = unique(lsh + 1 , lsh + N + 1) - lsh - 1;
	for(int i = 1 ; i <= N ; ++i)
		num[i] = lower_bound(lsh + 1 , lsh + cnt + 1 , num[i]) - lsh;
	for(int i = 1 ; i <= cnt ; ++i)
		lsh[i] %= M;
	Q = read();
	for(int i = 1 ; i <= Q ; ++i){
		now[i].ind = i;
		now[i].l = read();
		now[i].r = read();
	}
	sort(now + 1 , now + Q + 1);
	int L = 1 , R = 0;
	init(1 , 1 , cnt);
	for(int i = 1 ; i <= Q ; ++i){
		while(R < now[i].r)
			add(num[++R]);
		while(L > now[i].l)
			add(num[--L]);
		while(R > now[i].r)
			del(num[R--]);
		while(L < now[i].l)
			del(num[L++]);
		ans[now[i].ind] = Tree[1].ans[0][1] * Tree[1].times % M;
	}
	cerr << step << endl;
	for(int i = 1 ; i <= Q ; ++i)
		printf("%d\n" , ans[i]);
	return 0;
}