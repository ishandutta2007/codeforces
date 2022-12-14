#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define int long long
int N , M , cnt , jump[200003][20];
struct segment{
	int l , r;
}now[200003] , lar[200003];
bool operator <(segment a , segment b){return a.l < b.l || a.l == b.l && a.r > b.r;}

namespace segTree{
	int mrk[3000003];
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

	int cmp(int a , int b){
		if(!a || !b) return a + b;
		return lar[a].r <= lar[b].r ? b : a;
	}
	
	void modify(int x , int l , int r , int L , int R , int num){
		if(l >= L && r <= R) return (void)(mrk[x] = cmp(mrk[x] , num));
		if(mid >= L) modify(lch , l , mid , L , R , num);
		if(mid < R) modify(rch , mid + 1 , r , L , R , num);
	}
	
	int query(int x , int l , int r , int tar){
		if(l == r) return mrk[x];
		if(mid >= tar) return cmp(query(lch , l , mid , tar) , mrk[x]);
		else return cmp(query(rch , mid + 1 , r , tar) , mrk[x]);
	}
}

signed main(){
	N = read(); M = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].l = read(); now[i].r = read();
	}
	sort(now + 1 , now + N + 1);
	int maxRht = -1;
	for(int i = 1 ; i <= N ; ++i)
		if(maxRht < now[i].r){
			lar[++cnt] = now[i]; maxRht = now[i].r;
		}
	for(int i = 1 ; i <= cnt ; ++i){
		segTree::modify(1 , 0 , 5e5 , lar[i].l , lar[i].r , i);
		int l = i , r = cnt;
		while(l < r){
			int Mid = ((l + r + 1) >> 1);
			lar[Mid].l <= lar[i].r ? l = Mid : r = Mid - 1;
		}
		if(l == i) jump[i][0] = 0;
		else jump[i][0] = l;
	}
	for(int j = cnt ; j ; --j)
		for(int k = 1 ; jump[j][k - 1] ; ++k)
			jump[j][k] = jump[jump[j][k - 1]][k - 1];
	while(M--){
		int l , r , stp = 1 , id; l = read(); r = read();
		id = segTree::query(1 , 0 , 5e5 , l);
		if(!id){puts("-1"); continue;}
		if(lar[id].r >= r){puts("1"); continue;}
		for(int i = 19 ; i >= 0 ; --i)
			if(jump[id][i] != 0 && lar[jump[id][i]].r < r){
				stp += 1 << i;
				id = jump[id][i];
			}
		if(jump[id][0] == 0) puts("-1");
		else printf("%I64d\n" , stp + 1);
	}
	return 0;
}