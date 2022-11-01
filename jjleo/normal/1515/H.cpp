#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct Node{
	int son[2], sum;
	int tag, And, Or;
}t[maxn * 50];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

int cnt = 1;

inline void up(int x, int bit){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
	t[x].And = (t[ls(x)].And & t[rs(x)].And) | ((1 << bit) * (!t[ls(x)].sum && t[rs(x)].sum));
	t[x].Or = t[ls(x)].Or | t[rs(x)].Or | ((1 << bit) * (t[rs(x)].sum != 0));
}

inline void Xor(int x, int y, int bit){
	//printf("%d %d--\n", y, bit);
	y &= (1 << (bit + 1)) - 1;
	if(y & (1 << bit)) swap(ls(x), rs(x));
	int And = t[x].And, Or = t[x].Or;
	t[x].And = And & ~y | ~Or & y;
	t[x].Or = ~(And & y | ~Or & ~y) & ((1 << (bit + 1)) - 1);
	t[x].tag ^= y;
}

inline void down(int x, int bit){
	if(!t[x].tag) return;
	if(ls(x)) Xor(ls(x), t[x].tag, bit - 1);
	if(rs(x)) Xor(rs(x), t[x].tag, bit - 1);
	t[x].tag = 0;
}

int merge(int x, int y, int bit){
	if(!x || !y) return x | y;
	if(bit == -1) t[x].sum = 1;
	else down(x, bit), down(y, bit), ls(x) = merge(ls(x), ls(y), bit - 1), rs(x) = merge(rs(x), rs(y), bit - 1), up(x, bit);
	return x;
}

void split(int &a, int &b, int bit, int ll, int rr, int sum){
	if(!a) return;
	if(ll <= sum && sum + (1 << (bit + 1)) - 1 <= rr){
		b = a, a = 0;
		return;
	}
	down(a, bit);
	b = ++cnt;
	int mid = sum + (1 << bit) - 1;
	if(mid >= ll) split(ls(a), ls(b), bit - 1, ll, rr, sum);
	if(mid < rr) split(rs(a), rs(b), bit - 1, ll, rr, sum + (1 << bit));
	//printf("%d %d--\n", bit, ls(b)); 
	up(a, bit), up(b, bit);
}

void Or(int x, int bit, int d){
	if(!x || bit == -1) return;
	d &= (1 << (bit + 1)) - 1;
	//printf("%d %d %d %d %d %d--\n", t[x].And, t[x].Or, t[x].sum, d & ~t[x].Or, d, bit);
	if((d & (t[x].And | ~t[x].Or)) == d){
		//printf("%d %d %d %d %d--\n", t[x].And, t[x].Or, t[x].sum, d & ~t[x].Or, bit);
		Xor(x, d & ~t[x].Or, bit);
		return;
	}
	down(x, bit);
	//printf("%d %d--\n", bit, t[x].sum);
	if(ls(x) && (d & (1 << bit))) rs(x) = merge(ls(x), rs(x), bit - 1), ls(x) = 0;
	Or(ls(x), bit - 1, d), Or(rs(x), bit - 1, d);
	up(x, bit);
	//printf("%d %d--\n", bit, t[x].sum);
}

void add(int x, int bit, int d){
	if(bit == -1){
		t[x].sum = 1;
		return;
	}
	int i = (d & (1 << bit)) != 0;
	add(t[x].son[i] ? t[x].son[i] : t[x].son[i] = ++cnt, bit - 1, d);
	up(x, bit);
}

const int Bit = 19;
int n, q, opt, x, y, rt = 1, Rt;

int main(){
	t[0].And = (1 << (Bit + 1)) - 1;
	scanf("%d%d", &n, &q);
	while(n--) scanf("%d", &x), add(rt, Bit, x);
	while(q--){
		scanf("%d%d%d", &opt, &x, &y);
		split(rt, Rt, Bit, x, y, 0);
		//printf("%d size:%d, %d size:%d--\n", rt, t[rt].sum, Rt, t[Rt].sum);
		switch(opt){
			case 1:
				scanf("%d", &x);
				Xor(Rt, (1 << (Bit + 1)) - 1, Bit);
				Or(Rt, Bit, x ^ ((1 << (Bit + 1)) - 1));
				Xor(Rt, (1 << (Bit + 1)) - 1, Bit);
				break;	
			case 2:
				scanf("%d", &x);
				Or(Rt, Bit, x);
				break;
			case 3:
				scanf("%d", &x);
				Xor(Rt, x, Bit);	
				break;
			case 4:
				printf("%d\n", t[Rt].sum);
				break;	
		}
		//printf("%d size:%d--\n", Rt, t[Rt].sum);
		rt = merge(rt, Rt, Bit);
		//printf("%d size:%d--\n", rt, t[rt].sum);
	}
}
/*
5 5
2 0 5 2 0
4 1 5
*/