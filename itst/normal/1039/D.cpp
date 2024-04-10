#include<bits/stdc++.h>
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
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 10;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , cur[MAXN] , top[MAXN] , fa[MAXN] , N , T , cntEd , ans , ts;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void input(){
	N = read();
	T = sqrt(N * log2(N));
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
}

void init(int x , int p){
	fa[x] = p;
	top[++ts] = x;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			init(Ed[i].end , x);
}

void solve(int q){
	ans = 0;
	fill(cur + 1 , cur + N + 1 , 1);
	for(int i = N ; i > 1 ; --i){
		int x = top[i];
		if(cur[fa[x]] != -1 && cur[x] != -1){
			if(cur[fa[x]] + cur[x] >= q){
				cur[fa[x]] = -1;
				++ans;
			}
			else
				cur[fa[x]] = max(cur[fa[x]] , cur[x] + 1);
		}
	}
}

void work(){
	printf("%d\n" , N);
	for(int i = 2 ; i <= T ; ++i){
		solve(i);
		printf("%d\n" , ans);
	}
	for(int j = T + 1 ; j <= N ; ){
		solve(j);
		int cur = ans , L = j , R = N;
		while(L < R){
			int mid = (L + R + 1) >> 1;
			solve(mid);
			if(ans == cur)
				L = mid;
			else
				R = mid - 1;
		}
		while(j <= L){
			++j;
			printf("%d\n" , cur);
		}
	}
}

int main(){
	input();
	init(1 , 0);
	work();
	return 0;
}