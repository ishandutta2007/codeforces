#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 2e5 + 3;
struct data{
	int val[32];
}Tree[MAXN << 2] , tmp;
int N , K , MAX , arr[5];

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
#define max(a , b) (a > b ? a : b)
inline data merge(const data &a , const data &b){
	for(int i = 0 ; i <= MAX ; ++i)
		tmp.val[i] = max(a.val[i] , b.val[i]);
	return tmp;
}

inline int calc(int x){
	int sum = 0;
	for(int i = 0 ; i < K ; ++i)
		sum += x & (1 << i) ? arr[i] : -arr[i];
	return sum;
}

data get(){
	data m;
	for(int i = 0 ; i < K ; ++i) arr[i] = read();
	for(int i = 0 ; i <= MAX ; ++i)
		m.val[i] = calc(i);
	return m;
}

void init(int x , int l , int r){
	if(l == r) Tree[x] = get();
	else{
		init(lch , l , mid);
		init(rch , mid + 1 , r);
		Tree[x] = merge(Tree[lch] , Tree[rch]);
	}
}

void modify(int x , int l , int r , int tar){
	if(l == r) Tree[x] = get();
	else{
		if(mid >= tar) modify(lch , l , mid , tar);
		else modify(rch , mid + 1 , r , tar);
		Tree[x] = merge(Tree[lch] , Tree[rch]);
	}
}

data query(int x , int l , int r , int L , int R){
	if(l >= L && r <= R)
		return Tree[x];
	if(mid >= L && mid < R)
		return merge(query(lch , l , mid , L , R) , query(rch , mid + 1 , r , L , R));
	if(mid >= L) return query(lch , l , mid , L , R);
	return query(rch , mid + 1 , r , L , R);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	K = read();
	MAX = (1 << K) - 1;
	init(1 , 1 , N);
	for(int M = read() ; M ; --M)
		if(read() == 2){
			int l = read() , r = read() , ans = 0;
			tmp = query(1 , 1 , N , l , r);
			for(int i = 0 ; i <= MAX ; ++i)
				ans = max(ans , tmp.val[i] + tmp.val[MAX ^ i]);
			printf("%d\n" , ans);
		}
		else
			modify(1 , 1 , N , read());
	return 0;
}