#pragma GCC O(2)
#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar(); 
	}
	return a;
}

int output[12];
inline void print(int a){
	int dirN = 0;
	while(a){
		output[dirN++] = a % 10;
		a /= 10;
	}
	while(dirN)
		putchar(output[--dirN] + '0');
	putchar('\n');
} 

struct Change{
	int col , dir , time , befCol;
}now[MAXN];
struct Query{
	int l , r , time , ind;
}to[MAXN];
int l[10001] , r[10001] , belong[MAXN] , ans[MAXN] , mex[MAXN] , num[MAXN << 1] , ori[MAXN] , nowCol[MAXN];
int N , nowAns = 1 , cntLSH , cntQue , cntCh;
map < int , int > forLSH;

inline bool cmp(Query a , Query b){
	if(belong[a.l] == belong[b.l])
		if(belong[a.r] == belong[b.r])
			return a.time < b.time;
		else
			return (belong[a.r] > belong[b.r]) ^ (belong[a.l] & 1);
	return a.l < b.l; 
}

inline int getLSH(int a){
	if(!forLSH.count(a)){
		forLSH.insert(make_pair(a , ++cntLSH));
		return cntLSH;
	}
	else
		return forLSH.find(a)->second;
}

inline void fk(){
	register int numT = pow(N , 1.0 / 3) , T = N / numT;
	for(register int i = 1 ; i <= numT ; i++){
		l[i] = r[i - 1] + 1;
		r[i] = i * T;
		for(int j = l[i] ; j <= r[i] ; j++)
			belong[j] = i;
	}
	if(r[numT] < N){
		r[++numT] = N;
		l[numT] = r[numT] - 1;
		for(int i = l[numT] ; i <= r[numT] ; i++)
			belong[i] = numT;
	}
}

inline void del(int dir){
	if(dir <= 0)
		return;
	if(!--mex[dir] && dir < nowAns)
		nowAns = dir;
}

inline void add(int dir){
	if(dir <= 0)
		return;
	++mex[dir];
}

int main(){
	N = read();
	register int Q = read() , l = 1 , r = 0 , dirCh = 0;
	for(register int i = 1 ; i <= N ; i++)
		ori[i] = nowCol[i] = getLSH(read());
	for(register int i = 1 ; i <= Q ; i++)
		if(read() == 1){
			to[++cntQue].l = read();
			to[to[cntQue].ind = cntQue].r = read();
			to[cntQue].time = i;
		}
		else{
			now[cntCh].befCol = nowCol[now[++cntCh].dir = read()];
			nowCol[now[cntCh].dir] = now[cntCh].col = getLSH(read());
			now[cntCh].time = i;
		}
	memcpy(nowCol , ori , sizeof(ori));
	fk();
	sort(to + 1 , to + cntQue + 1 , cmp);
	for(register int i = 1 ; i <= cntQue ; i++){
		while(r < to[i].r){
			del(num[nowCol[++r]]);
			num[nowCol[r]]++;
			add(num[nowCol[r]]);
		}
		while(r > to[i].r){
			del(num[nowCol[r]]);
			num[nowCol[r]]--;
			add(num[nowCol[r--]]);
		}
		while(l < to[i].l){
			del(num[nowCol[l]]);
			num[nowCol[l]]--;
			add(num[nowCol[l++]]);
		}
		while(l > to[i].l){
			del(num[nowCol[--l]]);
			num[nowCol[l]]++;
			add(num[nowCol[l]]);
		}
		while(dirCh && now[dirCh].time > to[i].time){
			if(to[i].l <= now[dirCh].dir && to[i].r >= now[dirCh].dir){
				del(num[nowCol[now[dirCh].dir]]);
				num[nowCol[now[dirCh].dir]]--;
				add(num[nowCol[now[dirCh].dir]]);
				nowCol[now[dirCh].dir] = now[dirCh].befCol;
				del(num[nowCol[now[dirCh].dir]]);
				num[nowCol[now[dirCh].dir]]++;
				add(num[nowCol[now[dirCh].dir]]);
			}
			else
				 nowCol[now[dirCh].dir] = now[dirCh].befCol;
			dirCh--;
		}
		while(dirCh != cntCh && now[dirCh + 1].time < to[i].time){
			dirCh++;
			if(to[i].l <= now[dirCh].dir && to[i].r >= now[dirCh].dir){
				del(num[nowCol[now[dirCh].dir]]);
				num[nowCol[now[dirCh].dir]]--;
				add(num[nowCol[now[dirCh].dir]]);
				nowCol[now[dirCh].dir] = now[dirCh].col;
				del(num[nowCol[now[dirCh].dir]]);
				num[nowCol[now[dirCh].dir]]++;
				add(num[nowCol[now[dirCh].dir]]);
			}
			else
				 nowCol[now[dirCh].dir] = now[dirCh].col;
		}
		while(mex[nowAns])
		    ++nowAns;
		ans[to[i].ind] = nowAns;
	}
	for(register int i = 1 ; i <= cntQue ; i++)
		print(ans[i]);
	return 0;
}